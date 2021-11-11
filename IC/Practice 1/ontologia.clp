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

(defclass mensaje-aviso (is-a USER)
    (slot contenido
        (type STRING)
        )
    (slot ambiente
        (type INTEGER)
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

(definstances instancias-iniciales-rayuela
    (paciente of nino (nombre "Carlos")(personalidad timido))
    (NAO of robot (nombre "NAO") (saludo "¡Hola, soy el robot NAO! En esta sesión vamos hacer una serie de juegos para ver que tal se te dan. No te preocupes, ¡que seguro que se te da genial!. Los juegos serán la rayuela y los trileros, !a ver si me puedes ganar, buena suerte!") (despedida "Me ha gustado mucho jugar contigo, ¡nos vemos!"))
    (sesion of sesion (ambiente 1))
    (rayuela of rayuela)
    (piedra of item)

    (mensaje-aviso1 of mensaje-aviso (contenido "No te preocupes, ¡estos juegos son muy divertidos y lo estas haciendo genial,sigamos!")(ambiente 1))
   ; (mensaje-aviso1 of mensaje-aviso (contenido "prueba aviso ambiente 2")(ambiente 2))
    ;(mensaje-aviso1 of mensaje-aviso (contenido "Vamos a parar un poco y relajarnos, ¡que estos juegos cansan mucho, no pasa nada, seguimos en 5 minutos!")(ambiente 3))
    ;(mensaje-aviso1 of mensaje-aviso (contenido "¡Si no quieres jugar más terminamos el juego, la próxima vez jugaremos más!")(ambiente 4))

    (timido1 of personalidad (nombre "timido")(desviacion "Se ha puesto a llorar") (respuesta 3))
    (timido2 of personalidad (nombre "timido")(desviacion "Se niega a seguir jugando")(respuesta 2))

    (distraido1 of personalidad (nombre "distraido")(desviacion "Se levanta") (respuesta 3))
    (distraido2 of personalidad (nombre "distraido")(desviacion "Se olvida de jugar")(respuesta 2))
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
    (paso 0 "piedra")
    (paso 1 "cielo")
    (paso 2 "recoger piedra")
    (paso 3 "inicio")
    (max_ambiente 2)
)