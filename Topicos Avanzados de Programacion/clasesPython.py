#!/usr/bin/env python

class una_clase:
	def __init__(self):
		print "\nEste es el constructor\n"

un_objeto= una_clase()


class otra_clase:

	def __init__(self, saludo, numero):
		print saludo, "el numero es", numero, "\n"	

otro_objeto= otra_clase("Hola", 5)
