(defrule empezar-sesion
    ?n <- (object (is-a nino) (nombre ?a))
    ?r <- (object (is-a robot)(nombre ?b)(saludo ?sa))
    ?s <- (object (is-a sesion)(tiempo 0))
=>
    (set-strategy random)
    (dribble-on salida-prueba-X.txt)
    (printout t ?sa crlf)
    (modify-instance ?s (tiempo 1))
    (assert (id-nombre 0 ?b))
    (assert (id-nombre 1 ?a))
)

(defrule inicializar-juego 
    ?s <- (object (is-a sesion)(tiempo 1))   
    (object (is-a juego)(reglas ?r))
=>
    (printout t ?r crlf)
    (assert (fin-inicio))
    (modify-instance ?s (tiempo 2))
    (make-instance of puntuacion (jugador 0))
    (make-instance of puntuacion (jugador 1))
)

(defrule empezar-turno
    (not (reinicio))  
    ?s <- (object (is-a sesion)(tiempo 2)(ambiente ?a)(max_ambiente ?ma))
    ?i <- (fin-inicio)
    ?t <- (object (is-a item) (valor -1) (nombre ?id))
    (num ?nm)
    (not (object (is-a item) (valor ?nm))) 
    (test (< ?a ?ma))
=> 
    (modify-instance ?t (valor ?nm))
    (printout t "He asignado al item " ?id " el valor " ?nm crlf)
)

(defrule llegar
    (not (reinicio))
    (not (checkpoint))
    (fin-inicio)
    ?s <- (object (is-a sesion)(tiempo 2))
    (not (object (is-a item) (valor -1)))
    (not (object (is-a puntuacion) (valor 3)))
    ?j <- (object (is-a rayuela)(paso ?g)(turno ?k))
    (test (< ?g 4))
    (num ?nm)
    (id-nombre ?k ?n)
    (paso ?g ?np)
=>
    (modify-instance ?j (paso (+ 1 ?g)))
    (printout t "El jugador " ?n " ha llegado a la parte " ?np " sin caerse " crlf)
)

(defrule fallo-juego
    (not (reinicio))
    (not (checkpoint))
    ?it<- (fin-inicio)
    ?s <- (object (is-a sesion)(tiempo 2))
    (not (object (is-a item) (valor -1)))
    (not (object (is-a puntuacion) (valor 3)))
    ?j <- (object (is-a juego)(paso ?g)(turno ?k))
    (object (is-a mensaje-desviacion)(mensaje ?m))
    (test (!= ?g 4))
    (id-nombre ?k ?n)
    (paso ?g ?np)
=>
    (assert (checkpoint 3))
    (modify-instance ?j (paso 0))
    (printout t "El jugador " ?n ?m ?np ", cambio de turno " crlf)
    (retract ?it)
)

(defrule fin-turno-rayuela
    (not (reinicio))
    (not (checkpoint))
    ?j <- (object (is-a juego) (paso 4))
    ?it <- (fin-inicio)
=>
    (assert (checkpoint 1))
    (modify-instance ?j (paso 0))
    (retract ?it)
)

(defrule desviar
    (not (reinicio))
    (not (checkpoint))
    ?it <- (fin-inicio)
    ?s <- (object (is-a sesion)(tiempo 2)(ambiente ?a))
    (not (object (is-a item) (valor -1)))
    (object (is-a nino)(personalidad ?pn))
    (object (is-a juego) (paso ?g)(turno 1))
    (object (is-a personalidad) (nombre ?pn) (desviacion ?d) (respuesta ?r))
    (object (is-a mensaje-aviso) (contenido ?ct) (ambiente ?a))  
=>
    (modify-instance ?s (ambiente (+ ?a ?r)))
    (printout t ?d crlf)
    (printout t ?ct crlf)
    (assert (reinicio))
    (retract ?it)
)

(defrule abandono
    ?s <- (object (is-a sesion)(tiempo 2)(ambiente ?a)(max_ambiente ?ma))
    (object (is-a individuo)(despedida ?d))
    (test (>= ?a ?ma))
=>    
    (printout t ?d crlf)
    (dribble-off)
    (halt)
)

(defrule elegir-vaso
    (not (reinicio))
    (not (checkpoint))
    ?it <- (fin-inicio)
    ?s <- (object (is-a sesion)(tiempo 2))
    (not (object (is-a item)(valor -1)))
    (not (object (is-a puntuacion)(valor 3)))
    (num ?nm)
    (object (is-a item)(id ?nm)(valor ?x))
    (pelota ?x ?np)
    (num ?nm2)
=>
    (printout t "Se ha elegido el vaso " ?nm  " con pelota " ?np crlf)
    (assert (checkpoint ?x))
    (retract ?it)
)

(defrule suma-punto
    (not (reinicio)) 
    ?c <- (checkpoint 1)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
    (id-nombre ?g ?n)
=>
    (modify-instance ?p (valor (+ ?v 1))) 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?n " ha ganado un punto" crlf)
)

(defrule resta-punto
    (not (reinicio))   
    ?c <- (checkpoint 2)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
    (id-nombre ?g ?n)
    (test (> ?v 0))
=>
    (modify-instance ?p (valor (- ?v 1))) 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?n " ha perdido un punto." crlf)
)

(defrule puntuacion-cero
   (not (reinicio))   
    ?c <- (checkpoint 2)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
    (id-nombre ?g ?n)
    (test (= ?v 0))
=> 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?n " ha perdido un punto, pero se queda en 0." crlf)
)

(defrule sin-punto
    (not (reinicio)) 
    ?c <- (checkpoint 3)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
    (id-nombre ?g ?n)
=> 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?n " no ha ganado un punto." crlf)
)

(defrule reiniciar-valores
    ?r <- (reinicio)
    ?i <- (object (is-a item)(valor ?x)(id ?id))
    (test (<> ?x -1))
=>
    (modify-instance ?i (valor -1)(id ?id))
)

(defrule reiniciar
    ?r <- (reinicio)
    (not (object (is-a item)(valor ?x&~-1)))
=>
    (retract ?r)
    (assert (fin-inicio))
)

(defrule ganar
    (object (is-a puntuacion)(valor 3)(jugador ?j))
    ?s <- (object (is-a sesion)(tiempo 2))
    (object (is-a individuo)(despedida ?d))
    (id-nombre ?j ?n)
=>
    (printout t "El jugador " ?n " ha ganado" crlf)
    (printout t ?d crlf)
    (dribble-off)
    (halt)
)