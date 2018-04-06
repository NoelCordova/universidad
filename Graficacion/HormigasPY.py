from msvcrt import getch, kbhit
import random, os

#Declaracion de matriz y tamano
matriz= []
tamano= 10

#Numeros aleatorios
x= random.randrange(1, tamano-1)
y= random.randrange(1, tamano-1)

#matriz se llena con ceros
for contador in range(tamano):
	matriz.append([0]*tamano)

#Los siguientes son metodos para moverse por la terminal
#se repite los mismos comandos pero con sus respectivas variaciones


#Metodo para mover a la derecha
def Derecha():
   global y     #Uso de variable global
   y+= 1    #Sumatoria para la posicion
   
   if (y  >= tamano-1): #Condicion para esquinas
      y-= tamano    #Nueva sumatoria para las orillas

   Imprimir()

#Metodo para mover a la Izquierda
def Izquierda():
   global y
   y-= 1

   if (y <= -tamano):
      y+= tamano

   Imprimir()

#Metodo para mover arriba
def Arriba():
   global x
   x-= 1

   if (x <= -tamano):
      x+= tamano

   Imprimir()

#Metodo para mover abajo
def Abajo():
   global x
   x+= 1

   if (x >= tamano-1):
      x-= tamano

   Imprimir()	

#Metodo para imprimir
def Imprimir():
   global x, y

   for dx in range(x-1, x+2):       #Ciclos para los valores de cada posicion
      for dy in range(y-1, y+2):

         if (matriz[dx][dy] is 9):  #Condicion para el limite del valor
            matriz[dx][dy]= 0

         else:
            matriz[dx][dy] += 1
    
   os.system("cls")
   for contador in range(tamano):   #Imprime la matriz
      print(matriz[contador])
   print ("\n")


Imprimir()

#Ciclo para detectar y hacer las funciones de las teclas
while(True):
    if kbhit():
        chr= getch()
        if chr is b'H':
            Arriba()
        elif chr is b'K':
            Izquierda()
        elif chr is b'P':
            Abajo()
        elif chr is b'M':
            Derecha()
