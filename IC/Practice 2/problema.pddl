(define (problem ROBOT-TELEFONISTA-P1)
    (:domain ROBOT-TELEFONISTA)
    (:objects
        p1 p2 - paciente
        f1 f2 f3 f4 - familiar
        s1 s2 - personal
        h1 h2 - habitacion
        enfermeria r2 r3 - sala
        estacion - lugar
    )
    (:init
        (en-r estacion)
        (estacion-carga estacion)

        (en-p p1 h1)
        (en-p p2 h2)

        (en-p s1 enfermeria)
        (lugar-desinfeccion enfermeria)
        (abierta enfermeria)

        (en-p s2 h1)
        (en-p s2 h2)
        (bloqueo enfermeria h1)

        (cita f1 p1)
        (cita f2 p2)
        (cita f3 p1)
        (cita f4 p2)
        (cancelada f4 p2)
        (= (hora-cita f1 p1) 1)
        (= (hora-cita f2 p2) 2)
        (= (hora-cita f3 p1) 2)
        (= (hora-cita f4 p2) 3)

        (= (hora-actual) 0)

    )
    (:goal
        (and
            (en-r estacion)
            (desinfectado)
            (not (cita f1 p1))
            (not (cita f2 p2))
            (not (cita f3 p1))
            (not (cita f4 p2)))
    )
)