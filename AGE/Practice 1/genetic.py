import random
import numpy as np
import requests

NUM_STATIONS = 24
SIZE_POPULATION = 100

web_to_request = "http://memento.evannai.inf.uc3m.es/age/pilar?c="
web_to_practice1 = "http://memento.evannai.inf.uc3m.es/age/alfa?c="
web_to_test = "http://memento.evannai.inf.uc3m.es/age/test?c="


# Creación de la población inicial de manera aleatoria, SIZE_POPULATION individuos de NUM_STATIONS*16 bits
def initial_population():
    population = np.zeros((SIZE_POPULATION, NUM_STATIONS * 16), dtype=int)
    for i in range(0, len(population)):
        for j in range(0, len(population[0])):
            population[i][j] = random.randint(0, 1)
    return population


# Obtenemos un array con las evaluaciones de la población pasada, además de un contador de evaluaciones
def evaluate_population(population, num_evaluations):
    evaluations = []
    for i in population:
        chromosome = list_to_string(i)
        evaluation = None
        while evaluation is None:
            try:
                evaluation = requests.get(web_to_request + chromosome)
            except:
                pass
        evaluations.append(float(evaluation.text))
        num_evaluations = num_evaluations + 1
    return evaluations, num_evaluations


def list_to_string(list_of_integers):
    return ''.join([str(v) for v in list_of_integers])


# Se crea una población de tamaño SIZE_POPULATION mediante la selección del más válido entre num_candidates individuos
# elegidos aleatoriamente de la población original
def tournament_selection(population, evaluation, num_candidates):
    new_population = []
    for k in range(0, SIZE_POPULATION):
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


# Por pares, se parten ambos cromosomas por un mismo gen y se generan 2 individuos, cogiendo un parte de cada progenitor
def discrete_crossover(population):
    new_population = []
    for i in range(0, len(population), 2):
        s1 = []
        s2 = []
        n = random.randint(0, len(population[0]))
        it = 0
        for j in range(0, len(population[0])):
            if n > it:
                s1.append(population[i][j])
                s2.append(population[i + 1][j])
            else:
                s2.append(population[i][j])
                s1.append(population[i + 1][j])
            it = it + 1
        new_population.append(s1)
        new_population.append(s2)
    return new_population


# Por pares, se van eligiendo genes homólogos de los progenitores aleatoriamente generando dos nuevos individuos
def uniform_crossover(population):
    new_population = []
    for i in range(0, len(population), 2):
        a = []
        b = []
        for j in range(0, len(population[0])):
            n = random.randint(0, 1)
            if n == 0:
                a.append(population[i][j])
                b.append(population[i + 1][j])
            else:
                b.append(population[i][j])
                a.append(population[i + 1][j])
        new_population.append(a)
        new_population.append(b)
    return new_population


# De manera aleatoria y con probabilidad factor se modifican los genes de los individuos de la población
def mutation(population, factor):
    for i in range(0, len(population)):
        for j in range(0, len(population[0])):
            n = np.random.rand() * 100
            if n < factor:
                population[i][j] = 1 - population[i][j]
    return population


def get_best_chromosome(population, evaluations):
    min_value = min(evaluations)
    min_index = evaluations.index(min_value)
    return min_value, population[min_index]


# Se encarga de realizar todo el procedimiento del algoritmo genético y almacena los resultados correspondientes
def AG(cycles, size_tournament, mutation_factor, test_iteration):
    output_file = open('output_genetic_algorithm' + "_" +
                       str(cycles) + "_" + str(size_tournament) + "_" + str(mutation_factor) + "_" + str(test_iteration)
                       + '.txt', 'w')
    absolute_best_fitness = None
    absolute_best_chromosome = None
    population = initial_population()
    num_evaluations = 0
    evaluations, num_evaluations = evaluate_population(population, num_evaluations)
    for i in range(0, cycles):
        population_post_selection = tournament_selection(population, evaluations, size_tournament)
        population_post_crossover = uniform_crossover(population_post_selection)
        population = mutation(population_post_crossover, mutation_factor)
        evaluations, num_evaluations = evaluate_population(population, num_evaluations)

        best_fitness, best_chromosome = get_best_chromosome(population, evaluations)
        if absolute_best_fitness is None or absolute_best_fitness > best_fitness:
            absolute_best_fitness = best_fitness
            absolute_best_chromosome = best_chromosome
        print("Generación " + str(i) + ": " + str(best_fitness) + "\t" + list_to_string(best_chromosome) +
              "\nMejor absoluto: " + str(absolute_best_fitness) + "\t" + list_to_string(absolute_best_chromosome))
        output_file.write(str(num_evaluations) + " " + str(best_fitness) + " " + list_to_string(best_chromosome) + "\n")
        if absolute_best_fitness == 0:
            break
    output_file.write(
        "Mejor resultado: " + str(absolute_best_fitness) + " " + list_to_string(absolute_best_chromosome) + "\n")
    output_file.close()


if __name__ == '__main__':
    AG(2000, 10, 0.5, 'easy1')
