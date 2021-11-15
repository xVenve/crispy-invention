;; Rayuela con paciente Nervioso
(definstances instancias-iniciales-rayuela
    (paciente of nino (nombre "Estefania")(personalidad "nervioso"))
    (NAO of robot (nombre "NAO") (saludo "¡Hola, soy el robot NAO! En esta sesión vamos a hacer una serie de juegos para ver que tal se te dan. No te preocupes, ¡que seguro que se te da genial!. Los juegos serán la rayuela y los trileros, !a ver si me puedes ganar, buena suerte!") (despedida "Me ha gustado mucho jugar contigo, ¡nos vemos!"))

    (sesion of sesion (ambiente 1)(max_ambiente 5))
    (rayuela of rayuela)
    (mensaje-rayuela1 of mensaje-desviacion (mensaje " ha pisado la linea en el paso "))
    (mensaje-rayuela2 of mensaje-desviacion (mensaje " se ha caído en el paso "))
    (piedra of item (id -1)(nombre "piedra"))

    (mensaje-aviso1 of mensaje-aviso (contenido "No te preocupes, ¡estos juegos son muy divertidos y lo estás haciendo genial, sigamos!")(ambiente 1))
    (mensaje-aviso2 of mensaje-aviso (contenido "Venga, ¡intentémoslo una vez más!")(ambiente 2))
    (mensaje-aviso3 of mensaje-aviso (contenido "Vamos a parar un poco y relajarnos, ¡que estos juegos cansan mucho, no pasa nada, seguimos en 5 minutos!")(ambiente 3))
    (mensaje-aviso4 of mensaje-aviso (contenido "¡Si no quieres jugar más terminamos el juego, la próxima vez jugaremos más!")(ambiente 4))

    (nervioso1 of personalidad (nombre "nervioso")(desviacion "Se aburre") (respuesta 2))
    (nervioso2 of personalidad (nombre "nervioso")(desviacion "Se enfada")(respuesta 1))
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
)