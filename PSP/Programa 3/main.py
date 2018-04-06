#!/usr/bin/env python

from os import path
from os import name
from os import system
from ClaseArchivo import archivos
from ClaseArchivo import editar
from RegresionLineal import RL

def clear():
    if name == 'nt':
        system("cls")
    elif name == 'posix':
        system("clear")

if __name__ == '__main__':

	fileExists = False
	opc = False
	lista1, lista2 = [], []
	listaRL = []
	b0, b1, r, r2, p = [], [], [], [], []
	clear()

	while fileExists != True:

		nombreArchivo = raw_input("Ingrese el nombre del archivo: ")

		if path.isfile(nombreArchivo) == True:
			fileExists = True

			#Se abre el archivo
			archivo = archivos(nombreArchivo)
			file = archivo.abrir()
			manArchivos = editar(file)

			lines = manArchivos.lectura()		#se lee todo el doc en lineas
			line = lines.split("\n")			#se separa por lineas

			regresion = RL(line)
			regresion.separadorColumnas()

			clear()
			print "Archivo seleccionado: " + nombreArchivo + "\n-------------------------------------"

			while opc != True:
				num1 = int(raw_input("\nIngrese el numero de la columna deseada: "))
				lista1 = regresion.listas(num1)
				media1 = regresion.mediaListas(lista1)

				num2 = int(raw_input("Ingrese el numero de la columna deseada: "))
				lista2 = regresion.listas(num2)
				media2 = regresion.mediaListas(lista2)

				listaRL = regresion.regresionLinear(lista1, lista2, media1, media2)

				b0.append(listaRL[0])
				b1.append(listaRL[1])
				r.append(listaRL[2])
				r2.append(listaRL[3])
				p.append(listaRL[4])

				q = raw_input("Desea otra consulta?  y/n : ")

				if q is 'n': opc = True
				else: opc = False

			clear()
			print ("\n\nTest\tb0\t b1\t r\t r2\t p\n------------------------------------------------")
			
			for x in range(len(b0)):
				print "Test " + str(x+1) + "\t{0: .3f}".format(b0[x]) + "\t{0: .3f}".format(b1[x]) + "\t{0: .3f}".format(r[x]) + "\t{0: .3f}".format(r2[x]) + "\t{0: .3f}".format(p[x])

			print "\n\n"

		else:
			print "El archivo " + nombreArchivo + " no existe, intente de nuevo.\n"
			fileExists = False