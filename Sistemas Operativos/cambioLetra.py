#!/usr/bin/python

file= open("Archivo.txt", "r")
fileRead= file.read()

print fileRead

cambiar= raw_input("Que letra vas a modificar: ")
letra= raw_input("Ingresa la nueva letra: ")

opc= int(raw_input("Deseas cambiar un numero determinado?\tSi[1] No[0] : "))
if opc is 1:
	cuantas= int(raw_input("Cuantas veces vas a cambiarlo? : "))
	new= fileRead.replace(cambiar, letra, cuantas)
else:
	new= fileRead.replace(cambiar, letra)

file= open("Archivo.txt", "w")
file.write(new)
file.close()

