(defrule empezar-sesion
    ?n <- (object (is-a nino) (nombre ?a))
    ?r <- (object (is-a robot)(nombre ?b))
    ?s <- (object (is-a sesion)(tiempo 0))
=>
    (printout t "¡Hola " ?a " ,soy el robot " ?b "! En esta sesión vamos hacer una serie de juegos para ver que tal se te dan. No te preocupes, ¡que seguro que se te da genial!. Los juegos serán la rayuela y los trileros, !a ver si me puedes ganar, buena suerte!" crlf)
    (modify-instance ?s (tiempo 1))
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
    ?s <- (object (is-a sesion)(tiempo 2))
    ?i <- (fin-inicio)
    ?t <- (object (is-a item) (valor -1) (id ?id))
    (num ?nm)
    (not (object (is-a item) (valor ?nm))) 
=> 
    (modify-instance ?t (valor ?nm))
    (printout t "He asignado al item " ?id " el valor " ?nm crlf)
)

; inicio-piedra-cielo-recoger-volver
(defrule llegar
    (not (reinicio))
    (not (checkpoint))
    (fin-inicio)
    ?s <- (object (is-a sesion)(tiempo 2))
    (not (object (is-a item) (valor -1)))
    (not (object (is-a puntuacion) (valor 3)))
    ?j <- (object (is-a juego) (paso ?g)(turno ?k))
    (test (!= ?g 4))
=>
    (modify-instance ?j (paso (+ 1 ?g)))
    (printout t "El jugador " ?k "ha llegado a la parte " ?g " sin caerse " crlf)


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




(defrule elegir-vaso
    (not (reinicio))
    (not (checkpoint))
    ?it <- (fin-inicio)
    ?s <- (object (is-a sesion)(tiempo 2))
    (not (object (is-a item) (valor -1)))
    (not (object (is-a puntuacion) (valor 3)))
    (num ?nm)
    (object (is-a item)(id ?nm)(valor ?x))
=>
    (printout t "Se ha elegido el vaso " ?nm  " con pelota " ?x crlf)
    (assert (checkpoint ?x))
    (retract ?it)

)

(defrule suma-punto
    (not (reinicio)) 
    ?c <- (checkpoint 1)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
=>
    (modify-instance ?p (valor (+ ?v 1))) 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?g " ha ganado un punto." crlf)
)

(defrule resta-punto
    (not (reinicio))   
    ?c <- (checkpoint 2)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
=>
    (modify-instance ?p (valor (- ?v 1))) 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?g " ha perdido un punto." crlf)
)

(defrule sin-punto
    (not (reinicio)) 
    ?c <- (checkpoint 3)
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
=> 
    (modify-instance ?j (turno (- 1 ?g)))
    (retract ?c)
    (assert (reinicio))
    (printout t "El jugador " ?g " no ha ganado un punto." crlf)

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
    (object (is-a puntuacion) (valor 3)(jugador ?j))
    ?s <- (object (is-a sesion)(tiempo 2))
=>
    (printout t "El jugador " ?j " ha ganado" crlf)
    (printout t "Me ha gustado mucho jugar contigo, ¡nos vemos!" crlf)
    (halt)
)

