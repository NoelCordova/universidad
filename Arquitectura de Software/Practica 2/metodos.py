#!/usr/bin/env python

import os

def clear():
    if os.name == 'nt':
        os.system("cls")
    elif os.name == 'posix':
        os.system("clear")


'''
	El numero de sonidos emitidos por un grillo en un minuto, es una funcion de la temperatura. 
	Como resultado de esto, es posible determinar el nivel de la temperatura haciendo uso de un grillito como termometro.
	La formula para la funcion es: T = N / 4 + 40
	Donde T representa la temperatura en grados Farenheit y N el numero de sonidos emitidos por minuto. 
	N  es la variable que se le pedira al usuario.
'''
def programa_A():
	N = int(raw_input("Ingrese el numero de sonidos emitidos: "))

	return (N / 4 + 40)


'''
	Realice un programa tal que dado como datos los valores enteros P y Q, determine si los mismo satisfacen la siguiente expresion:
	P**3 + Q**4 - 2 * P**2 > 680
	En caso afirmativo, debe imprimir los valores de P y Q, en caso contrario debera mostrar un mensaje
	de que los valores no cumplen el criterio.
'''
def programa_B():
	P = int(raw_input("Ingrese el dato P: "))
	Q = int(raw_input("Ingrese el dato Q: "))

	if (P**3 + Q**4 - 2 * P**2) > 680:
		return ('P= ' + str(P) + ", Q= " + str(Q))

	else:
		return 'Los valores no son mayores a 680.'


'''
	Construir un programa tal que solicite al usuario el no. de control y 5 calificaciones de un alumno,
	imprima el no. de control, el promedio y la palabra aprobado si el alumno tiene un promedio mayor o igual a 7,
	y la palabra no aprobado, en caso contrario.
'''
def programa_C():
	numControl = raw_input("Ingrese el numero de control: ")
	suma = 0.0
	for i in range(1, 6):
		calificacion = float(raw_input("Ingrese la calificacion num " + str(i) + ': '))
		suma = suma + calificacion

	promedio = suma / 5

	if promedio >= 7:
		return ('\nno. control ' + numControl + ': ' + str(promedio) + '\nAprobado')
	else:
		return ('\nno. control ' + numControl + ': ' + str(promedio) + '\nNo aprobado')


'''
	Realizar un diagrama que lea un numero entero y determine e imprima si el mismo es positivo, negativo o nulo.
'''
def programa_D():
	num = raw_input("Ingrese un numero: ")

	if float(num)%1 == 0:
		if float(num) < 0:
			return ("Negativo")
		elif float(num) > 0:
			return ("Positivo")
	else:
		return ("Nulo")


'''
	Un programa que lea un numero y determine si el numero es par, impar o nulo.
'''
def programa_E():
	num = raw_input("Ingrese un numero: ")

	if float(num)%1 == 0:
		if float(num)%2 == 0:
			return ("Numero par")
		elif float(num)%2 == 1:
			return ("Numero impar")
	else:
		return ("Nulo")


'''
	 Un programa que lea tres numeros enteros y determine si los mismos estan en orden creciente.
'''
def programa_F():
	num1 = int(raw_input("Ingrese un numero: "))
	num2 = int(raw_input("Ingrese un numero: "))
	num3 = int(raw_input("Ingrese un numero: "))

	if (num1 < num2) and (num1 < num3) and (num2 < num3):
		return ("Orden creciente")
	else:
		return ("Nulo")


'''
	En una tienda efectuan descuento a los clientes dependiendo del monto de la compra.
	El descuento se efectua en base al siguiente criterio:
	1. Si el monto es menor que $500 - no hay descuento.
	2. Si el monto esta comprendido entre $500 y $1 000 inclusive - 5% de descuento.
	3. Si el monto esta comprendido entre $1 000 y $7 000 inclusive - 11% de descuento.
	4. Si el monto esta comprendido entre $7 000 y $15 000 inclusive - 18% de descuento.
	5. Si el monto es mayor a $15 000 - 25% de descuento. 
'''
def programa_G():
	compra = float(raw_input("Ingrese el monto de la compra: "))

	if compra < 500:
		return compra
	elif compra >= 500 and compra < 1000:
		return compra - (compra * .05)
	elif compra >= 1000 and compra < 7000:
		return compra - (compra * .11)
	elif compra >= 7000 and compra < 15000:
		return compra - (compra * .18)
	elif compra >= 15000:
		return compra - (compra * .25)


'''
	Dado tres numero reales, identificar cual es mayor, el menor o si son iguales.
'''
def programa_H():
	numMayor = 0.0
	numMenor = 0.0
	for i in range(1, 4):
		num = float(raw_input("Ingrese un nuemro: "))

		if i is 1:
			numMayor = num
			numMenor = num
		else:
			if num > numMayor:
				numMayor = num
			if num < numMenor:
				numMenor = num

	if numMayor is numMenor:
		return "Num mayor y Num menor son iguales: " + str(numMayor)
	else:
		return "Num mayor: " + str(numMayor) + ', Num menor: ' + str(numMenor)


'''
	El costo de las llamadas telefonicas internacionales depende de la zona geografica en donde se ubique el pais destino
	y del numero de minutos hablados. En la siguiente tabla se presenta el costo del minuto por zona.
	A cada zona se la ha asociado una clave:

		CLAVE 	Destino 			Precio minuto 
		12 		America del Norte 	2.0 
		15 		America Central 	2.2 
		18 		America del Sur 	4.5
		19 		Europa 				3.5
		23 		Asia 				6.0
		25 		Africa 				6.0 
		29 		Oceania 			5.0
	
	Construya un programa que le permita calcular e imprimir el costo total de una llamada.
'''
def programa_I():
	claves = [12, 15, 18, 19, 23, 25, 29]
	precio = [2.0, 2.2, 4.5, 3.5, 6.0, 6.0, 5.0]

	pais = int(raw_input("Ingrese la clave del pais: "))
	minutos = int(raw_input("Ingrese los minutos hablados: "))

	if pais in claves:
		for i in range(len(claves)):
			if claves[i] is pais:
				return 'Costo total de llamada: ' + str(minutos * precio[i])
	else:
		return 'Error, la clave del pais no existe.'


'''
	Escriba un programa que permita calcular lo que hay que pagarle a un trabajador teniendo en cuenta su sueldo y las
	horas extras trabajadas. Para el pago de horas extras, se toma en cuenta la categoria del trabajador.

		Categoria 		Precio hora extra
			1 				$30.0
			2 				$38.0
			3 				$50.0
			4 				$70.0

	Cada trabajador puede tener como maximo 30 horas extras, si tienen mas solo se le pagaran 30.
	A los trabajadores con categoria mayor a 4 no se le deben pagar horas extras.
'''
def programa_J():
	categoria = int(raw_input("Ingrese su categoria: "))
	sueldo = int(raw_input("Ingrese su sueldo base: "))
	horas = int(raw_input("Ingrese el numero de horas laboradas: "))

	if categoria is 1:
		if horas <= 30:
			return sueldo + (horas * 30)
		else:
			return sueldo + (30 * 30)
	elif categoria is 2:
		if horas <= 30:
			return sueldo + (horas * 38)
		else:
			return sueldo + (30 * 38)
	elif categoria is 3:
		if horas <= 30:
			return sueldo + (horas * 50)
		else:
			return sueldo + (30 * 50)
	elif categoria is 4:
		if horas <= 30:
			return sueldo + (horas * 70)
		else:
			return sueldo + (30 * 70)
	else:
		return sueldo