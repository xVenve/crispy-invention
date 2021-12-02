(define (problem ROBOTCAFE-P1)
(:domain ROBOTCAFE)
    (:objects
        p1 p2 - persona 
        cafetera tetera barra - lugar
        cafe te - bebida)
    (:init 
        (en barra)
        (lugar-servicio barra)
        (comanda te p1)
        (comanda cafe p2)
        (produce cafetera cafe)
        (produce tetera te)
    )
    (:goal (and 
        (entregado p2) 
        (entregado p1)))
)