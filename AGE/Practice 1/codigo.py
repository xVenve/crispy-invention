# INICIALIZACION DE LA POBLACION

import numpy as np
import random
import requests

web = 'http://memento.evannai.inf.uc3m.es/age/pilar?c='
SIZE = 100  # FILAS (INDIVIDUOS)
STATIONS = 384  # COLUMNAS


def initialize_population():
    population = np.zeros((SIZE, STATIONS), dtype=int)

    for i in range(0, len(population)):
        for j in range(0, len(population[0])):
            population[i][j] = random.randint(0, 1)
    return population


def evaluate_population(population):
    evaluation_array = []
    for i in range(0, len(population)):
        chromosome_binary = [str(int) for int in population[i]]
        string = ''.join(chromosome_binary)
        request = None
        while request is None:
            try:
                request = requests.get(web + string)
            except:
                pass
        evaluation_array.append(float(request.text))
    return evaluation_array


def tournament(population, evaluation, num_candidates):
    new_population = []
    for k in range(0, SIZE):
        candidates = []
        for i in range(0, num_candidates):
            n = random.randint(0, len(population) - 1)
            candidates.append([n, evaluation[n]])
        min_evaluation = None
        min_index = None
        for j in range(0, num_candidates):
            if min_evaluation is None or min_evaluation > candidates[j][1]:
                min_evaluation = candidates[j][1]
                min_index = candidates[j][0]
        new_population.append(population[min_index])
    return new_population


def cruce(population):
    new_population = []
    for i in range(0, len(winners), 2):
        father = winners[i]
        mother = winners[i + 1]
        s1 = []
        s2 = []
        for j in range(0, len(father)):
            rando = random.randint(0, 1)
            if rando == 0:
                s1.append(father[j])
                s2.append(mother[j])
            else:
                s1.append(mother[j])
                s2.append(father[j])
        new_population.append(s1)
        new_population.append(s2)
    return new_population


def mutation(population):
    prob = 0
    for solution in population:
        for i in range(0, len(solution)):
            prob = random.randint(0, 100)
            if prob <= 0.5:
                solution[i] = 1 - solution[i]
    return population


if __name__ == '__main__':
    population = initialize_population()
    gen = 1

    minim_abs = 999999999
    generations = 300
    i = 0
    while i<generations:
        evaluation = evaluate_population(population)
        winners = tournament(population, evaluation, 10)
        population = cruce(population)
        population = mutation(population)
        minim = 9999999
        for number in evaluation:
            if float(number) < minim:
                minim = float(number)
                if minim < minim_abs:
                    minim_abs = minim
        if i == generations-1:
            print(minim, minim_abs)
        else:
            print(minim)
        i = i+1

        gen = gen + 1
