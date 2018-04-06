a = 3
b = 1

def saludo():
	print 'Hola terricola.'

class calculadora():
	def suma():
		return a + b

	def resta():
		# Leer caracter por caracter la variable cadena
		for x in range(len(cadena)):

		# Validar caracteres alfabeticos
		if cadena[x].isalpha() is True:
			cadenaIsOk = True
		# Validar espacios
		elif cadena[x].isspace() is True:
			cadenaIsOk = True
		# Se ignoran los caracteres basura
		else:
			cadenaIsOk = False
			break

cadena = raw_input('Ingresa tu nombre: ').lower()

# Comprobacion de cadena
if cadenaIsOk is True:
	print cadena + " estas en el curso de PSP"
else:
	print 'Cadena no valida'