'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Calcular el tamanio de una muestra
                            para estimar una media.

	Fecha: 03 de Marzo del 2017

'''
list = []
from math import sqrt

def llenarLista(lista):
	nIsOk = True

	while nIsOk is True:
		n = int(raw_input('Ingrese el tamanio de la lista: '))

		if n >= 11 and n <= 15:
			nIsOk = False

			for x in range(n):
				datoIsOk = True

				while datoIsOk is True:
					dato = int(raw_input("Ingrese un dato a la lista: "))

					if dato >= 3000 and dato <= 15000:
						datoIsOk = False
					else:
						print 'Error, el dato debe ser entre 3000 y 15000\n'
						datoIsOk = True

				lista.append(dato)
		else:
			nIsOk = True
			print 'Error, la lista debe ser entre 11 y 15\n'
            
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

def estimacionMedia(lista):
    ncIsOk = True
    
    while ncIsOk is True:
        nivelConfianza = float(raw_input('\nIngrese el nivel de confianza: '))
        
        if nivelConfianza >= -3 and nivelConfianza <= 3:
            ncIsOk = False
            
            margenError = float(raw_input('Ingrese el margen de error: '))
            return int(round((((nivelConfianza)*(desviacion(lista))) / margenError)**2))
        else:
            ncIsOk = True
            print 'Error, el valor de confianza debe estar en el rango de -3 y 3\n'
            
            
llenarLista(list)
print 'El calculo de la muestra es: ' + str(estimacionMedia(list))