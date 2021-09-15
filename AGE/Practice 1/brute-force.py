import requests

initial_chromosome = '0000000000000000000000000000000000000000000000000000000000000000'  # 4 station

web_to_request = "http://memento.evannai.inf.uc3m.es/age/test?c="

min_eva = None
min_chomosome = None
nEval = 0  # Poner contador de evaluaciones
output_file = open('output_brute-force.txt', 'a')

for i in range(0, pow(2, 16)):
    chomosome_binary = initial_chromosome

    chromosome_int = int(chomosome_binary, 2) + i
    chomosome_binary = format(chromosome_int, "064b")

    r = requests.get(web_to_request + chomosome_binary)
    nEval = nEval + 1

    print(r.text)

    if min_eva is None or min_eva > r.text:
        min_eva = r.text
        min_chomosome = chomosome_binary
        output_file.write(str(nEval) + ", "+min_chomosome + ", " + min_eva + "\n")

print("Valor de evaluación: " + str(min_eva))
output_file.close()  # Poner el cromosoma en la salida y el nEval. Tener en cuenta las excepciones de web para actuar y no pare
