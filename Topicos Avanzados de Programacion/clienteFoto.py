#!/usr/bin/env python3
#Cliente
import socket
arch= open('/home/slingerriperxd/Desktop/foto.jpg','rb')
foto= arch.read()

HOST= 'Localhost'
PUERTO= 2015
s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PUERTO))

s.sendall(foto)
arch.close()
s.close()

