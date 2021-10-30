(defrule inicial
    (elemento ?x)
    (not (resultado ?))
    =>
    (assert (resultado 1)))

(defrule fin
    ?x <- (elemento 1)
    ?z <- (resultado ?y)
    =>
    (assert (elemento ?y))
    (retract ?x)
    (retract ?z)
    (halt))

(defrule paso
    ?w <- (elemento ?x)
    ?z <- (resultado ?y)
    (test (<> ?x 1))
    =>
    (assert (elemento (- ?x 1)))
    (assert (resultado (* ?y ?x)))
    (retract ?w)
    (retract ?z))

(deffacts hechos-iniciales
    (elemento 5))