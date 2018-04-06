#!/usr/bin/env python3

import os

listNombre= []
listTamano= []
st=0
while 1:
	conInicial= 0
	conFinal= 0
	
	os.system("clear")
	
	opc= int(input("Que opcion desea hacer?\n1) Agregar procesos\n2) Eliminar proceso\n3) Mostrar Procesos\n4) Desfragmentar\n5) Salir\nOpcion [ ]\b\b"))
	if opc is 1:
		os.system("clear")
		nombre= input("Nombre del proceso: ")
		listNombre.append(nombre)
		tamano= int(input("Tamano del proceso: "))
		listTamano.append(tamano)
		st+=tamano
		
	elif opc is 2:
		os.system("clear")
		
		while True:
			try:
				nombre= input("Buscar: ")
				ubicacion= (listNombre.index(nombre))
				print ("La ubicacion del proceso ['",nombre,"'] es: ", ubicacion)
		
				print("Desea eliminar todo el contenido de la ubicacion", ubicacion, "?: ", end='')
				newOpc= int(input())
				if newOpc is 1:
					listNombre[ubicacion]= " "
				break
			except ValueError:
				print("Oops! No era válido. Intente nuevamente...\nO quieres volver a ver la lista? :", end='')
				newOpc= int(input())
				if newOpc is 1:
					print (listNombre)
					print (listTamano) 
				else:
					break
		
	elif opc is 3:
		os.system("clear")
		print (listNombre)
		print (listTamano)
		input("Press enter to continue...")
		
	elif opc is 4:
		d=0
		for c in range(len(listNombre)):
			if listNombre[c]==" ":
				d+=1
		for c2 in range(d):
				v= listNombre.index(" ")
				del listNombre[v]
				del listTamano[v]	
				
		input("Desfragmentado :)")
		
	else:
		os.system("clear")
		print("\nAdios :)\n")
		break
