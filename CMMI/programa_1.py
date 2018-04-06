'''

	Instituto Tecnologico Nacional de Mexico
	Jose Mario Molina Pasquel y Henriquez

	Desarrollador: Edgar Noel Espino Cordova
	Funcion del Programa: 	Validar una cadena ingresada
							por el usuario validando que
							sean caracteres alfabeticos

	Fecha: 17 de Febrero del 2017

'''

cadena = raw_input('Ingresa tu nombre: ').lower()

#Leer caracter por caracter la variable cadena
for x in range(len(cadena)):

	#Validar caracteres alfabeticos
	if cadena[x].isalpha() is True:
		cadenaIsOk = True
	#Validar espacios
	elif cadena[x].isspace() is True:
		cadenaIsOk = True
	#Se ignoran los caracteres basura
	else:
		cadenaIsOk = False
		break
		
#Comprobacion de cadena
if cadenaIsOk is True:
	print cadena + " estas en el curso de PSP"
else:
	print 'Cadena no valida'
