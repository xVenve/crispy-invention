(defclass individuo (is-a USER)
    (slot nombre 
        (type STRING)
        (default ?NONE)
    )
    (slot personalidad
        (type SYMBOL)
        (allowed-values distraido timido robot)
    )
)

(defclass nino (is-a individuo)
    (slot personalidad
        (source composite)
        (allowed-values distraido timido)
    )
)

(defclass robot (is-a individuo)
    (slot personalidad
        (source composite)
        (allowed-values robot)
        (default robot)
    )
)

(defclass sesion (is-a USER)
    (slot tiempo
        (type INTEGER)
        (default 0)
    )
    (slot ambiente
        (type INTEGER)
        (default 0)
    )
)

(defclass juego (is-a USER)
    (slot reglas
        (type STRING)
    )
    (slot turno
        (type INTEGER)
        (default 0)
    )
)

(defclass puntuacion (is-a USER)
    (slot jugador
        (type INTEGER)
        (range 0 1)
    )
    (slot valor
        (type INTEGER)
        (range 0 100)
        (default 0)
    )
)

(defclass rayuela (is-a juego)
    (slot reglas
        (source composite)
        (default "!Vamos a jugar a la rayuela! En este juego lanzaremos una piedra dentro de las casillas que tenemos pintadas en el suelo, entonces saltando a la pata coja deberemos ir desde la casilla inicial hasta el cielo sin pisar la casilla en la que ha caido la piedra y volver. Quien logre hacer 3 vueltas gana. !Cuidado no te caigas, y mucha suerte!")
    )
    (slot paso
        (type INTEGER)
        (default 0)
    )
)

(defclass trileros (is-a juego)
    (slot reglas
        (source composite)
        (default "!Vamos a jugar a los trileros! Para este juego tendremos 3 vasos y 2 pelotas. Voy a esconder las pelotas dentro de los vasos y voy a empezar a moverlos. Cuando termine de moverlos me tienes que decir qué vaso tiene bola. Si fallas será mi turno, pero si aciertas, ganas un punto y tu turno sigue. El que llegue a 3 puntos gana. !Señala y levanta bien el vaso, seguro que me ganas, vamos a empezar!")
    )
)

(defclass item (is-a USER)
    (slot valor 
        (type INTEGER)
        (default -1)
    )
    (slot id
        (type INTEGER)
        (default -1)
    )
)



(definstances instancias-iniciales-rayuela
    (paciente of nino (nombre "Carlos")(personalidad timido))
    (NAO of robot (nombre "NAO"))
    (sesion of sesion)
    (rayuela of rayuela)
    (piedra of item)
)
(deffacts hechos-iniciales-rayuela
    (num 1)
    (num 2)
    (num 3)
    (num 4)
    (num 5)
    (num 6)
    (num 7)
    (num 8)
    (num 9)
    (num 10)
)