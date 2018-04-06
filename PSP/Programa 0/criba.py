#!/usr/bin/env python
lista = []
status = False
dato = 0
n = 0

#metodo para llenar la lista
def LlenadoLista(list, num):
	for ni in range(2, num+1):
		list.append(ni)

#metodo para algoritmo
def Criba(list):
	for x in range(n-1):
		numActual = list[x]

		#se toma un numero diferente a cero para el algoritmo
		if numActual != 0:
			for y in range(x+1, n-1):
				#se remplazan los divisores en la lista
				if Divisor(list[y], numActual) is 1:
					list[y] = 0

			#se escribe el caracter diferente a cero en archivo .txt
			file.write(str(list[x]) + ", ")

#metodo para conocer los divisores
def Divisor(num1, num2):
	if num1 % num2 is 0:
		return 1	#Si son multiplos regresa 1 de lo contrario 0
	else:
		return 0

if __name__ == '__main__':
	while status != True:
		dato = int(raw_input('Ingrese un numero: '))

		if dato >= 2 and dato <= 100:
			n = dato
			status = True
		else:
			print '\nError, el numero ingresado no es valido.'
			print '1 < n <= 100\n'
			status = False

	nameFile = raw_input('\nDetermine el nombre del archivo respuesta. \nej. res.txt: ')
	file = open(nameFile, "wb")

	LlenadoLista(lista, n)
	Criba(lista)

	print 'Ok, archivo creado.\n'

	file.seek(-2, 2)
	file.write(".")
	file.close()
