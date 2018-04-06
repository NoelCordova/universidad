'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Generacion de valores 'y' 
                            con base en la ecuacion de
                            distribucion normal. 

	Fecha: 08 de Marzo del 2017

'''
import random
import math
list = []
list2 = []

def llenarLista(lista):
	nIsOk = True

	while nIsOk is True:
		n = int(raw_input('Ingrese el tamanio de la lista: '))

		if n >= 50 and n <= 100:
			nIsOk = False

			for x in range(n):
				datoIsOk = True
				lista.append(random.randint(40, 300))
		else:
			nIsOk = True
			print 'Error, la lista debe ser entre 50 y 100\n'
            

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


def distribucionNormal(lista1, lista2):
    for x in range(len(lista1)):
        distribucion = (1/(math.sqrt(2*math.pi*desviacion(lista1))))*e(-math.pow((x-media(lista1)),2)/(2*math.pow(desviacion(lista1),2)))
        lista2.append(distribucion)
        
def e(x=1):
    return math.pow(math.e, x)

llenarLista(list)
distribucionNormal(list, list2)

print '\nResultado: \n'

for x in range(len(list)):
    print 'Numero: ' + str(list[x]) + ': ' + str(list2[x])