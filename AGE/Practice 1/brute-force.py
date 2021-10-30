import requests

chromosome_seed = '0000000000000000000000000000000000000000000000000000000000000000'  # 4 station each 16 bits

web_to_request = "http://memento.evannai.inf.uc3m.es/age/test?c="

min_eva = None  # Value of min evaluation
min_chromosome = None  # Chromosome that produce de min
nEval = 0  # Num. of evaluations
min_neva = 0  # Num. of evaluations of min_eva
output_file = open('output_brute-force.txt', 'w')
# all_output_file = open('all_output_file.txt', 'w')
# all_output_best_fitness_file = open('all_output_best_fitness_file.txt', 'w')


for i in range(0, pow(2, 16)):
    chromosome_binary = chromosome_seed
    request_answer = None

    chromosome_int = int(chromosome_binary, 2) + pow(2, 3 * 16) * i  # Adjust for the station 1
    chromosome_binary = format(chromosome_int, "064b")
    try:
        request_answer = requests.get(web_to_request + chromosome_binary)
        nEval = nEval + 1
    except:
        i = i - 1

    if min_eva is None or min_eva > request_answer.text:
        min_eva = request_answer.text
        min_chromosome = chromosome_binary
        min_neva = nEval
        newMin = str(min_neva) + ", " + min_chromosome + ", " + min_eva
        output_file.write(newMin + "\n")
        print(newMin)

    # print(str(nEval) + ", " + chromosome_binary + ", " + r.text)
    # all_output = str(nEval) + ", " + chromosome_binary + ", " + r.text
    # all_output_best_fitness = str(nEval) + ", " + min_chromosome + ", " + min_eva
    # all_output_file.write(all_output + "\n")
    # all_output_best_fitness_file.write(all_output_best_fitness + "\n")

print("Se han realizado", nEval, "evaluaciones, el mejor resultado ha sido", min_eva, "para el cromosoma",
      min_chromosome, "se ha obtenido en la evaluación", min_neva)
output_file.close()
# all_output_file.close()
# all_output_best_fitness_file.close()
