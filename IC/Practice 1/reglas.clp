(defrule empezar-sesion
    ?n <- (object (is-a nino) (nombre ?a))
    ?r <- (object (is-a robot)(nombre ?b))
    ?s <- (object (is-a sesion)(tiempo 0))
=>
    (printout t "¡Hola " ?a " ,soy el robot " ?b "! En esta sesión vamos hacer una serie de juegos para ver que tal se te dan. No te preocupes, ¡que seguro que se te da genial!. Los juegos serán la rayuela y los trileros, !a ver si me puedes ganar, buena suerte!" crlf)
    (modify-instance ?s (tiempo 1))
)

(defrule elegir-juego
    ?s <- (object (is-a sesion)(tiempo 1))
    ?j <- (object (is-a juego))
=>
    (modify-instance ?s (tiempo 2))
    (assert (inicializa-juego))
    (unmake-instance ?j)
)

(defrule inicializar-juego 
    ?i <- (inicializa-juego)
    (object (is-a juego)(reglas ?r))
=>
    (printout t ?r crlf)
    (retract ?i)
    (make-instance of puntuacion (jugador 0))
    (make-instance of puntuacion (jugador 1))
)

(defrule ganar-punto
    ?p <- (object (is-a puntuacion) (jugador ?g)(valor ?v))
    ?j <- (object (is-a juego) (turno ?g))
=>
    (modify-instance ?p (valor (+ ?v 1)))
    (modify-instance ?j (turno ( - 1 ?g)))
)

