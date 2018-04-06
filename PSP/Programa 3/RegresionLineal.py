#!/usr/bin/env python

from math import sqrt

class RL():
	def __init__(self, line):
		self.line = line
		self.col1, self.col2, self.col3, self.col4, self.col5 = [], [], [], [], []


	def separadorColumnas(self):
		cont = 1

		for x in range(len(self.line)):
			cadena = self.line[x]
			newCad = cadena.split("|")

			for y in range(len(newCad)-1):
				if cont is 1:
					self.col1.append(newCad[y])
					cont = cont + 1

				elif cont is 2:
					self.col2.append(newCad[y])
					cont = cont + 1

				elif cont is 3:
					self.col3.append(newCad[y])
					cont = cont + 1

				elif cont is 4:
					self.col4.append(newCad[y])
					cont = cont + 1

				elif cont is 5:
					self.col5.append(newCad[y])
					cont = 1


	def listas(self, num):
		if num is 1:
			lista = self.col1
		elif num is 2:
			lista = self.col2
		elif num is 3:
			lista = self.col3
		elif num is 4:
			lista = self.col4
		elif num is 5:
			lista = self.col5

		return lista


	def mediaListas(self, lista):
		suma = 0.0

		for x in range(len(lista)):
			suma+= float(lista[x])

		prom = suma / len(lista)
		return prom


	def regresionLinear(self, lista1, lista2, media1, media2):
		listaRes = []
		#Lista1 toma el valor de X, lista2 toma el valor de Y.
		SumXCuad = 0.0	#sumatoroia de X cuadrada
		SumXY = 0.0		#sumatoria de X*Y
		SumYCuad = 0.0	#sumatoria de Y cuadrada

		for x in range(len(lista1)):
			valX = float(lista1[x])	#Valor de X
			valY = float(lista2[x])	#Valor de Y

			SumXCuad = SumXCuad + (valX**2)
			SumXY = SumXY + (valX * valY)
			SumYCuad = SumYCuad + (valY**2)

		b1 = ((SumXY)-(len(lista1)*media1*media2))/((SumXCuad)-(len(lista1)*(media1**2)))
		b0 = ((media2)-(b1*media1))
		r = (len(lista1)*(SumXY)-(media1*len(lista1))*(media2*len(lista2)))/sqrt((len(lista1)*(SumXCuad)-(media1*len(lista1))**2)*(len(lista1)*(SumYCuad)-(media2*len(lista2))**2))
		r2 = (r**2)
		p = (b0+b1*386)

		listaRes.append(b0)
		listaRes.append(b1)
		listaRes.append(r)
		listaRes.append(r2)
		listaRes.append(p)

		return listaRes