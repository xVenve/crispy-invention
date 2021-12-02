(define (domain ROBOTCAFE)
(:requirements :strips :typing)
	(:types
		persona
        lugar
        bebida 
	)
	(:predicates
        (produce ?l - lugar ?b - bebida)
		(en ?l - lugar)
		(comanda ?b - bebida ?p - persona)
        (en-proceso ?p - persona) 
        (lleva ?b - bebida)
        (lugar-servicio ?l - lugar)
        (entregado ?p - persona)
    )
    (:action tomar-comanda
        :parameters (?p ?k - persona ?b ?v - bebida ?l - lugar) 
        :precondition (and 
            (comanda ?b ?p) 
            (en ?l)
            (lugar-servicio ?l)
            (not (en-proceso ?k)))
        :effect (and 
            (en-proceso ?p))
    )
    (:action hacer-bebida
        :parameters (?p - persona ?b - bebida ?l ?l2 - lugar)
        :precondition (and 
            (en-proceso ?p) 
            (comanda ?b ?p) 
            (produce ?l ?b)
            (en ?l))
        :effect (and 
            (lleva ?b))
    )
    (:action moverse
        :parameters (?l ?l2 - lugar)
        :precondition (and 
            (en ?l) 
            (not (en ?l2)))
        :effect (and 
            (en ?l2) 
            (not (en ?l)))
    )
    (:action entregar-comanda
        :parameters (?p - persona ?b ?v - bebida ?l ?z - lugar)
        :precondition (and 
            (en-proceso ?p) 
            (comanda ?b ?p)
            (en ?l) 
            (lugar-servicio ?l) 
            (lleva ?b))
        :effect (and 
            (not (en-proceso ?p)) 
            (not (comanda ?b ?p)) 
            (not (lleva ?b)) 
            (entregado ?p))
    )
)