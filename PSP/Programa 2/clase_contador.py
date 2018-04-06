#!/usr/bin/env python

class contadorLineas():
	def __init__(self, numLineas, line):
		self.numLineas = numLineas
		self.line = line
		self.nombreClass = []

	def contador(self):

		conEspBlanco = 0
		conLineas = 0
		conDef = 0
		conClass = 0
		conComent = 0
		deff = False
		clas = False
		numDef = 0
		numCLas = 0
		objetosInClass = 0

		for x in range(self.numLineas):
			list = []
			tabulador = False
			tabTotal = 0
			cadena = self.line[x]
			newCadena = cadena.split("\t")

			for y in range(len(newCadena)):
				if newCadena[y] == '':
					tabulador = True
					tabTotal = tabTotal + 1
				else:
					tabulador = False

					list.append(newCadena[y])

					cadenaLinea = list[0]
					newCadenaLinea = cadenaLinea.split(" ")

					if newCadenaLinea[0] == 'def':
						deff = True
						numDef = numDef + 1

						if tabTotal == 0:
							conDef = conDef + 1

						elif clas == True:
							conClass = conClass + 1
							objetosInClass = objetosInClass + 1


					elif newCadenaLinea[0] == "\r":
						conEspBlanco = conEspBlanco + 1

					elif newCadenaLinea[0] == 'class':
						conClass = conClass + 1
						clas = True
						numCLas = numCLas + 1

					elif newCadenaLinea[0] == '#':
						conComent = conComent + 1

					else:
						if clas == True and tabTotal != 0 and deff == True:
							conClass = conClass + 1

						elif deff == True and tabTotal != 0:
							conDef = conDef + 1

						else:
							conLineas = conLineas + 1
							deff = False
							clas = False

		tamanoTotal = (conClass + conDef + conLineas + conEspBlanco + conComent)
		print("\n")
		print('{:25}{:25}{:25}{:25}{:25}{:25}'.format('Tamano Clases', 'Tamano Def', 'Instrucciones', 'Espacios en Blanco', 'Comentarios', 'Tamano Total'))
		print('{:13}{:22}{:27}{:30}{:19}{:26}'.format(conClass, conDef, conLineas, conEspBlanco, conComent, tamanoTotal))
		print ("\n")
