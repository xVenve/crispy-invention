import random
import numpy as np
import requests

NUM_STATIONS = 4
SIZE_POBLATION = 6

web_to_request = "http://memento.evannai.inf.uc3m.es/age/test?c="


def initial_poblation():
    arr = np.zeros((SIZE_POBLATION, NUM_STATIONS * 16), dtype=int)
    for i in range(0, len(arr)):
        for j in range(0, len(arr[0])):
            arr[i][j] = random.randint(0, 1)
    return arr


def evaluate_poblation(array):
    evaluation = []
    for i in range(0, len(array)):
        string_ints = [str(int) for int in array[i]]
        chromosome = ''.join(string_ints)
        request_answer = requests.get(web_to_request + chromosome)
        evaluation.append(request_answer.text)
    return evaluation


def tournament(array, evaluation, num_cand):
    new_poblation = []
    for k in range(0, SIZE_POBLATION):
        candidates = []
        for i in range(0, num_cand):
            n = random.randint(0, len(array) - 1)
            candidates.append([n, evaluation[n]])

        min = None
        min_index = None
        for j in range(0, num_cand):
            if min is None or min > candidates[j][1]:
                min = candidates[j][1]
                min_index = candidates[j][0]
        new_poblation.append(array[min_index])
    return new_poblation


def cruce_uniforme(array):
    new_poblation = []
    for i in range(0, len(array), 2):
        a = []
        b = []
        for j in range(0, len(array[0])):
            n = random.randint(0, 1)
            if n == 0:
                a.append(array[i][j])
                b.append(array[i + 1][j])
            else:
                b.append(array[i][j])
                a.append(array[i + 1][j])
        new_poblation.append(a)
        new_poblation.append(b)
    return new_poblation


def mutation(array, factor):
    for i in range(0, len(array)):
        for j in range(0, len(array[0])):
            n = random.randint(1, 100)
            if n <= factor:
                array[i][j] = 1 - array[i][j]
    return array


p = initial_poblation()
e = evaluate_poblation(p)
for i in range(0, 100):
    b = tournament(p, e, 3)
    c = cruce_uniforme(b)
    p = mutation(c, 5)
    e = evaluate_poblation(p)

print(evaluate_poblation(p))
