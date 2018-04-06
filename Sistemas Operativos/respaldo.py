#!/usr/bin/env python

file= open("/home/slingerriperxd/Desktop/Hello.txt", "w")
file.write("Hello :3")
file.write("\nAhora si funciona?")
file.write("\nSI FUNCIONO!!!")

file= open("/home/slingerriperxd/Desktop/Hello.txt", "r")
newfile= file.read()
	
	
file2= open("/home/slingerriperxd/Documents/Python/T.S.O/Backup.txt", "w")
file2.write(newfile)

file.close()
file2.close()
