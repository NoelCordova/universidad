#!/usr/bin/env python

import os

def clear():
    if os.name == 'nt':
        os.system("cls")
    elif os.name == 'posix':
        os.system("clear")

'''
	FOR:
	Hacer un prorgrama que dado como datos los sueldos de 10 empleados de una empresa, obtenga el total de nomina de la misma.

'''
def programa_A():
	nomina = 0.0
	for i in range(1, 11):
		sueldo = float(raw_input("Ingrese el sueldo del empleado " + str(i) + "  : "))
		nomina = nomina + sueldo

	return nomina


'''
	WHILE
	Escribir un prorgama que dado N cantidad de numero enteros a capturar, cuente cuantos numeros ceros se han ingresado.
'''
def programa_B():
	i = 1
	contCeros = 0
	numeros = int(raw_input("Ingrese la cantidad de numeros a capturar: "))

	while i <= numeros:
		n = int(raw_input("Ingrese el numero " + str(i) + " : "))

		if n == 0:
			contCeros = contCeros + 1
			i = i + 1
		else:
			i = i + 1

	if contCeros != 0:
		return "Hay " + str(contCeros) + " ceros." 
	else:
		return "No hay ceros."


'''
	FOR
	Hacer un programa que dado como datos 270 numero enteros, (del 1 al 270), obtenga la suma de los numeros impares
	y el promedio de los numeros pares
'''
def programa_C():
	sumaImpares = 0
	sumaPares = 0
	totalPares = 0

	for i in range(1, 271):
		if i%2 == 0:
			sumaPares = sumaPares + i
			totalPares = totalPares + 1
		elif i%2 == 1:
			sumaImpares = sumaImpares + i

	sumaPares = sumaPares / totalPares

	return "Suma impares: " + str(sumaImpares) + ", promedio pares: " + str(sumaPares)


'''
	WHILE
	Escriba un programa que obtenga la suma e imprima los terminos de la siguiente serie: 2, 5, 7, 10, 12, 15, 17, ..., 1 800
'''
def programa_D():
	status = False
	contador = 0
	suma = 0
	
	while contador < 1800:

		if status == False:
			contador = contador + 2
			status = True

		elif status == True:
			contador = contador + 3
			status = False

		suma = suma + contador

	return "El resultado de la suma es: " + str(suma) + "; es una serie que va de 2 y 3."


'''
	FOR
	Hacer un programa que lea un numero entero N y calcule el resultado de la siguiente serie: 1 - 1/2 + 1/3 - 1/4 + ... +- 1/N
'''
def programa_E():
	suma = 0.0
	status = False

	N = int(raw_input("Ingrese un numero: "))

	for i in range(1, N+1):
		if status == False:
			suma = suma + (1.0 / i)
			status = True
		else:
			suma = suma - (1.0 / i)
			status = False

	return "El resultado de la suma es: " + str("%.2f" % suma)

'''
	WHILE
	Construya un programa tal que dado N numeros enteros como dato, calcule el mayor y el menos de estos numeros.
'''
def programa_F():
	numMayor = 0.0
	numMenor = 0.0
	i = 1

	N = int(raw_input("Ingrese el total de numeros a calcular: "))
	print "\n"

	while i <= N:
		num = float(raw_input("Ingrese un nuemro: "))

		if i is 1:
			numMayor = num
			numMenor = num
		else:
			if num > numMayor:
				numMayor = num
			if num < numMenor:
				numMenor = num

		i = i + 1

	if numMayor is numMenor:
		return "Num mayor y Num menor son iguales: " + str(numMayor)
	else:
		return "Num mayor: " + str(numMayor) + ', Num menor: ' + str(numMenor)


'''
	FOR
	Un vendedor ha hecho una serie de ventas y desea conocer aquellas de $200 o menos, las mayores a $200
	pero inferiores a $400, y el numero de ventas de $400 o superiores de tal cantidad. Al inicio de capturara un numero
	que indicara el numero de ventas realizadas. Dentro del ciclo se solicitara el monto de la venta.
'''
def programa_G():
	menos = 0
	entre = 0
	mas = 0

	N = int(raw_input("Ingrese el numero de ventas: "))

	for i in range(1, N+1):
		venta = int(raw_input("Ingrese el monto de la venta: "))

		if venta <= 200:
			menos = menos + 1
		elif venta >=201 and venta <=400:
			entre = entre + 1
		elif venta >= 401:
			mas = mas + 1

	return	(
				"\nNum de ventas <= 200: " + str(menos) + "\n" +
				"Num de ventas entre 201 a 400: " + str(entre) + "\n" +
				"Num de ventas >=401: " + str(mas)
			)


'''
	WHILE
	Hacer un programa que calcule el termino ingresado por el usuario de la secuencia Fibonacci.
	Recuerde que los dos primeros numeros de la serie son 0 y 1, el resto se calcula como la suma de los dos numeros
	inmediatos que le preceden.
	Ejemplo de la serie: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ..., 
'''
def programa_H():
	numA = 0
	numB = 1
	
	limite = int(raw_input("Ingrese un limite para la serie: "))

	while numA + numB <= limite:
		numC = numA + numB
		numA = numB
		numB = numC

	return "Limite de la serie " + str(limite) + ", valor obtenido: " + str(numC)


'''
	FOR
	Escribir un programa que solicite al usuario un numero entero cualquiera.
	El programa debera mostrar como salida si el numero es primo o no.
'''
def programa_I():
	a = 0
	num = int(raw_input("Ingrese un numero: "))

	for i in range(1, num+1):
		if(num%i == 0):
  			a=a+1

	if(a!=2):
 		return "No es primo"
	else:
 		return "Si es primo"