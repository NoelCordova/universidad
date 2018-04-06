#! usr/bin/python

from classes import CalculadoraBasica
from classes import CalculadoraCientifica
from classes import CalculadoraProgramador
from classes import CalculadoraFinanciera
import metodos


if __name__ == '__main__':
    
    resultado = 0.0
    
    while True:
        metodos.clear()
        metodos.menu()
        operacion = ''
        cadena = ''
        list = []
        
        opc = raw_input("Opcion: ").lower()
        
        if opc == 'b':
            while operacion != 'r':
                metodos.clear()
                print '\tCalculadora Basica\n'
                metodos.menuBasica()
                operacion = raw_input("Operacion: ")

                if operacion == '1':
                    numX = float(raw_input('>>>'))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(numX, numY)
                    resultado = float(calculadora.Suma())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == '2':
                    numX = float(raw_input('>>>'))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(numX, numY)
                    resultado = float(calculadora.Resta())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == '3':
                    numX = float(raw_input('>>>'))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(numX, numY)
                    resultado = float(calculadora.Multiplicacion())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == '4':
                    numX = float(raw_input('>>>'))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(numX, numY)
                    resultado = float(calculadora.Division())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == 'm1':
                    print ('MEM ' + str(resultado))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(resultado, numY)
                    resultado = float(calculadora.Suma())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == 'm2':
                    print ('MEM ' + str(resultado))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(resultado, numY)
                    resultado = float(calculadora.Resta())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == 'm3':
                    print ('MEM ' + str(resultado))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(resultado, numY)
                    resultado = float(calculadora.Multiplicacion())
                    print resultado
                    raw_input("\nPresione enter para continuar...")

                elif operacion == 'm4':
                    print ('MEM ' + str(resultado))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraBasica(resultado, numY)
                    resultado = float(calculadora.Division())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
        if opc == 'c':
             while operacion != 'r':
                metodos.clear()
                print '\tCalculadora Cientifica\n'
                metodos.menuCientifica()
                operacion = raw_input("Operacion: ")
                
                if operacion == '1':
                    
                    entrada = raw_input(">>>")
                    metodos.CrearLista(entrada, cadena, list)
                    
                    for x in range(len(list)):

                        if list[x] is '+':
                            #Los parametros de Calculadora son list[x-1] y list[x+1]
                            calculadora = CalculadoraCientifica(float(list[x-1]), float(list[x+1]))
                            resultado = float(calculadora.Suma())
                            #Se elimina el contenido a la derecha del operador
                            list.pop(x+1)
                            #En la posicion a la derecha del operador se agrega el resultado
                            list.insert(x+1, resultado)

                        elif list[x] is '-':
                            calculadora = CalculadoraCientifica(float(list[x-1]), float(list[x+1]))
                            resultado = float(calculadora.Resta())
                            list.pop(x+1)
                            list.insert(x+1, resultado)

                        elif list[x] is '*':
                            calculadora = CalculadoraCientifica(float(list[x-1]), float(list[x+1]))
                            resultado = float(calculadora.Multiplicacion())
                            list.pop(x+1)
                            list.insert(x+1, resultado)

                        elif list[x] is '/':
                            calculadora = CalculadoraCientifica(float(list[x-1]), float(list[x+1]))
                            resultado = float(calculadora.Division())
                            list.pop(x+1)
                            list.insert(x+1, resultado)
                            
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '2':
                    numX = float(raw_input('>>>'))
                    calculadora = CalculadoraCientifica(numX, 0)
                    resultado = float(calculadora.Raiz())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '3':
                    numX = float(raw_input('>>>'))
                    numY = float(raw_input('>>>'))
                    calculadora = CalculadoraCientifica(numX, numY)
                    resultado = float(calculadora.Potencia())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '4':
                    numX = float(raw_input('>>>'))
                    calculadora = CalculadoraCientifica(numX, 0)
                    resultado = float(calculadora.Radianes())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '5':
                    numX = float(raw_input('>>>'))
                    calculadora = CalculadoraCientifica(numX, 0)
                    resultado = float(calculadora.Seno())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '6':
                    numX = float(raw_input('>>>'))
                    calculadora = CalculadoraCientifica(numX, 0)
                    resultado = float(calculadora.Coseno())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '7':
                    numX = float(raw_input('>>>'))
                    calculadora = CalculadoraCientifica(numX, 0)
                    resultado = float(calculadora.Tangente())
                    print resultado
                    raw_input("\nPresione enter para continuar...")
                    
        if opc == 'p':
            while operacion != 'r':
                metodos.clear()
                print '\tCalculadora Programador\n'
                metodos.menuProgramador()
                operacion = raw_input("Operacion: ")
                
                if operacion == '1':
                    numX = int(raw_input('>>>'))
                    numY = int(raw_input('>>>'))
                    calculadora = CalculadoraProgramador(numX, numY, 0)
                    resultado = int(calculadora.Suma())
                    calculadora = CalculadoraProgramador(numX, numY, resultado)
                    print '\nDecimal: '     + str(resultado)
                    print 'Binario: '       + str(calculadora.Binario())
                    print 'Octal: '         + str(calculadora.Octal())
                    print 'Hexadecimal: '   + str(calculadora.Hexadecimal())
                    raw_input("\nPresione enter para continuar...")
                
                elif operacion == '2':
                    numX = int(raw_input('>>>'))
                    numY = int(raw_input('>>>'))
                    calculadora = CalculadoraProgramador(numX, numY, 0)
                    resultado = int(calculadora.Resta())
                    calculadora = CalculadoraProgramador(numX, numY, resultado)
                    print '\nDecimal: '     + str(resultado)
                    print 'Binario: '       + str(calculadora.Binario())
                    print 'Octal: '         + str(calculadora.Octal())
                    print 'Hexadecimal: '   + str(calculadora.Hexadecimal())
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '3':
                    numX = int(raw_input('>>>'))
                    numY = int(raw_input('>>>'))
                    calculadora = CalculadoraProgramador(numX, numY, 0)
                    resultado = int(calculadora.Multiplicacion())
                    calculadora = CalculadoraProgramador(numX, numY, resultado)
                    print '\nDecimal: '     + str(resultado)
                    print 'Binario: '       + str(calculadora.Binario())
                    print 'Octal: '         + str(calculadora.Octal())
                    print 'Hexadecimal: '   + str(calculadora.Hexadecimal())
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '4':
                    numX = int(raw_input('>>>'))
                    numY = int(raw_input('>>>'))
                    calculadora = CalculadoraProgramador(numX, numY, 0)
                    resultado = int(calculadora.Division())
                    calculadora = CalculadoraProgramador(numX, numY, resultado)
                    print '\nDecimal: '     + str(resultado)
                    print 'Binario: '       + str(calculadora.Binario())
                    print 'Octal: '         + str(calculadora.Octal())
                    print 'Hexadecimal: '   + str(calculadora.Hexadecimal())
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '5':
                    resultado = int(raw_input('>>>'))
                    calculadora = CalculadoraProgramador(0, 0, resultado)
                    print '\nDecimal: '     + str(resultado)
                    print 'Binario: '       + str(calculadora.Binario())
                    print 'Octal: '         + str(calculadora.Octal())
                    print 'Hexadecimal: '   + str(calculadora.Hexadecimal())
                    raw_input("\nPresione enter para continuar...")
                    
        if opc == 'f':
            while operacion != 'r':
                metodos.clear()
                print '\tCalculadora Financiera\n'
                metodos.menuFinanciera()
                operacion = raw_input("Operacion: ")
                
                if operacion == '1':
                    numX = float(raw_input("Dolar>>>"))
                    calculadora = CalculadoraFinanciera(numX, 0)
                    resultado = float(calculadora.DolarToPeso())
                    print str("%.2f"%resultado)
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '2':
                    numX = float(raw_input("EUR>>>"))
                    calculadora = CalculadoraFinanciera(numX, 0)
                    resultado = float(calculadora.EurToPeso())
                    print str("%.2f"%resultado)
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '3':
                    numX = float(raw_input("PesoMX>>>"))
                    calculadora = CalculadoraFinanciera(numX, 0)
                    resultado = float(calculadora.PesoToDolar())
                    print str("%.2f"%resultado)
                    raw_input("\nPresione enter para continuar...")
                    
                elif operacion == '4':
                    numX = float(raw_input("PesoMX>>>"))
                    calculadora = CalculadoraFinanciera(numX, 0)
                    resultado = float(calculadora.PesoToEur())
                    print str("%.2f"%resultado)
                    raw_input("\nPresione enter para continuar...")
            
        if opc == 'q':
            metodos.clear()
            print '\nCYA c:\n'
            break