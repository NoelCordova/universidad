#!/usr/bin/env python

import os
from ClassVuelos import Vuelos

def clear():
    if os.name == 'nt':
        os.system("cls")
    elif os.name == 'posix':
        os.system("clear")



if __name__ == '__main__':
    
    vuelos = Vuelos()
    vuelos.separar()

    while True:
        clear()
        print   (
                    "1. Consulta de aerolinea\n"            +
                    "2. Consulta por origen\n"              +
                    "3. Consulta por fecha de salida\n"     +
                    "4. Consulta por fecha de llegada\n"    +
                    "5. Rango de precios\n"                 +
                    "0. Salir"
                )

        opc = raw_input("Opcion: ")

        if opc == '1':
            clear()
            vuelos.consultaAerolinea()
            raw_input("\n\n\nEntrer para continuar...")

        elif opc == '2':
            clear()
            vuelos.consultaOrigen()
            raw_input("\n\n\nEntrer para continuar...")

        elif opc == '3':
            clear()
            vuelos.consultaFS()
            raw_input("\n\n\nEntrer para continuar...")

        elif opc == '4':
            clear()
            vuelos.consultaLlegada()
            raw_input("\n\n\nEntrer para continuar...")

        elif opc == '5':
            clear()
            vuelos.consultaPrecios()
            raw_input("\n\n\nEntrer para continuar...")

        elif opc == '0':
            break