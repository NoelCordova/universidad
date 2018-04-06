'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Calculo de los valores
                            'z' de una lista de valores

	Fecha: 2 de Marzo del 2017

'''
list = []
list2 = []
from math import sqrt

def llenarLista(lista):
	nIsOk = True

	while nIsOk is True:
		n = int(raw_input('Ingrese el tamanio de la lista: '))

		if n >= 4 and n <= 15:
			nIsOk = False

			for x in range(n):
				datoIsOk = True

				while datoIsOk is True:
					dato = int(raw_input("Ingrese un dato a la lista: "))

					if dato >= 5 and dato <= 300:
						datoIsOk = False
					else:
						print 'Error, el dato debe ser entre 5 y 300\n'
						datoIsOk = True

				lista.append(dato)
		else:
			nIsOk = True
			print 'Error, la lista debe ser entre 4 y 15\n'
            
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

	des = sqrt(suma / (len(lista)-1))
	return des

def puntajeEstandar(lista, lista2):
    for x in range(len(lista)):
        pe = ((lista[x] - media(lista)) / desviacion(lista))
        lista2.append(pe)
        
llenarLista(list)
puntajeEstandar(list, list2)

print list
print list2