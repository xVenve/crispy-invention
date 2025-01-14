.text
inicializar: #$a0 -> A  $a1->M  $a2->N
	li $t3, 0
	ble $a1, $t3, error
	ble $a2, $t3, error
	li $v0, 0 
    mul $t4, $a1, $a2 #Numero de elementos matriz
	li $t5, 0 #Indice
	li $t6, 0 #Iterador de memoria
	move $t7, $a0
	add $t5, $t5, $t7
	bcl1:bgt $t6, $t4, inif #Recorrer la matriz por elemento
    sw $t3, ($t5) #Carga del valor 0
    #Incremento de iteradores
    addi $t5, $t5, 4 
	addi $t6, $t6, 1
    b bcl1
	inif: jr $ra
	error: li $v0, -1
	jr $ra





sumar: #$a0 -> A  $a1->B  $a2->C  $a3-> M   Pila (sp)  -> N
	li $t3, 0
	#Sacar el valor de pila ($t0)
	lw $t0, ($sp)
	mul $t7, $t0, $a3 #Numero total elementos
	ble  $a3, $t3, error_sum
    ble  $t0, $t3, error_sum
    li $v0, 0     
	li $t1,0 #Indice
 	#desplazamiento memoria

	move $t4, $a0  #Desplazamiento A
    move $t5, $a1  #Desplazamiento B
	move $t6, $a2  #Desplazamiento C
	loop_suma: bge $t1, $t7, fin_suma
    lw $t0, ($t5) #Cargar valor de matriz B
	lw $t2, ($t6) #Cargar valor de matriz C
	add $t3, $t2, $t0   #suma
	sw $t3, ($t4) #Carga de valor en A
	#Incremento de iteradores
	addi $t4,$t4,4
	addi $t5,$t5,4
	addi $t6,$t6,4
	addi $t1,$t1,1
	b loop_suma
	fin_suma: jr $ra
	error_sum: li $v0, -1
		jr $ra
        
        
        
        
        
extraerFila:   #A-> $a0, B-> $a1, M -> $a2, N -> $a3, j-> $sp
	#Copiar valor de pila 
	lw $t0, ($sp)
	#Control de errores
	blez $a2,error_copia
	blez $a3, error_copia
	bltz $t0, error_copia
	bgt $t0, $a2, error_copia

	li $v0, 0
	move $t1, $a0 #Copia direccion A
	move $t2, $a1 #Copia direccion B 
	li $t3, 0 #Indice 
	#Localización fila, dir+(fila*columnas*tamaño)
	mul $t4, $t0,$a3
	mul $t4, $t4, 4
	add $t2, $t2,$t4

loop_copia: bge $t3,$a3, fin_copia
	#Carga y copia
	lw $t5, ($t2)
	sw $t5,($t1)
	#Incremento de iteradores
	addi $t2, $t2, 4
	addi $t1, $t1, 4
	addi $t3, $t3, 1
	b loop_copia
error_copia: li $v0, -1
	jr $ra
fin_copia: jr $ra





masCeros: #$a0->A  $a1 -> B $a2-> M $a3->N
	li $t0,0
	blez $a2,error_ceros
	blez $a3, error_ceros
    #Creacion de espacio en pila 
	addu $sp, $sp, -16 #Salvar los datos previos de s0 y s1
	sw $s6, ($sp)
	sw $s3, 4($sp)
	sw $s4, 8($sp) #Dir de B y luego de A
    sw $s5, 12($sp)
	#MOVIMIENTO DE ARGUMENTOS
	move $s4, $a1
	move $a1, $a2 
    	move $a2, $a3
	move $a3, $t0
	move $s5, $ra
	
	jal calcular
	move $s6,$v0 #NÚMERO DE 0’S EN A
    #Reestructuracion de argumentos 
	move $t1, $s4
	move $s4, $a0 
	move $a0, $t1
    
	jal calcular
	move $s3, $v0 #NUMERO DE 0’S EN B
	#Comparacion de resultados
	bgt $s6,$s3, res_0
	bgt $s3,$s6, res_1
	li $v0,2
	b rest
	res_0: li $v0, 0
		b rest
	res_1: li $v0,1
    	b rest
	rest:
	#Restaurar pila tras guardar la dirección de las matrices
	move $ra, $s5
	lw $s6, ($sp)   	#Restaurar los datos previos de s0 y s1
	lw $s3, 4($sp)
    	lw $s4, 8($sp)
    	lw $s5, 12($sp)
	addu $sp, $sp, 16

	b fin_ceros	
	error_ceros: li $v0, -1
	jr $ra
	fin_ceros: jr $ra