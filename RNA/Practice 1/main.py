import numpy
import csv


def createData():
    data = numpy.array(list(csv.reader(open(r".\test.csv", "rt"), delimiter=","))).astype("float")
    weights = numpy.random.uniform(-1, 1, 9)  # Podemos cambiar el rango por -5, +5
    return data, weights


def createOutput(pattern, weights):
    pattern[8] = 1.0
    return numpy.dot(pattern, weights)


if __name__ == "__main__":
    d, w = createData()

    for i in range(0, 1000):
        for j in range(0, len(d)):
            createOutput(d[j], w)
