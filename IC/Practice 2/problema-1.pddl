(define (problem ROBOT-TELEFONISTA-P1)
    (:domain ROBOT-TELEFONISTA)
    (:objects
        paciente1 - paciente
        familiar1 familiar2 - familiar
        enfermero celador - personal
        habitacion1 - habitacion
        enfermeria - sala
        estacion - lugar
    )
    (:init
        (en-r estacion)
        (estacion-carga estacion)

        (en-p paciente1 habitacion1)

        (en-p enfermero enfermeria)
        (lugar-desinfeccion enfermeria)
        (abierta enfermeria)

        (en-p celador habitacion1)

        (cita familiar1 paciente1)
        (cita familiar2 paciente1)
        (= (hora-cita familiar1 paciente1) 9)
        (= (hora-cita familiar2 paciente1) 10)

        (= (hora-actual) 8)

    )
    (:goal
        (and
            (en-r estacion)
            (desinfectado)
            (not (cita familiar1 paciente1))
            (not (cita familiar2 paciente1)))
        )
)