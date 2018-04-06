#!/usr/bin/env python3
#cliente
import socket

HOST= 'Localhost'
PUERTO= 2015

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PUERTO))
s.sendall(b'10')
datos= s.recv(1024)
s.close()

print('Regreso', repr(datos))
