(define (problem ROBOT-TELEFONISTA-P7)
    (:domain ROBOT-TELEFONISTA)
    (:objects
        paciente1 paciente2 paciente3 paciente4 paciente5 paciente6 - paciente
        familiar1 familiar2 familiar3 familiar4 familiar5 familiar6 familiar7 familiar8 familiar9 - familiar
        enfermero1 enfermero2 celador1 celador2 celador3 - personal
        habitacion1 habitacion2 habitacion3 habitacion4 habitacion5 habitacion6 - habitacion
        enfermeriaA enfermeriaB - sala
        estacion - lugar
    )
    (:init
        (en-r estacion)
        (estacion-carga estacion)

        (en-p paciente1 habitacion1)
        (en-p paciente2 habitacion2)
        (en-p paciente3 habitacion3)
        (en-p paciente4 habitacion4)
        (en-p paciente5 habitacion5)
        (en-p paciente6 habitacion6)

        (bloqueo habitacion1 habitacion2)
        (bloqueo habitacion2 habitacion1)
        (bloqueo enfermeriaA habitacion3)
        (bloqueo habitacion3 enfermeriaA)
        (bloqueo enfermeriaB habitacion4)
        (bloqueo habitacion4 enfermeriaB)

        (en-p enfermero1 enfermeriaA)
        (en-p enfermero2 enfermeriaB)

        (bloqueo estacion enfermeriaA)
        (bloqueo enfermeriaA estacion)

        (lugar-desinfeccion enfermeriaA)
        (lugar-desinfeccion enfermeriaB)
        (abierta enfermeriaA)
        (abierta enfermeriaB)

        (en-p celador1 habitacion1)
        (en-p celador1 habitacion2)
        (en-p celador2 habitacion3)
        (en-p celador2 habitacion4)
        (en-p celador3 habitacion5)
        (en-p celador3 habitacion6)

        (cita familiar1 paciente1)
        (= (hora-cita familiar1 paciente1) 10)

        (cita familiar2 paciente2)
        (= (hora-cita familiar2 paciente2) 12)

        (cita familiar7 paciente6)
        (= (hora-cita familiar7 paciente6) 13)
        (cancelada familiar7 paciente6)

        (cita familiar3 paciente3)
        (= (hora-cita familiar3 paciente3) 14)

        (cita familiar4 paciente4)
        (= (hora-cita familiar4 paciente4) 14)

        (cita familiar5 paciente1)
        (= (hora-cita familiar5 paciente1) 17)

        (cita familiar6 paciente5)
        (= (hora-cita familiar6 paciente5) 18)
        (cancelada familiar6 paciente5)

        (cita familiar8 paciente6)
        (= (hora-cita familiar8 paciente6) 18)

        (cita familiar9 paciente5)
        (= (hora-cita familiar9 paciente5) 21)

        (= (hora-actual) 8)

    )
    (:goal
        (and
            (en-r estacion)
            (desinfectado)
            (not (cita familiar1 paciente1))
            (not (cita familiar2 paciente2))
            (not (cita familiar7 paciente6))
            (not (cita familiar3 paciente3))
            (not (cita familiar4 paciente4))
            (not (cita familiar5 paciente1))
            (not (cita familiar6 paciente5))
            (not (cita familiar8 paciente6))
            (not (cita familiar9 paciente5))
        )
    )
)