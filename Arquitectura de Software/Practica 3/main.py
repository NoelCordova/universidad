#!/usr/bin/env python

import metodos

if __name__ == '__main__':

	status = False

	while status != True:
		metodos.clear()
		print 	(
					"\n\t     Menu:\n\n" 					+
					"1.  Programa 1   (Nominas)\n"			+
					"2.  Programa 2   (Ceros)\n"			+
					"3.  Programa 3   (Pares, impares)\n"	+
					"4.  Programa 4   (Serie)\n"			+
					"5.  Programa 5   (Serie N)\n"			+
					"6.  Programa 6   (Mayor o menor)\n"	+
					"7.  Programa 7   (Ventas)\n"			+
					"8.  Programa 8   (Fibonacci)\n"		+
					"9.  Programa 9   (Num primos)\n"		+
					

					"\nQ. Salir\n\n"
				)

		opc = raw_input("Opcion: ")
		print "\n"

		if opc != 'q' or opc != 'Q':
			status= False

		#--------------------------------------------------------------------------

		if opc is '1':
			print "El total de la nomina es: " + str(metodos.programa_A())

		elif opc is '2':
			print str(metodos.programa_B())

		elif opc is '3':
			print str(metodos.programa_C())

		elif opc is '4':
			print str(metodos.programa_D())

		elif opc is '5':
			print str(metodos.programa_E())

		elif opc is '6':
			print str(metodos.programa_F())

		elif opc is '7':
			print str(metodos.programa_G())

		elif opc is '8':
			print str(metodos.programa_H())

		elif opc is '9':
			print str(metodos.programa_I())

		#--------------------------------------------------------------------------

		elif opc is 'q' or opc is 'Q':
			metodos.clear()
			print '\nBye c:\n'
			break

		else:
			metodos.clear()
			print 'Opcion invalida...'

		raw_input("\nEnter para continuar...")