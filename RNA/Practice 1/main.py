import numpy
import csv


def createDataTraining(path):
    data = numpy.array(list(csv.reader(open(path, "rt"), delimiter=","))).astype("float")
    weights = numpy.random.uniform(-1, 1, len(data[0]))  # Podemos cambiar el rango por -5, +5
    return data, weights


def createData(path):
    data = numpy.array(list(csv.reader(open(path, "rt"), delimiter=","))).astype("float")
    return data


def calculateOutput(pattern, weights):
    pattern_copy = pattern
    pattern_copy[len(pattern)-1] = 1.0
    return numpy.dot(pattern_copy, weights)


def adjustWeights(data, weights, gamma, output, ):
    for i in range(0, len(weights) - 1):
        weights[i] = weights[i] + gamma * (data[len(data)-1] - output) * data[i]

    weights[len(data)-1] = weights[len(data)-1] + gamma * (data[len(data)-1] - output)


def calculateErrors(data, output):
    n = len(data)
    sum_sqrt = 0
    sum_ab = 0
    for x in range(0, n):
        res = (data[x][len(data[0])-1] - output[x])
        sum_sqrt = sum_sqrt + res ** 2
        sum_ab = sum_ab + abs(res)
    mse = 1 / n * sum_sqrt
    mae = 1 / n * sum_ab
    return mse, mae


def ADALINE(path_training, path_validation, path_test, gamma, cycles):
    data_training, weights = createDataTraining(path_training)
    data_validation = createData(path_validation)
    data_test = createData(path_test)
    test_array = []

    for i in range(0, cycles):
        training_array = []
        validation_array = []
        for j in range(0, len(data_training)):
            training_output = calculateOutput(data_training[j], weights)
            training_array = numpy.append(training_array, training_output)
            adjustWeights(data_training[j], weights, gamma, training_output)
        # print(calculateErrors(data_training, training_array))
        for h in range(0, len(data_validation)):
            validation_output = calculateOutput(data_validation[h], weights)
            validation_array = numpy.append(validation_array, validation_output)
        mse, mae = calculateErrors(data_validation, validation_array)
        print(f"{mse:.20f}", f"{mae:.20f}")

    for k in range(0, len(data_test)):
        test_output = calculateOutput(data_test[k], weights)
        test_array = numpy.append(test_array, test_output)
    # print(calculateErrors(data_test, test_array))


if __name__ == "__main__":
    ADALINE(r".\training.csv", r".\validation.csv", r".\test.csv", 0.01, 1000)
