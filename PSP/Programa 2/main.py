#!/usr/bin/env python

from classes import archivos
from classes import editar
from clase_contador import contadorLineas
from os import path

if __name__ == '__main__':

	fileExists = False

	while fileExists != True:

		nombreArchivo = raw_input("Ingrese el nombre del archivo: ")

		if path.isfile(nombreArchivo) == True:
			fileExists = True


			#Se abre el archivo
			archivo = archivos(nombreArchivo)
			file = archivo.abrir()

			#Instancia para clase editar
			manArchivos = editar(file)				#manArchivos = manipuacion de archivos
			numLineas = manArchivos.lenArchivo()	#Tamano del archivo
			manArchivos.cerrar()					#Se cierra el archivo

			#Se vuelve a abrir el archivo con otra instancia de editar.
			archivo = archivos(nombreArchivo)
			file = archivo.abrir()
			manArchivos = editar(file)

			lines = manArchivos.lectura()		#se lee todo el doc en lineas
			line = lines.split("\n")			#se separa por lineas

			contLineas = contadorLineas(numLineas, line)
			contLineas.contador()

		else:
			print "El archivo " + nombreArchivo + " no existe, intente de nuevo.\n"
			fileExists = False
