#!/usr/bin/env python3
import os
os.system("clear")

archivo= input("Ingrese el nombre del archivo que desea procesar: ")
print("\nNombre: ", archivo)
print("Tamaño: ", os.path.getsize(archivo), "bytes")
print("\nVista preliminar del archivo\n---------------------------------\n")

file= open(archivo, "r")
print(file.read())
print("\n---------------------------------")

tamArch= os.path.getsize(archivo)
numPartes= int(input("En cuantas partes desea dividir el archivo? : "))
tamPartes= tamArch/numPartes
print("Tamaño de las partes divididas: ", tamPartes)

while archivo != NULL:
	print("Si")
	
else:
	print("No")	
	
	

file.close()
