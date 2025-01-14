import numpy as np
import random

import requests

NUM_MOTOR = 10
web_to_request_4 = "http://memento.evannai.inf.uc3m.es/age/robot4?"
web_to_request_10 = "http://memento.evannai.inf.uc3m.es/age/robot10?"


def list_to_string(list_of_values):
    return ' '.join([str(v[0]) for v in list_of_values])


def initial_individual():
    individual = np.zeros((NUM_MOTOR, 2), dtype=float)

    for it in range(0, NUM_MOTOR):
        individual[it][0] = random.gauss(0, 100)
        individual[it][1] = random.SystemRandom().uniform(5, 20)
    return individual


def evaluate_individual(individual):
    degrees = ""
    for it in range(1, NUM_MOTOR + 1):
        if it == 1:
            degrees = "c" + str(it) + "=" + str(individual[it - 1][0])
        else:
            degrees = degrees + "&c" + str(it) + "=" + str(individual[it - 1][0])

    evaluation = None
    while evaluation is None:
        try:
            evaluation = requests.get(web_to_request_10 + degrees)
        except:
            pass
    return evaluation.text


def mutate_codification(individual):
    son = individual.copy()
    for it in range(0, NUM_MOTOR):
        son[it][0] = son[it][0] + random.gauss(0, son[it][1])
    return son


def individual_next_generation(individual, son, improvements_counter, iteration, c):
    evaluation_father = evaluate_individual(individual)
    evaluation_son = evaluate_individual(son)
    improvement = np.roll(improvements_counter.copy(), -1)
    if float(evaluation_son) < float(evaluation_father):
        individual = son.copy()
        evaluation_father = evaluation_son
        if np.count_nonzero(improvement) < 10:
            improvement[9] = True
    else:
        if np.count_nonzero(improvement) > 0:
            improvement[9] = False
    if iteration > 9:
        change_in_variance = 1
        if np.count_nonzero(improvement) < 2:
            change_in_variance = c
        if np.count_nonzero(improvement) > 2:
            change_in_variance = 1 / c
        for it in range(0, NUM_MOTOR):
            individual[it][1] = individual[it][1] * change_in_variance
    return individual, evaluation_father, improvement


def EE1plus1(c, cycles, test_iteration):
    output_file = open('./logs/output_evolution_strategy_5-20' + "_" + str(NUM_MOTOR) + "_" + str(cycles) + "_" + str(c)
                       + "_" + str(test_iteration) + '.txt', 'w')
    output_file2 = open('results10.txt', 'a')
    individual = initial_individual()
    improvements_counter = np.zeros(10, dtype=bool)
    absolute_best_evaluation = None
    absolute_best_num_evaluation = None
    for it in range(0, cycles):
        son = mutate_codification(individual)
        individual, best_evaluation, improvements_counter = individual_next_generation(individual, son,
                                                                                       improvements_counter, it, c)
        if absolute_best_evaluation is None or float(absolute_best_evaluation) > float(best_evaluation):
            absolute_best_evaluation = best_evaluation
            absolute_best_num_evaluation = 2 * it
        output_file.write(str(2 * it) + " " + str(best_evaluation) + " " + list_to_string(individual) + "\n")
        print("Generación " + str(it) + ": " + str(best_evaluation) + "\t Grados: " + list_to_string(individual))
        if float(best_evaluation) == 0:
            break
    output_file2.write('output_evolution_strategy_5-20' + "_" + str(NUM_MOTOR) + "_" + str(cycles) + "_" + str(c) +
                       "_" + str(test_iteration) + " " + str(absolute_best_num_evaluation) + " " +
                       str(absolute_best_evaluation) + "\n")
    output_file.close()
    output_file2.close()


if __name__ == '__main__':
    for i in range(1, 11):
        EE1plus1(0.98, 10000, i)
        EE1plus1(0.92, 10000, i)
        EE1plus1(0.82, 10000, i)
        EE1plus1(0.72, 10000, i)
        EE1plus1(0.62, 10000, i)
