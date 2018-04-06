#!/usr/bin/env python

class archivos():
	def __init__(self, nombreArchivo):
		self.nombreArchivo = nombreArchivo

	#Funcion para abrir un archivo
	def abrir(self):
		file = open(self.nombreArchivo, "r")
		return file


class editar():
	def __init__(self, archivo):
		self.archivo = archivo
		#self.leer.read(archivo)

	#Funcion para cerrar un archivo
	def cerrar(self):
		return self.archivo.close()

	#Funcion para tener el tamano del archivo en lineas
	def lenArchivo(self):
		return len(self.archivo.readlines())

	#Funcion para leer el archivo completo
	def lectura(self):
		return self.archivo.read()