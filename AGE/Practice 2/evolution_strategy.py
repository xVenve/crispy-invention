import numpy as np
import random

import requests

NUM_MOTOR = 4
web_to_request_4 = "http://memento.evannai.inf.uc3m.es/age/robot4?"

population =np.zeros((NUM_MOTOR, 2), dtype = float)

for i in range(0, NUM_MOTOR):
    population[i][0] = random.gauss(0, 100)
    population[i][1] = random.SystemRandom().uniform(5, 20)


# Hacer de -180 a 180 al inicializar, trabaja bien con negativos

grados = ""
for i in range(1, NUM_MOTOR+1):
    if i == 1:
        grados = "c"+str(i)+"="+str(population[i-1][0])
    else:
        grados = grados+ "&c"+str(i)+"="+str(population[i-1][0])

mejoras = 0
c= 0.82

for it in range(0, 100000):
    p_eva = requests.get(web_to_request_4 + grados)

    # nuevo individuos
    hijo =np.zeros((NUM_MOTOR, 2), dtype = float)
    for i in range(0, NUM_MOTOR):
        hijo[i][0] = population[i][0] + random.gauss(0, population[i][1])
        hijo[i][1] = population[i][1]

    grados = ""
    for i in range(1, NUM_MOTOR+1):
        if i == 1:
            grados = "c"+str(i)+"="+str(hijo[i-1][0])
        else:
            grados = grados+ "&c"+str(i)+"="+str(hijo[i-1][0])

    # Hacer de -180 a 180 al inicializar, trabaja bien con negativos

    p_evah = requests.get(web_to_request_4 + grados)

    percentaje = 2
    # Evaluo hijo, si es mejor padre -1 mejora, si hijo mejor +1 mejora y calculamos la varianza del hijo

    print(p_eva.text, p_evah.text)
    eva_mejor = 0
    if p_evah.text < p_eva.text:
        print("cambio hijo")
        population = hijo.copy()
        eva_mejor = p_evah.text
        if mejoras < 10:
            mejoras = mejoras + 1
        if it > 9:
            cambio = 1
            if mejoras < percentaje:
                cambio = c
            if mejoras > percentaje:
                cambio = 1/c

            for i in range(0, NUM_MOTOR):
                hijo[i][1] = hijo[i][1]*cambio
    else:
        eva_mejor = p_eva.text
        if mejoras > 0:
            mejoras = mejoras - 1

    print(eva_mejor)
