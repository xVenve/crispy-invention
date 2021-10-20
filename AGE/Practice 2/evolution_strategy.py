import numpy as np
import random

import requests

NUM_MOTOR = 4
web_to_request_4 = "http://memento.evannai.inf.uc3m.es/age/robot4?"


def list_to_string(list_of_values):
    return ' '.join([str(v[0]) for v in list_of_values])


def initial_individual():
    individual = np.zeros((NUM_MOTOR, 2), dtype=float)

    for i in range(0, NUM_MOTOR):
        individual[i][0] = random.gauss(0, 100)
        individual[i][1] = random.SystemRandom().uniform(5, 20)
    return individual


def evaluate_individual(individual):
    degrees = ""
    for i in range(1, NUM_MOTOR + 1):
        if i == 1:
            degrees = "c" + str(i) + "=" + str(individual[i - 1][0])
        else:
            degrees = degrees + "&c" + str(i) + "=" + str(individual[i - 1][0])

    evaluation = None
    while evaluation is None:
        try:
            evaluation = requests.get(web_to_request_4 + degrees)
        except:
            pass
    return evaluation.text


def crossover(individual):
    son = individual.copy()
    for i in range(0, NUM_MOTOR):
        son[i][0] = son[i][0] + random.gauss(0, son[i][1])
    return son


def individual_next_generation(individual, son, improvements_counter, iteration, c):
    evaluation_father = evaluate_individual(individual)
    evaluation_son = evaluate_individual(son)
    if evaluation_son < evaluation_father:
        individual = son.copy()
        evaluation_father = evaluation_son
        if improvements_counter < 10:
            improvements_counter = improvements_counter + 1
        if iteration > 9:
            change_in_variance = 1
            if improvements_counter < 2:
                change_in_variance = c
            if improvements_counter > 2:
                change_in_variance = 1 / c
            for i in range(0, NUM_MOTOR):
                son[i][1] = son[i][1] * change_in_variance
    else:
        if improvements_counter > 0:
            improvements_counter = improvements_counter - 1

    return individual, evaluation_father, improvements_counter


def EE1plus1(c, cycles, test_iteration):
    output_file = open('output_evolution_strategy' + "_" + str(cycles) + "_" + str(c) + "_" + str(test_iteration) +
                       '.txt', 'w')
    individual = initial_individual()
    improvements_counter = 0
    for i in range(0, cycles):
        son = crossover(individual)
        individual, best_evaluation, improvements_counter = individual_next_generation(individual, son,
                                                                                       improvements_counter, i, c)
        output_file.write(str(2 * i) + " " + str(best_evaluation) + " " + list_to_string(individual) + "\n")
        print("Generación " + str(i) + ": " + str(best_evaluation) + "\t Grados: " + list_to_string(individual))
    output_file.close()


if __name__ == '__main__':
    EE1plus1(0.82, 2000, 1)
    EE1plus1(0.82, 2000, 2)
    EE1plus1(0.82, 2000, 3)
    EE1plus1(0.82, 2000, 4)
    EE1plus1(0.82, 2000, 5)

    EE1plus1(0.82, 5000, 1)
    EE1plus1(0.82, 5000, 2)
    EE1plus1(0.82, 5000, 3)
    EE1plus1(0.82, 5000, 4)
    EE1plus1(0.82, 5000, 5)

    EE1plus1(0.62, 2000, 1)
    EE1plus1(0.62, 2000, 2)
    EE1plus1(0.62, 2000, 3)
    EE1plus1(0.62, 2000, 4)
    EE1plus1(0.62, 2000, 5)

    EE1plus1(0.62, 5000, 1)
    EE1plus1(0.62, 5000, 2)
    EE1plus1(0.62, 5000, 3)
    EE1plus1(0.62, 5000, 4)
    EE1plus1(0.62, 5000, 5)

    EE1plus1(1.02, 2000, 1)
    EE1plus1(1.02, 2000, 2)
    EE1plus1(1.02, 2000, 3)
    EE1plus1(1.02, 2000, 4)
    EE1plus1(1.02, 2000, 5)

    EE1plus1(1.02, 5000, 1)
    EE1plus1(1.02, 5000, 2)
    EE1plus1(1.02, 5000, 3)
    EE1plus1(1.02, 5000, 4)
    EE1plus1(1.02, 5000, 5)
