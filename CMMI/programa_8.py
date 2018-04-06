'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Calculo del coeficiente
							de determinacion

	Fecha: 16 de Marzo del 2017

'''
list = []
from math import sqrt

#funcion reutilizada
def llenarLista(lista):
    n = int(raw_input('Ingrese el tamano de la lista: '))
    print '\n'

    for x in range(n):
        lista.append([])
        LDC=input("LOC programa " + str(x+1) + ": ")
        lista[x].append(LDC)
        esfuerzo=input("Esfuerzo programa " + str(x+1) + ": ")
        lista[x].append(esfuerzo)
        print '\n'

#funcion reutilizada
def mediaLOC(lista):
	suma = 0.0
	for x in range(len(lista)):
		suma+= lista[x][0]

	prom = suma / len(lista)
	return prom

#funcion reutilizada
def mediaEsfuerzo(lista):
    suma = 0.0
    for x in range(len(lista)):
        suma+= lista[x][1]

    prom = suma / len(lista)
    return prom

#funcion reutilizada
def regresionLineal(lista):
    sumaMult = 0.0
    sumaResXC = 0.0
    sumaVarTotal = 0.0			#Linea agregada
    sumaVarNoExp = 0.0			#linea agreagda
    
    for x in range(len(lista)):
        resX = lista[x][0] - mediaLOC(lista)
        resY = lista[x][1] - mediaEsfuerzo(lista)

        multiplicacion = resX * resY
        sumaMult+= multiplicacion

        resXCuadrado = (resX)**2
        sumaResXC+= resXCuadrado

        variacionTotal = resY**2		#liena agregada
        sumaVarTotal+= variacionTotal	#linea agregada

    b1 = sumaMult / sumaResXC
    b0 = mediaEsfuerzo(lista) - b1 * mediaLOC(lista)

    #ciclo agregado
    for x in range(len(lista)):
        e = b0 + (b1 * lista[x][0])
        res2 = lista[x][1] - e
        variacionNoExp = res2**2

        sumaVarNoExp+= variacionNoExp

    return round(((sumaVarTotal - sumaVarNoExp)/sumaVarTotal)*100, 2) #modificada


llenarLista(list)
print regresionLineal(list)
