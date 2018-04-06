'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Limite superior e inferior

	Fecha: 24 de Febrero del 2017

'''
import math
list = []

def llenarLista(lista):
	nIsOk = True
	npIsOk = True

	while nIsOk is True:
		n = int(raw_input('Ingrese el numero de programadores: '))

		if n >= 3 and n <= 16:
			nIsOk = False

			while npIsOk is True:
				numProgramas = int(raw_input('Ingrese el numero de programas: '))

				if numProgramas >= 3 and numProgramas <= 5:
					npIsOk = False

					for x in range(n):
						lista.append([])
						print '\n'

						for y in range(numProgramas):
							LOC = int(raw_input("Programador " + str(x+1) + ": LOC del programa " + str(y+1) + ": "))
							lista[x].append(LOC)
				else:
					npIsOk = True
					print 'Error, el numero de programas debe ser entre 3 y 5\n'
		else:
			nIsOk = True
			print 'Error, el numero de programadores debe ser entre 3 y 16\n'

def media(lista):
	suma = 0.0
	for x in range(len(lista)):
		suma+= lista[x]
	prom = suma / len(lista)
	return prom

def granMedia(lista):
	suma = 0.0
	for x in range(len(lista)):
		suma+= media(lista[x])

	prom = suma / len(lista)
	return prom

def desviacion(lista):
	suma = 0.0
	for x in range(len(lista)):
		suma+= (lista[x] - media(lista))**2

	des = math.sqrt(suma / (len(lista)-1))
	return des

def limiteSuperior(lista):
	listaDesviacion = []
	n = len(lista) * len(lista[0])

	for x in range(len(lista)):
		for y in range(len(lista[x])):
			listaDesviacion.append(lista[x][y])

	return (granMedia(lista) + 3*(desviacion(listaDesviacion) / math.sqrt(n)))
	
def limiteInferior(lista):
	listaDesviacion = []
	n = len(lista) * len(lista[0])

	for x in range(len(lista)):
		for y in range(len(lista[x])):
			listaDesviacion.append(lista[x][y])

	return (granMedia(lista) - 3*(desviacion(listaDesviacion) / math.sqrt(n)))

llenarLista(list)
print limiteSuperior(list)
print limiteInferior(list)