#!/usr/bin/env python3
import time
from threading import Thread


def creacion_de_proceso(i):
	print("Se creo el proceso: ", i)
	
	for c in range(i*5):
		time.sleep(1)
		
		if (i*5)-5  is c:
			print("Se esta ejecutanto el proceso " + str(i))
			
	print("\n\tSe completo el proceso: ", i, "\n")
	
def main(i):
	i=1
	while 1:
		t= Thread(target= creacion_de_proceso, args= (i,))
		time.sleep(2)
		t.start()
		i+=1
		
if __name__ == '__main__':
	main(1)
