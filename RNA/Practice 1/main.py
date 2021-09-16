import numpy
import csv


def createDataTraining():
    data = numpy.array(list(csv.reader(open(r".\training.csv", "rt"), delimiter=","))).astype("float")
    weights = numpy.random.uniform(-1, 1, 9)  # Podemos cambiar el rango por -5, +5
    return data, weights

def createData(path):
    data = numpy.array(list(csv.reader(open(path, "rt"), delimiter=","))).astype("float")
    return data

def createOutput(pattern, weights):
    pattern_copy = pattern
    pattern_copy[8] = 1.0
    return numpy.dot(pattern_copy, weights)

def adjustWeights (data, weights, delta, output,):
    for i in range (0, len (weights)-1):
        weights[i] = weights[i] + delta * (data[8] - output) * data[i]

    weights[8] = delta * (data[8]-output)

def calculateErrors(data, output):
    n = len(data)
    sum = 0
    sum_ab = 0
    for x in range (0, n):
        res = (data[x][8] - output[x])
        sum = sum + res**2
        sum_ab = sum_ab + abs(res)
    mse = 1/n * sum
    mae = 1/n * sum_ab
    return mse, mae



if __name__ == "__main__":
    data_training, weights = createDataTraining()
    data_validation = createData(r".\validation.csv")
    data_test = createData(r".\test.csv")
    test_array = []

    for i in range(0, 1000):
        training_array = []
        validation_array = []
        for j in range(0, len(data_training)):
            t = createOutput(data_training[j], weights)
            training_array = numpy.append(training_array, t)
            adjustWeights(data_training[j], weights, 0.01, t)
        # print(calculateErrors(data_training, training_array))
        for h in range(0, len(data_validation)):
            v = createOutput(data_validation[h], weights)
            validation_array = numpy.append(validation_array, v)
        # print(calculateErrors(data_validation, validation_array))

    for k in range(0, len(data_test)):
        v = createOutput(data_test[k], weights)
        test_array = numpy.append(test_array, v)
    print(calculateErrors(data_test, test_array))
