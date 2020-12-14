import sys


class Nodo():

    def __init__(self, parent=None, bateria1=None, sat1franjas=None, observaciones1=None, operacion1=None, pos=None,
                 bateria2=None, sat2franjas=None, observaciones2=None, numOBSrestantes=None, operacion2=None,
                 g=None, h=None, f=None, OBS=[]):
        self.parent = parent

        self.pos = pos

        self.bateria1 = bateria1
        self.sat1franjas = sat1franjas
        self.observaciones1 = observaciones1
        self.operacion1 = operacion1

        self.bateria2 = bateria2
        self.sat2franjas = sat2franjas
        self.observaciones2 = observaciones2
        self.operacion2 = operacion2

        self.numOBSrestantes = numOBSrestantes
        self.g = g
        self.h = h
        self.f = f
        self.OBS = OBS

    def __eq__(self, other):
        # and (self.g == other.g) and (self.h == other.h) and (self.f == other.f)
        return (self.bateria1 == other.bateria1) and (self.pos == other.pos) and (self.sat1franjas == other.sat1franjas) and (self.observaciones1 == other.observaciones1) and (self.operacion1 == other.operacion1) and (self.bateria2 == other.bateria2) and (self.sat2franjas == other.sat2franjas) and (self.observaciones2 == other.observaciones2) and (self.numOBSrestantes == other.numOBSrestantes) and (self.operacion2 == other.operacion2)


def astar(problema, heuristica):

    # Leer el problema y extraer los datos
    f = open(problema, "r")
    lineas = f.read().splitlines()
    OBS = lineas[0][5:].split(';')
    SAT1 = lineas[1][6:].split(';')
    SAT2 = lineas[2][6:].split(';')
    f.close

    SAT1costeOBS = int(SAT1[0])
    SAT1costeTRANS = int(SAT1[1])
    SAT1costeGIR = int(SAT1[2])
    SAT1costeCAR = int(SAT1[3])

    SAT2costeOBS = int(SAT2[0])
    SAT2costeTRANS = int(SAT2[1])
    SAT2costeGIR = int(SAT2[2])
    SAT2costeCAR = int(SAT1[3])

    # Creacion de estado inicial PONER QUE h Y f SEAN DE LA HEURISTICA
    start = Nodo(None, int(SAT1[4]), '(0,1)', 0, None, 0, int(
        SAT2[4]), '(2,3)', 0, len(OBS), None, 0, 0, 0, OBS[:])
    # Creacion de la lista abierta y la lista cerrada
    open_list = []
    closed_list = []

    open_list.append(start)

    nodo_prev = None

    # Crear el loop para el algoritmo
    while len(open_list) > 0:
        print('Numero de estados abierta:', len(open_list))
        for nodoi in open_list:
            print(nodoi.bateria1, " ", nodoi.sat1franjas, " ", nodoi.observaciones1, " ", nodoi.operacion1, " ",
                  nodoi.pos, " ", nodoi.bateria2, " ", nodoi.sat2franjas, " ", nodoi.observaciones2, " ",
                  nodoi.numOBSrestantes, " ", nodoi.operacion2, " ", nodoi.g, " ", nodoi.h, " ", nodoi.f)

        nodo_actual = None

        encontrado = True
        while encontrado == True:

            encontrado = False
            if len(open_list) > 0:
                nodo_actual = open_list.pop(0)
                for nodo in closed_list:
                    if nodo_actual == nodo:
                        encontrado = True
                        break

                if encontrado == False:
                    closed_list.append(nodo_actual)
            else:
                print('No se ha encontrado solución')
                sys.exit(0)

        print('Estado actual:', nodo_actual.bateria1, " ", nodo_actual.sat1franjas, " ", nodo_actual.observaciones1,
              " ", nodo_actual.operacion1, " ", nodo_actual.pos, " ", nodo_actual.bateria2, " ", nodo_actual.sat2franjas, " ", nodo_actual.observaciones2, " ", nodo_actual.numOBSrestantes, " ", nodo_actual.operacion2, " ", nodo_actual.g,
              " ", nodo_actual.h, " ", nodo_actual.f)

        """ for obss in OBS:
            print(obss[1], " ", obss[3]) """

        # Comprobacion de si es el nodo final
        if nodo_actual.numOBSrestantes == 0:
            print('El estado final cuesta =  ', nodo_prev.f)
            while nodo_prev != start:
                print("SAT1:", nodo_prev.operacion1,
                      "SAT2:", nodo_prev.operacion2, "Coste", nodo_prev.f)
                nodo_prev = nodo_prev.parent
            break

        # Generación de hijos
        nodohijo1 = None
        boolhijo1 = False
        nodohijo2 = None
        boolhijo2 = False
        nodohijo3 = None
        boolhijo3 = False
        nodohijo4 = None
        boolhijo4 = False
        nodohijo5 = None
        boolhijo5 = False

        # Operación de Observación1
        if nodo_actual.bateria1 >= SAT1costeOBS and nodo_actual.pos < 12 and nodo_actual.OBS != None:
            for elem in nodo_actual.OBS:

                """ print(elem[1], "==", nodo_actual.sat1franjas[1], " or ", elem[1], " == ",
                      nodo_actual.sat1franjas[3]," and ", elem[3]," == ",nodo_actual.pos)

                print(elem[1] == nodo_actual.sat1franjas[1]
                      and elem[3] == nodo_actual.pos)

                print(elem[1] == nodo_actual.sat1franjas[3]
                      and elem[3] == nodo_actual.pos) """

                if (int(elem[1]) == int(nodo_actual.sat1franjas[1]) or int(elem[1]) == int(nodo_actual.sat1franjas[3])) and int(elem[3]) == nodo_actual.pos:
                    print("Ope11")
                    nodohijo1 = Nodo(nodo_actual, nodo_actual.bateria1-SAT1costeOBS, nodo_actual.sat1franjas,
                                     nodo_actual.observaciones1+1, 'Observa', nodo_actual.pos+1, None, None, None, None, None, None, None, None, nodo_actual.OBS[:])
                    nodohijo1.OBS.remove(elem)
                    boolhijo1 = True
                    break

        # Operación de Giro1
        if nodo_actual.bateria1 >= SAT1costeGIR and nodo_actual.pos < 12:
            print("Ope21")
            if nodo_actual.sat1franjas == '(0,1)':
                nodohijo2 = Nodo(nodo_actual, nodo_actual.bateria1-SAT1costeGIR, '(1,2)', nodo_actual.observaciones1,
                                 'Gira', nodo_actual.pos+1,  None, None, None, None, None, None, None, None, None)
                boolhijo2 = True
            else:
                nodohijo2 = Nodo(nodo_actual, nodo_actual.bateria1-SAT1costeGIR, '(0,1)', nodo_actual.observaciones1,
                                 'Gira', nodo_actual.pos+1,  None, None, None, None, None, None, None, None, None)
                boolhijo2 = True

        # Operación de IDLE1
        if nodo_actual.pos < 12:
            print("Ope31")
            nodohijo3 = Nodo(nodo_actual, nodo_actual.bateria1, nodo_actual.sat1franjas, nodo_actual.observaciones1,
                             'IDLE', nodo_actual.pos+1,  None, None, None, None, None, None, None, None, None)
            boolhijo3 = True

        # Operación de Carga1
        if nodo_actual.pos < 12 and (nodo_actual.bateria1 <= start.bateria1 - SAT1costeCAR):
            print("Ope41")
            nodohijo4 = Nodo(nodo_actual, nodo_actual.bateria1+SAT1costeCAR, nodo_actual.sat1franjas,
                             nodo_actual.observaciones1, 'Carga', nodo_actual.pos+1, None, None, None, None, None, None, None, None, None)
            boolhijo4 = True

        # Operación de Transmisión1
        if nodo_actual.observaciones1 > 0 and nodo_actual.pos < 12 and nodo_actual.bateria1 >= SAT1costeTRANS:
            print("Ope51")
            nodohijo5 = Nodo(nodo_actual, nodo_actual.bateria1-SAT1costeTRANS, nodo_actual.sat1franjas,
                             nodo_actual.observaciones1-1, 'Transmite', nodo_actual.pos+1, None, None, None, None, None, None, None, None, None)
            boolhijo5 = True

        print("O", boolhijo1, " G", boolhijo2, " I",
              boolhijo3, " C", boolhijo4, " T", boolhijo5)

        # Operación de Observación2
        if nodo_actual.bateria2 >= SAT2costeOBS and nodo_actual.pos < 12 and len(nodo_actual.OBS) > 0:

            if boolhijo1 == True and len(nodohijo1.OBS) > 0:
                for elem in nodohijo1.OBS:
                    if (int(elem[1]) == int(nodo_actual.sat2franjas[1]) or int(elem[1]) == int(nodo_actual.sat2franjas[3])) and int(elem[3]) == nodo_actual.pos:
                        print("Ope121")
                        nodohijo1.bateria2 = nodo_actual.bateria2-SAT2costeOBS
                        nodohijo1.sat2franjas = nodo_actual.sat2franjas
                        nodohijo1.observaciones2 = nodo_actual.observaciones2+1
                        nodohijo1.operacion2 = 'Observa'
                        nodohijo1.numOBSrestantes = nodo_actual.numOBSrestantes
                        nodohijo1.g = nodo_actual.g + 1
                        nodohijo1.h = nodo_actual.h
                        nodohijo1.f = nodohijo1.g + nodohijo1.h
                        nodohijo1.OBS.remove(elem)
                        print('XXX', nodohijo1.bateria1, " ", nodohijo1.sat1franjas, " ", nodohijo1.observaciones1, " ", nodohijo1.operacion1, " ", nodohijo1.pos, " ", nodohijo1.bateria2,
                              " ", nodohijo1.sat2franjas, " ", nodo_actual.observaciones2, " ", nodohijo1.numOBSrestantes, " ", nodohijo1.operacion2, " ", nodohijo1.g, " ", nodohijo1.h, " ", nodohijo1.f)
                        open_list.append(nodohijo1)
                        break
            if boolhijo2 == True:
                for elem in nodo_actual.OBS:
                    if (int(elem[1]) == int(nodo_actual.sat2franjas[1]) or int(elem[1]) == int(nodo_actual.sat2franjas[3])) and int(elem[3]) == nodo_actual.pos:
                        print("Ope122")
                        nodohijo2.bateria2 = nodo_actual.bateria2-SAT2costeOBS
                        nodohijo2.sat2franjas = nodo_actual.sat2franjas
                        nodohijo2.observaciones2 = nodo_actual.observaciones2+1
                        nodohijo2.operacion2 = 'Observa'
                        nodohijo2.numOBSrestantes = nodo_actual.numOBSrestantes
                        nodohijo2.g = nodo_actual.g + 1
                        nodohijo2.h = nodo_actual.h
                        nodohijo2.f = nodohijo2.g + nodohijo2.h
                        nodohijo2.OBS = nodo_actual.OBS[:]
                        nodohijo2.OBS.remove(elem)
                        open_list.append(nodohijo2)
                        break
            if boolhijo3 == True:
                for elem in nodo_actual.OBS:
                    if (int(elem[1]) == int(nodo_actual.sat2franjas[1]) or int(elem[1]) == int(nodo_actual.sat2franjas[3])) and int(elem[3]) == nodo_actual.pos:
                        print("Ope123")
                        nodohijo3.bateria2 = nodo_actual.bateria2-SAT2costeOBS
                        nodohijo3.sat2franjas = nodo_actual.sat2franjas
                        nodohijo3.observaciones2 = nodo_actual.observaciones2+1
                        nodohijo3.operacion2 = 'Observa'
                        nodohijo3.numOBSrestantes = nodo_actual.numOBSrestantes
                        nodohijo3.g = nodo_actual.g + 1
                        nodohijo3.h = nodo_actual.h
                        nodohijo3.f = nodohijo3.g + nodohijo3.h
                        nodohijo3.OBS = nodo_actual.OBS[:]
                        nodohijo3.OBS.remove(elem)
                        open_list.append(nodohijo3)
                        break
            if boolhijo4 == True:
                for elem in nodo_actual.OBS:
                    if (int(elem[1]) == int(nodo_actual.sat2franjas[1]) or int(elem[1]) == int(nodo_actual.sat2franjas[3])) and int(elem[3]) == nodo_actual.pos:
                        print("Ope124")
                        nodohijo4.bateria2 = nodo_actual.bateria2-SAT2costeOBS
                        nodohijo4.sat2franjas = nodo_actual.sat2franjas
                        nodohijo4.observaciones2 = nodo_actual.observaciones2+1
                        nodohijo4.operacion2 = 'Observa'
                        nodohijo4.numOBSrestantes = nodo_actual.numOBSrestantes
                        nodohijo4.g = nodo_actual.g + 1
                        nodohijo4.h = nodo_actual.h
                        nodohijo4.f = nodohijo4.g + nodohijo4.h
                        nodohijo4.OBS = nodo_actual.OBS[:]
                        nodohijo4.OBS.remove(elem)
                        open_list.append(nodohijo4)
                        break
            if boolhijo5 == True:
                for elem in nodo_actual.OBS:
                    if (int(elem[1]) == int(nodo_actual.sat2franjas[1]) or int(elem[1]) == int(nodo_actual.sat2franjas[3])) and int(elem[3]) == nodo_actual.pos:
                        print("Ope125")
                        nodohijo5.bateria2 = nodo_actual.bateria2-SAT2costeOBS
                        nodohijo5.sat2franjas = nodo_actual.sat2franjas
                        nodohijo5.observaciones2 = nodo_actual.observaciones2+1
                        nodohijo5.operacion2 = 'Observa'
                        nodohijo5.numOBSrestantes = nodo_actual.numOBSrestantes-1
                        nodohijo5.g = nodo_actual.g + 1
                        nodohijo5.h = nodo_actual.h
                        nodohijo5.f = nodohijo5.g + nodohijo5.h
                        nodohijo5.OBS = nodo_actual.OBS[:]
                        nodohijo5.OBS.remove(elem)
                        open_list.append(nodohijo5)
                        break

        # Operación de Giro2
        if nodo_actual.bateria2 >= SAT1costeGIR and nodo_actual.pos < 12:
            if boolhijo1 == True:
                if nodo_actual.sat2franjas == '(2,3)':
                    print("Ope221")
                    nodohijo1.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo1.sat2franjas = '(1,2)'
                    nodohijo1.observaciones2 = nodo_actual.observaciones2
                    nodohijo1.operacion2 = 'Gira'
                    nodohijo1.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo1.g = nodo_actual.g + 1
                    nodohijo1.h = nodo_actual.h
                    nodohijo1.f = nodohijo1.g + nodohijo1.h
                    print('XXX', nodohijo1.bateria1, " ", nodohijo1.sat1franjas, " ", nodohijo1.observaciones1, " ", nodohijo1.operacion1, " ", nodohijo1.pos, " ", nodohijo1.bateria2,
                          " ", nodohijo1.sat2franjas, " ", nodo_actual.observaciones2, " ", nodohijo1.numOBSrestantes, " ", nodohijo1.operacion2, " ", nodohijo1.g, " ", nodohijo1.h, " ", nodohijo1.f)
                    open_list.append(nodohijo1)

                elif nodo_actual.sat2franjas == '(1,2)':
                    print ("ALT Open221")
                    nodohijo1.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo1.sat2franjas = '(2,3)'
                    nodohijo1.observaciones2 = nodo_actual.observaciones2
                    nodohijo1.operacion2 = 'Gira'
                    nodohijo1.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo1.g = nodo_actual.g + 1
                    nodohijo1.h = nodo_actual.h
                    nodohijo1.f = nodohijo1.g + nodohijo1.h
                    print('XXX', nodohijo1.bateria1, " ", nodohijo1.sat1franjas, " ", nodohijo1.observaciones1, " ", nodohijo1.operacion1, " ", nodohijo1.pos, " ", nodohijo1.bateria2,
                          " ", nodohijo1.sat2franjas, " ", nodo_actual.observaciones2, " ", nodohijo1.numOBSrestantes, " ", nodohijo1.operacion2, " ", nodohijo1.g, " ", nodohijo1.h, " ", nodohijo1.f)
                    open_list.append(nodohijo1)

            if boolhijo2 == True:
                print("Ope222")

                if nodo_actual.sat2franjas == '(2,3)':
                    nodohijo2.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo2.sat2franjas = '(1,2)'
                    nodohijo2.observaciones2 = nodo_actual.observaciones2
                    nodohijo2.operacion2 = 'Gira'
                    nodohijo2.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo2.g = nodo_actual.g + 1
                    nodohijo2.h = nodo_actual.h
                    nodohijo2.f = nodohijo2.g + nodohijo2.h
                    nodohijo2.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo2)
                else:
                    nodohijo2.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo2.sat2franjas = '(2,3)'
                    nodohijo2.observaciones2 = nodo_actual.observaciones2
                    nodohijo2.operacion2 = 'Gira'
                    nodohijo2.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo2.g = nodo_actual.g + 1
                    nodohijo2.h = nodo_actual.h
                    nodohijo2.f = nodohijo2.g + nodohijo2.h
                    nodohijo2.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo2)

            if boolhijo3 == True:
                print("Ope223")

                if nodo_actual.sat2franjas == '(2,3)':
                    nodohijo3.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo3.sat2franjas = '(1,2)'
                    nodohijo3.observaciones2 = nodo_actual.observaciones2
                    nodohijo3.operacion2 = 'Gira'
                    nodohijo3.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo3.g = nodo_actual.g + 1
                    nodohijo3.h = nodo_actual.h
                    nodohijo3.f = nodohijo3.g + nodohijo3.h
                    nodohijo3.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo3)
                else:
                    nodohijo3.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo3.sat2franjas = '(2,3)'
                    nodohijo3.observaciones2 = nodo_actual.observaciones2
                    nodohijo3.operacion2 = 'Gira'
                    nodohijo3.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo3.g = nodo_actual.g + 1
                    nodohijo3.h = nodo_actual.h
                    nodohijo3.f = nodohijo3.g + nodohijo3.h
                    nodohijo3.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo3)

            if boolhijo4 == True:
                print("Ope224")

                if nodo_actual.sat2franjas == '(2,3)':
                    nodohijo4.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo4.sat2franjas = '(1,2)'
                    nodohijo4.observaciones2 = nodo_actual.observaciones2
                    nodohijo4.operacion2 = 'Gira'
                    nodohijo4.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo4.g = nodo_actual.g + 1
                    nodohijo4.h = nodo_actual.h
                    nodohijo4.f = nodohijo4.g + nodohijo4.h
                    nodohijo4.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo4)
                else:
                    nodohijo4.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo4.sat2franjas = '(2,3)'
                    nodohijo4.observaciones2 = nodo_actual.observaciones2
                    nodohijo4.operacion2 = 'Gira'
                    nodohijo4.numOBSrestantes = nodo_actual.numOBSrestantes
                    nodohijo4.g = nodo_actual.g + 1
                    nodohijo4.h = nodo_actual.h
                    nodohijo4.f = nodohijo4.g + nodohijo4.h
                    nodohijo4.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo4)

            if boolhijo5 == True:
                print("Ope225")

                if nodo_actual.sat2franjas == '(2,3)':
                    nodohijo5.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo5.sat2franjas = '(1,2)'
                    nodohijo5.observaciones2 = nodo_actual.observaciones2
                    nodohijo5.operacion2 = 'Gira'
                    nodohijo5.numOBSrestantes = nodo_actual.numOBSrestantes-1
                    nodohijo5.g = nodo_actual.g + 1
                    nodohijo5.h = nodo_actual.h
                    nodohijo5.f = nodohijo5.g + nodohijo5.h
                    nodohijo5.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo5)
                else:
                    nodohijo5.bateria2 = nodo_actual.bateria2-SAT2costeGIR
                    nodohijo5.sat2franjas = '(2,3)'
                    nodohijo5.observaciones2 = nodo_actual.observaciones2
                    nodohijo5.operacion2 = 'Gira'
                    nodohijo5.numOBSrestantes = nodo_actual.numOBSrestantes-1
                    nodohijo5.g = nodo_actual.g + 1
                    nodohijo5.h = nodo_actual.h
                    nodohijo5.f = nodohijo5.g + nodohijo5.h
                    nodohijo5.OBS = nodo_actual.OBS[:]
                    open_list.append(nodohijo5)

        # Operación de IDLE2
        if int(nodo_actual.pos) < 12:

            if boolhijo1 == True:
                print("Ope321")
                nodohijo1.bateria2 = nodo_actual.bateria2
                nodohijo1.sat2franjas = nodo_actual.sat2franjas
                nodohijo1.observaciones2 = nodo_actual.observaciones2
                nodohijo1.operacion2 = 'IDLE'
                nodohijo1.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo1.g = nodo_actual.g + 1
                nodohijo1.h = nodo_actual.h
                nodohijo1.f = nodohijo1.g + nodohijo1.h
                print('XXX', nodohijo1.bateria1, " ", nodohijo1.sat1franjas, " ", nodohijo1.observaciones1, " ", nodohijo1.operacion1, " ", nodohijo1.pos, " ", nodohijo1.bateria2,
                      " ", nodohijo1.sat2franjas, " ", nodo_actual.observaciones2, " ", nodohijo1.numOBSrestantes, " ", nodohijo1.operacion2, " ", nodohijo1.g, " ", nodohijo1.h, " ", nodohijo1.f)
                open_list.append(nodohijo1)

            if boolhijo2 == True:
                print("Ope322")
                nodohijo2.bateria2 = nodo_actual.bateria2
                nodohijo2.sat2franjas = nodo_actual.sat2franjas
                nodohijo2.observaciones2 = nodo_actual.observaciones2
                nodohijo2.operacion2 = 'IDLE'
                nodohijo2.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo2.g = nodo_actual.g + 1
                nodohijo2.h = nodo_actual.h
                nodohijo2.f = nodohijo2.g + nodohijo2.h
                nodohijo2.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo2)

            if boolhijo3 == True:
                print("Ope323")
                nodohijo3.bateria2 = nodo_actual.bateria2
                nodohijo3.sat2franjas = nodo_actual.sat2franjas
                nodohijo3.observaciones2 = nodo_actual.observaciones2
                nodohijo3.operacion2 = 'IDLE'
                nodohijo3.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo3.g = nodo_actual.g + 1
                nodohijo3.h = nodo_actual.h
                nodohijo3.f = nodohijo3.g + nodohijo3.h
                nodohijo3.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo3)

            if boolhijo4 == True:
                print("Ope324")
                nodohijo4.bateria2 = nodo_actual.bateria2
                nodohijo4.sat2franjas = nodo_actual.sat2franjas
                nodohijo4.observaciones2 = nodo_actual.observaciones2
                nodohijo4.operacion2 = 'IDLE'
                nodohijo4.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo4.g = nodo_actual.g + 1
                nodohijo4.h = nodo_actual.h
                nodohijo4.f = nodohijo4.g + nodohijo4.h
                nodohijo4.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo4)

            if boolhijo5 == True:
                print("Ope325")
                nodohijo5.bateria2 = nodo_actual.bateria2
                nodohijo5.sat2franjas = nodo_actual.sat2franjas
                nodohijo5.observaciones2 = nodo_actual.observaciones2
                nodohijo5.operacion2 = 'IDLE'
                nodohijo5.numOBSrestantes = nodo_actual.numOBSrestantes-1
                nodohijo5.g = nodo_actual.g + 1
                nodohijo5.h = nodo_actual.h
                nodohijo5.f = nodohijo5.g + nodohijo5.h
                nodohijo5.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo5)

        # Operación de Carga2
        if (nodo_actual.pos < 12) and (nodo_actual.bateria2 <= int(SAT2[4]) - SAT2costeCAR):

            if boolhijo1 == True:
                print("Ope421")
                nodohijo1.bateria2 = nodo_actual.bateria2 + SAT2costeCAR
                nodohijo1.sat2franjas = nodo_actual.sat2franjas
                nodohijo1.observaciones2 = nodo_actual.observaciones2
                nodohijo1.operacion2 = 'Carga'
                nodohijo1.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo1.g = nodo_actual.g + 1
                nodohijo1.h = nodo_actual.h
                nodohijo1.f = nodohijo1.g + nodohijo1.h
                print('XXX', nodohijo1.bateria1, " ", nodohijo1.sat1franjas, " ", nodohijo1.observaciones1, " ", nodohijo1.operacion1, " ", nodohijo1.pos, " ", nodohijo1.bateria2,
                              " ", nodohijo1.sat2franjas, " ", nodo_actual.observaciones2, " ", nodohijo1.numOBSrestantes, " ", nodohijo1.operacion2, " ", nodohijo1.g, " ", nodohijo1.h, " ", nodohijo1.f)
                open_list.append(nodohijo1)

            if boolhijo2 == True:
                print("Ope422")

                nodohijo2.bateria2 = nodo_actual.bateria2 + SAT2costeCAR
                nodohijo2.sat2franjas = nodo_actual.sat2franjas
                nodohijo2.observaciones2 = nodo_actual.observaciones2
                nodohijo2.operacion2 = 'Carga'
                nodohijo2.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo2.g = nodo_actual.g + 1
                nodohijo2.h = nodo_actual.h
                nodohijo2.f = nodohijo2.g + nodohijo2.h
                nodohijo2.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo2)

            if boolhijo3 == True:
                print("Ope423")

                nodohijo3.bateria2 = nodo_actual.bateria2 + SAT2costeCAR
                nodohijo3.sat2franjas = nodo_actual.sat2franjas
                nodohijo3.observaciones2 = nodo_actual.observaciones2
                nodohijo3.operacion2 = 'Carga'
                nodohijo3.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo3.g = nodo_actual.g + 1
                nodohijo3.h = nodo_actual.h
                nodohijo3.f = nodohijo3.g + nodohijo3.h
                nodohijo3.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo3)

            if boolhijo4 == True:
                print("Ope424")

                nodohijo4.bateria2 = nodo_actual.bateria2 + SAT2costeCAR
                nodohijo4.sat2franjas = nodo_actual.sat2franjas
                nodohijo4.observaciones2 = nodo_actual.observaciones2
                nodohijo4.operacion2 = 'Carga'
                nodohijo4.numOBSrestantes = nodo_actual.numOBSrestantes
                nodohijo4.g = nodo_actual.g + 1
                nodohijo4.h = nodo_actual.h
                nodohijo4.f = nodohijo4.g + nodohijo4.h
                nodohijo4.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo4)

            if boolhijo5 == True:
                print("Ope425")

                nodohijo5.bateria2 = nodo_actual.bateria2 + SAT2costeCAR
                nodohijo5.sat2franjas = nodo_actual.sat2franjas
                nodohijo5.observaciones2 = nodo_actual.observaciones2
                nodohijo5.operacion2 = 'Carga'
                nodohijo5.numOBSrestantes = nodo_actual.numOBSrestantes - 1
                nodohijo5.g = nodo_actual.g + 1
                nodohijo5.h = nodo_actual.h
                nodohijo5.f = nodohijo5.g + nodohijo5.h
                nodohijo5.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo5)

        # Operación de Transmisión
        if nodo_actual.observaciones2 > 0 and nodo_actual.pos < 12 and nodo_actual.bateria2 >= SAT2costeTRANS:
            if boolhijo1 == True:
                print("Ope521")

                nodohijo1.bateria2 = nodo_actual.bateria2 + SAT2costeTRANS
                nodohijo1.sat2franjas = nodo_actual.sat2franjas
                nodohijo1.observaciones2 = nodo_actual.observaciones2-1
                nodohijo1.operacion2 = 'Transmite'
                nodohijo1.numOBSrestantes = nodo_actual.numOBSrestantes-1
                nodohijo1.g = nodo_actual.g + 1
                nodohijo1.h = nodo_actual.h
                nodohijo1.f = nodohijo1.g + nodohijo1.h
                print('XXX', nodohijo1.bateria1, " ", nodohijo1.sat1franjas, " ", nodohijo1.observaciones1, " ", nodohijo1.operacion1, " ", nodohijo1.pos, " ", nodohijo1.bateria2,
                      " ", nodohijo1.sat2franjas, " ", nodo_actual.observaciones2, " ", nodohijo1.numOBSrestantes, " ", nodohijo1.operacion2, " ", nodohijo1.g, " ", nodohijo1.h, " ", nodohijo1.f)
                open_list.append(nodohijo1)

            if boolhijo2 == True:
                print("Ope522")

                nodohijo2.bateria2 = nodo_actual.bateria2 + SAT2costeTRANS
                nodohijo2.sat2franjas = nodo_actual.sat2franjas
                nodohijo2.observaciones2 = nodo_actual.observaciones2-1
                nodohijo2.operacion2 = 'Transmite'
                nodohijo2.numOBSrestantes = nodo_actual.numOBSrestantes-1
                nodohijo2.g = nodo_actual.g + 1
                nodohijo2.h = nodo_actual.h
                nodohijo2.f = nodohijo2.g + nodohijo2.h
                nodohijo2.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo2)

            if boolhijo3 == True:
                print("Ope523")

                nodohijo3.bateria2 = nodo_actual.bateria2 + SAT2costeTRANS
                nodohijo3.sat2franjas = nodo_actual.sat2franjas
                nodohijo3.observaciones2 = nodo_actual.observaciones2-1
                nodohijo3.operacion2 = 'Transmite'
                nodohijo3.numOBSrestantes = nodo_actual.numOBSrestantes-1
                nodohijo3.g = nodo_actual.g + 1
                nodohijo3.h = nodo_actual.h
                nodohijo3.f = nodohijo3.g + nodohijo3.h
                nodohijo3.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo3)

            if boolhijo4 == True:
                print("Ope524")

                nodohijo4.bateria2 = nodo_actual.bateria2 + SAT2costeTRANS
                nodohijo4.sat2franjas = nodo_actual.sat2franjas
                nodohijo4.observaciones2 = nodo_actual.observaciones2-1
                nodohijo4.operacion2 = 'Transmite'
                nodohijo4.numOBSrestantes = nodo_actual.numOBSrestantes-1
                nodohijo4.g = nodo_actual.g + 1
                nodohijo4.h = nodo_actual.h
                nodohijo4.f = nodohijo4.g + nodohijo4.h
                nodohijo4.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo4)

            if boolhijo5 == True:
                print("Ope525")

                nodohijo5.bateria2 = nodo_actual.bateria2 + SAT2costeTRANS
                nodohijo5.sat2franjas = nodo_actual.sat2franjas
                nodohijo5.observaciones2 = nodo_actual.observaciones2-1
                nodohijo5.operacion2 = 'Transmite'
                nodohijo5.numOBSrestantes = nodo_actual.numOBSrestantes-2
                nodohijo5.g = nodo_actual.g + 1
                nodohijo5.h = nodo_actual.h
                nodohijo5.f = nodohijo5.g + nodohijo5.h
                nodohijo5.OBS = nodo_actual.OBS[:]
                open_list.append(nodohijo5)

        # Operación de Noche
        if nodo_actual.pos == 12:
            print("OpeNoche")
            nodohijoNoche = Nodo(nodo_actual, nodo_actual.bateria1, nodo_actual.sat1franjas,
                                 nodo_actual.observaciones1, 'Noche', 0, nodo_actual.bateria2, nodo_actual.sat2franjas, nodo_actual.observaciones2, nodo_actual.numOBSrestantes, 'Noche', nodo_actual.g+12, nodo_actual.h, nodo_actual.g+12 + nodo_actual.h, nodo_actual.OBS[:])
            open_list.append(nodohijoNoche)

        open_list = sorted(open_list, key=lambda nodo: nodo.f)
        nodo_prev = nodo_actual


if __name__ == "__main__":

    # Comprobacion del numero de parametros
    if len(sys.argv) < 3:
        print('Formato invalido. \n Cosmos.sh <problema.prob> <heuristica>')
        sys.exit(-1)

    # Llamada a A* dado un problema y heuristica
    astar(sys.argv[1], sys.argv[2])
