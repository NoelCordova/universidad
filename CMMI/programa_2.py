'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Derivacion estandar

	Fecha: 23 de Febrero del 2017

'''
import math
list = []


def llenarLista(lista):
	nIsOk = True

	while nIsOk is True:
		n = int(raw_input('Ingrese el tamanio de la lista: '))

		if n >= 3 and n <= 15:
			nIsOk = False

			for x in range(n):
				datoIsOk = True

				while datoIsOk is True:
					dato = int(raw_input("Ingrese un dato a la lista: "))

					if dato >= 5 and dato <= 100:
						datoIsOk = False
					else:
						print 'Error, el dato debe ser entre 5 y 100'
						datoIsOk = True

				lista.append(dato)
		else:
			nIsOk = True
			print 'Error, la lista debe ser entre 3 y 15'

def media(lista):
	suma = 0.0
	for x in range(len(lista)):
		suma+= lista[x]

	prom = suma / len(lista)
	return prom

def desviacion(lista):
	suma = 0.0
	for x in range(len(lista)):
		suma+= (lista[x] - media(lista))**2

	des = math.sqrt(suma / (len(lista)-1))
	return des


llenarLista(list)
print desviacion(list)