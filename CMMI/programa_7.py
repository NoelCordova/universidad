'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Calculo del error
                            estandar de estimacion
                            

	Fecha: 09 de Marzo del 2017

'''
list = []
from math import sqrt

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


def mediaLOC(lista):                   #Funcion reutilizada
	suma = 0.0
	for x in range(len(lista)):
		suma+= lista[x][0]            #Modificada
        
	prom = suma / len(lista)
	return prom


def mediaEsfuerzo(lista):           #Funcion reutilizada
    suma = 0.0
    for x in range(len(lista)):
        suma+= lista[x][1]          #modificada
        
    prom = suma / len(lista)
    return prom
        
    
def regresionLineal(lista):
    lista2 = []
    lista3 = []
    lista4 = []
    lista5 = []
    sumaMult = 0.0
    sumaResXC = 0.0
    sumaY = 0.0
    
    for x in range(len(lista)):
        resX = lista[x][0] - mediaLOC(lista)
        resY = lista[x][1] - mediaEsfuerzo(lista)
        
        multiplicacion = resX * resY
        lista2.append(multiplicacion)
        
        resXCuadrado = (resX)**2
        lista3.append(resXCuadrado)
        
    for x in range(len(lista)):
        sumaMult+= lista2[x]
        sumaResXC+= lista3[x]
        
    b1 = sumaMult / sumaResXC
    b0 = mediaEsfuerzo(lista) - b1 * mediaLOC(lista)
    
    #return str(b0) + " + " + str(b1)
    #return b0 + b1
    
    for x in range(len(lista)):
        y = b0 + (b1 * lista[x][0])
        lista4.append(y)
        
    for x in range(len(lista)):
        res = (lista[x][1] - lista4[x])
        newRes = (res)**2
        lista5.append(newRes)
        
    for x in range(len(lista)):
        sumaY+= lista5[x]
        
    return sqrt(sumaY / (len(lista)-2))
    
    
llenarLista(list)
print regresionLineal(list)