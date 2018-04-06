#! usr/bin/python

import os

def clear():
    if os.name == 'nt':
        os.system("cls")
    elif os.name == 'posix':
        os.system("clear")


def menu():
    print   (
                "\tElija un tipo de calculadora"    +
                "\n\nB. Basica\n"                   +
                "C. Cientifica\n"                   +
                "P. Programador\n"                  +
                "F. Financiera\n"                   +
                "Q. Salir\n"
            )
    
    
def menuBasica():
    print   (
                "1.  Suma\n"                        +
                "2.  Resta\n"                       +
                "3.  Multiplicacion\n"              +
                "4.  Division\n"                    +
                "M1. Memoria & Suma\n"              +
                "M2. Memoria & Resta\n"             +
                "M3. Memoria & Multiplicacion\n"    +
                "M4. Memoria & Division\n"          +
                "R.  Regresar al menu\n"
            )


def menuCientifica():
    print   (
                "1.  Entrada de datos\n"    +
                "2.  Raiz cuadrada\n"       +
                "3.  Potencia\n"            +
                "4.  Radianes\n"            +
                "5.  Seno\n"                +
                "6.  Coseno\n"              +
                "7.  Tangente\n"            +
                "R.  Regresar al menu\n"
            )
    

def menuProgramador():
    print   (
                "1.  Suma\n"                +
                "2.  Resta\n"               +
                "3.  Multiplicacion\n"      +
                "4.  Division\n"            +
                "5.  Convertir numero\n"    +
                "R.  Regresar al menu\n"
            )
    

def menuFinanciera():
    print   (
                "1.  Dolar a Peso\n"        +
                "2.  EUR a peso\n"          +
                "3.  Peso a Dolar\n"        +
                "4.  Peso a EUR\n"          +
                "R.  Regresar al menu\n"    
            )


def CrearLista(entrada, cadena, lista):
#Separar la cadena en una lista independiente.
    cadena = ''
    for x in range(len(entrada)):

        if str.isdigit(entrada[x]) == True:
            cadena = cadena + str(entrada[x])

            if x is len(entrada)-1:
                lista.append(cadena)
                
        elif entrada[x] == '(':
            
            if cadena == '':
                lista.append(entrada[x])
            else:
                lista.append(cadena)
                cadena = ''
                lista.append(entrada[x])
                
        elif entrada[x] == ')':
            lista.append(cadena)
            cadena = ''
            lista.append(entrada[x])

        else:
            lista.append(cadena)
            cadena = ''
            lista.append(entrada[x])