(defclass persona (is-a USER)
    (slot nombre
        (type STRING))
    (slot ciudad
        (type STRING)))

(defclass actividad (is-a USER)
    (slot nombre
        (type STRING))
    (slot ciudad
        (type STRING))
    (slot duracion
        (type INTEGER)))



(defrule iniciar-persona
    (declare (salience 30))
    (object (is-a persona) (nombre ?x) (ciudad ?y))
    =>
    (assert (suma ?x 0))
    (assert (contador ?x 0)))

(defrule asig-act-per
    (declare (salience 10))
    (object (is-a persona) (nombre ?x) (ciudad ?y))
    (object (is-a actividad) (nombre ?v) (ciudad ?y) (duracion ?w))
    =>
    (assert (act-per ?x ?v ?y ?w)))


 (defrule sumar-actividad
    (declare (salience 20))
    (object (is-a persona) (nombre ?x) (ciudad ?y))
    ?c <- (act-per ?x ? ?y ?w)
    ?a <- (suma ?x ?z)
    ?b <- (contador ?x ?v)
    =>
    (assert (suma ?x (+ ?z ?w)))
    (assert (contador ?x (+ ?v 1)))
    (retract ?a)
    (retract ?b)
    (retract ?c))   

(defrule imprimir-media
    (declare (salience 5))
    (object (is-a persona) (nombre ?x) (ciudad ?y))
    ?a <- (suma ?x ?z)
    ?b <- (contador ?x ?v)
    =>
    (printout t "La duración media de las actividades de " ?x " fue " (/ ?z ?v) crlf)
    (retract ?a)
    (retract ?b))

(defrule fin
    (declare (salience 1))
    =>
    (halt))



(definstances personas
    (of persona (nombre Juan) (ciudad Paris))
    (of persona (nombre Ana) (ciudad Edimburgo)))

(definstances actividades
    (of actividad (nombre Torre_Eiffel) (ciudad Paris) (duracion 2))
    (of actividad (nombre Castillo_de_Edimburgo) (ciudad Edimburgo) (duracion 5))
    (of actividad (nombre Louvre) (ciudad Paris) (duracion 6))
    (of actividad (nombre Montmartre) (ciudad Paris) (duracion 1))
    (of actividad (nombre Royal_Mile) (ciudad Edimburgo) (duracion 3)))