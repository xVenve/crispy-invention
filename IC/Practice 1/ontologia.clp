(defclass individuo (is-a USER)
    (slot nombre 
        (type STRING)
        (default ?NONE)
    )
)

(defclass nino (is-a individuo)
    (slot personalidad
        (type SYMBOL)
    )
)
    
(defclass robot (is-a individuo)
    (slot saludo
        (type STRING)
    )
    (slot despedida
        (type STRING)
    )
)

(defclass sesion (is-a USER)
    (slot tiempo
        (type INTEGER)
        (default 0)
    )
    (slot ambiente
        (type INTEGER)
        (default 1)
    )
    (slot max_ambiente 
        (type INTEGER)    
    )
)

(defclass mensaje-aviso (is-a USER)
    (slot contenido
        (type STRING)
    )
    (slot ambiente
        (type INTEGER)
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
    (slot paso
        (type INTEGER)
        (default 0)
    )
)
(defclass mensaje-desviacion (is-a USER)
    (slot mensaje 
        (type STRING)
    )
)

(defclass rayuela (is-a juego)
    (slot reglas
        (source composite)
        (default "!Vamos a jugar a la rayuela! En este juego lanzaremos una piedra dentro de las casillas que tenemos pintadas en el suelo, entonces saltando a la pata coja deberemos ir desde la casilla inicial hasta el cielo sin pisar la casilla en la que ha caído la piedra y volver. Quien logre hacer 3 vueltas gana. !Cuidado no te caigas, y mucha suerte!")
    )
)

(defclass trileros (is-a juego)
    (slot reglas
        (source composite)
        (default "!Vamos a jugar a los trileros! Para este juego tendremos 3 vasos y 2 pelotas. Voy a esconder las pelotas dentro de los vasos y voy a empezar a moverlos. Cuando termine de moverlos me tienes que decir qué vaso tiene bola. Si fallas será mi turno, pero si aciertas, ganas un punto y tu turno sigue. El que llegue a 3 puntos gana. !Señala y levanta bien el vaso, seguro que me ganas, vamos a empezar!")
    )
)

(defclass item (is-a USER)
    (slot nombre
        (type STRING))
    (slot valor 
        (type INTEGER)
        (default -1)
    )
    (slot id
        (type SYMBOL)
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

(defclass personalidad (is-a USER)
    (slot nombre
        (type SYMBOL)
    )
    (slot desviacion
        (type STRING)
    )
    (slot respuesta
        (type INTEGER)
    )
)