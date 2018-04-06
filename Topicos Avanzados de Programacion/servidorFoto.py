#!/usr/bin/env python3
#servidor
import socket
HOST= ''
PUERTO= 2015
datos2= bytes(0)
file= open('/home/slingerriperxd/Desktop/dat.jpg', 'wb')

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PUERTO))
s.listen(1)

con, dir= s.accept()
print('Conectado desde ', dir)

while True:
	datos= con.recv(1024)
	datos2+= datos
	if not datos: break
	
file.write(datos2)
file.close()	
con.close()


#AF_INET   IPv4  ****.*.*.*   IPv6 ***.*.*.*.*.*

#SOCK_STREAM   TCP --> Envia y recibe datos      SOCK_DGRAM    UDP --> No recibe, solo envía

#UNICODE   UTF8
