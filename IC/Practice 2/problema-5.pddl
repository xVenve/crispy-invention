(define (problem ROBOT-TELEFONISTA-P5)
    (:domain ROBOT-TELEFONISTA)
    (:objects
        paciente1 paciente2 paciente3 - paciente
        familiar1 familiar2 familiar3 familiar4 - familiar
        enfermero celador - personal
        habitacion1 habitacion2 habitacion3 - habitacion
        enfermeria1 enfermeria2 - sala
        estacion - lugar
    )
    (:init
        (en-r estacion)
        (estacion-carga estacion)

        (en-p paciente1 habitacion1)
        (en-p paciente2 habitacion2)
        (en-p paciente3 habitacion3)

        (lugar-desinfeccion enfermeria1)
        (lugar-desinfeccion enfermeria2)
        (en-p enfermero enfermeria1)
        (abierta enfermeria1)
        (abierta enfermeria2)

        (bloqueo enfermeria1 habitacion1)
        (bloqueo habitacion1 enfermeria1)
        (bloqueo enfermeria1 habitacion2)
        (bloqueo habitacion2 enfermeria1)

        (cita familiar1 paciente1)
        (cita familiar2 paciente2)
        (cita familiar3 paciente1)
        (cita familiar4 paciente2)
        (cancelada familiar2 paciente2)
        (cancelada familiar3 paciente1)
        (= (hora-cita familiar1 paciente1) 9)
        (= (hora-cita familiar2 paciente2) 10)
        (= (hora-cita familiar3 paciente1) 10)
        (= (hora-cita familiar4 paciente2) 11)

        (= (hora-actual) 8)

    )
    (:goal
        (and
            (en-r estacion)
            (desinfectado)
            (not (cita familiar1 paciente1))
            (not (cita familiar2 paciente2))
            (not (cita familiar3 paciente1))
            (not (cita familiar4 paciente2)))
    )
)