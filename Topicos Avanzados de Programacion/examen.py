#!/usr/bin/env python


file= open("entrada.txt", "r")
file2= open("salida.txt", "w")
fileRead= file.read()
file.close()

contador= 0

while True:
	num= fileRead.find(" ", contador)
	numerador= int(fileRead[contador:num])
	contador= num
	
	num= fileRead.find("\n", num)
	denominador= int(fileRead[contador:num])
	contador= num+1
	
	if numerador is 0 and denominador is 0:
		break
		
	elif denominador < numerador and denominador > 0:
		write= str(numerador) + "/" + str(denominador) + "=[" + str(numerador//denominador)
		numerador%=denominador

		while numerador > 0:
			if denominador%numerador is 0:
				write+=","+str((denominador//numerador)-1)+",1"
			else:
				write+=","+str(denominador//numerador)
			c= numerador
			numerador= denominador%numerador
			denominador= c
			
		write+="]\n"
		file2.write(write)
file2.close()
