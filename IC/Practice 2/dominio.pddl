(define (domain ROBOT-TELEFONISTA)
    (:requirements :strips :typing :negative-preconditions :fluents)
    (:types
        paciente familiar personal - persona
        habitacion sala - lugar
    )
    (:predicates
        (en-p ?p - persona ?h - lugar) ; Una habitacion tiene una persona
        (en-r ?l - lugar) ; El robot esta en un lugar
        (desinfectado) ; El robot esta desinfectado
        (lugar-desinfeccion ?l - lugar) ; Lugar donde tiene lugar la desinfeccion
        (estacion-carga ?l - lugar) ; Lugar donde tiene lugar la carga
        (abierta ?h - lugar) ; Una habitacion esta abierta
        (saludado-avisado-llamada ?p - paciente) ; Un paciente ha sido saludado
        (cita ?f - familiar ?p - paciente) ; Un paciente tiene una cita con un familiar
        (necesita-desinfeccion) ; Robot en habitacion COVID necesita desinfeccion
        (cancelada ?f - familiar ?p - paciente) ; Se ha cancelado una cita
        (bloqueo ?l1 - lugar ?l2 - lugar) ; Camino bloqueado
    )
    (:functions
        (hora-actual) ; Hora actual
        (hora-cita ?f - familiar ?p - paciente) ; Un familiar tiene una cita de videollamada con un paciente en una hora determinada
    )
    (:action moverse
        :parameters (?l1 ?l2 - lugar)
        :precondition (and
            (en-r ?l1)
            (not (en-r ?l2))
            (not (estacion-carga ?l1))
            (abierta ?l2)
            (not (necesita-desinfeccion))
            (not (bloqueo ?l1 ?l2))
        )
        :effect (and
            (en-r ?l2)
            (not (en-r ?l1))
        )
    )
    (:action quitar-bloqueo
        :parameters (?l1 ?l2 - lugar ?p - personal)
        :precondition (and
            (en-r ?l1)
            (not (en-r ?l2))
            (bloqueo ?l1 ?l2)
            (en-p ?p ?l2)
        )
        :effect (and
            (not (bloqueo ?l1 ?l2))
        )
    )
    (:action moverse-a-preparar-llamada
        :parameters (?l - lugar ?l2 - sala ?f - familiar ?p - paciente)
        :precondition (and
            (en-r ?l)
            (estacion-carga ?l)
            (cita ?f ?p)
            (not (bloqueo ?l ?l2))
            (abierta ?l2)
            (= (hora-cita ?f ?p) (hora-actual))
        )
        :effect (and
            (not (en-r ?l))
            (en-r ?l2)
            (not (desinfectado))
        )
    )
    (:action pedir-desinfeccion
        :parameters (?l - lugar ?p - personal)
        :precondition (and
            (en-r ?l)
            (lugar-desinfeccion ?l)
            (en-p ?p ?l)
        )
        :effect (and
            (desinfectado)
        )
    )
    (:action pedir-abrir-habitacion
        :parameters (?l ?h - lugar ?p - personal ?f - familiar ?p2 - paciente)
        :precondition (and
            (desinfectado)
            (en-r ?l)
            (not (estacion-carga ?l))
            (en-p ?p ?h)
            (cita ?f ?p2)
            (not (abierta ?h))
            (= (hora-actual)(hora-cita ?f ?p2))
            (en-p ?p2 ?h)
        )
        :effect (and
            (abierta ?h)
        )
    )
    (:action saludar-avisar-llamada-paciente
        :parameters (?f - familiar ?p - paciente ?h - habitacion)
        :precondition (and
            (desinfectado)
            (cita ?f ?p)
            (= (hora-actual)(hora-cita ?f ?p))
            (en-p ?p ?h)
            (en-r ?h)
            (not (saludado-avisado-llamada ?p))
        )
        :effect (and
            (saludado-avisado-llamada ?p)
            (not (desinfectado))
            (necesita-desinfeccion)
        )
    )
    (:action cancelada-llamada
        :parameters (?f - familiar ?p - paciente)
        :precondition (and
            (cita ?f ?p)
            (cancelada ?f ?p)
        )
        :effect (and
            (not (cita ?f ?p))
        )
    )
    (:action trascurre-llamada
        :parameters (?f - familiar ?p - paciente ?h - habitacion)
        :precondition (and
            (cita ?f ?p)
            (= (hora-actual)(hora-cita ?f ?p))
            (en-p ?p ?h)
            (en-r ?h)
            (saludado-avisado-llamada ?p)
        )
        :effect (and
            (not (saludado-avisado-llamada ?p))
            (not (cita ?f ?p))
        )
    )
    (:action desinfeccion-post-llamada
        :parameters (?l - habitacion ?f - familiar ?p - paciente)
        :precondition (and
            (en-r ?l)
            (en-p ?p ?l)
            (not (cita ?f ?p))
            (= (hora-actual)(hora-cita ?f ?p))
            (necesita-desinfeccion)
        )
        :effect (and
            (desinfectado)
            (not (necesita-desinfeccion))
        )
    )
    (:action moverse-a-carga
        :parameters (?l ?l2 - lugar)
        :precondition (and
            (en-r ?l)
            (not (en-r ?l2))
            (desinfectado)
            (estacion-carga ?l2)
        )
        :effect (and
            (not (en-r ?l))
            (en-r ?l2)
        )
    )
    (:action pasar-tiempo
        :parameters (?l - lugar)
        :precondition (and
            (en-r ?l)
            (estacion-carga ?l)
        )
        :effect (and
            (increase (hora-actual) 1)
        )
    )
)