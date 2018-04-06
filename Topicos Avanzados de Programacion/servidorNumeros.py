#!/usr/bin/env python3
#servidor
import socket

HOST= ''
PUERTO= 2015

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PUERTO))
s.listen(1)

con, dir= s.accept()
print('Conectado desde ', dir)

while True:
	datos= con.recv(1024)
	if not datos: break
	print('datos= ', datos)
	datos= int(datos)*2
	print (datos)
	datos2= str(datos)
	con.sendall(bytes(datos2, 'UTF-8'))
con.close()


#AF_INET   IPv4  ****.*.*.*   IPv6 ***.*.*.*.*.*

#SOCK_STREAM   TCP --> Envia y recibe datos      SOCK_DGRAM    UDP --> No recibe, solo envía

#UNICODE   UTF8
