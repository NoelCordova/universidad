#! usr/bin/python

from math import sqrt
from math import pow
from math import sin
from math import cos
from math import tan
from math import radians

class CalculadoraBasica():
    def __init__(self, numX, numY):
        self.numX = numX
        self.numY = numY
        
    def Suma(self):
        return self.numX + self.numY
        
    def Resta(self):
        return self.numX - self.numY
        
    def Division(self):
        return self.numX / self.numY
        
    def Multiplicacion(self):
        return self.numX * self.numY
    
    
class CalculadoraCientifica(CalculadoraBasica):
    def __init__(self, numX, numY):
        CalculadoraBasica.__init__(self, numX, numY)
    
    def Raiz(self):
        return sqrt(self.numX)
    
    def Radianes(self):
        return radians(self.numX)
    
    def Potencia(self):
        return pow(self.numX, self.numY)
    
    def Seno(self):
        return sin(radians(self.numX))
    
    def Coseno(self):
        return cos(radians(self.numX))
    
    def Tangente(self):
        return tan(radians(self.numX))
    

class CalculadoraProgramador(CalculadoraBasica):
    def __init__(self, numX, numY, resultado):
        CalculadoraBasica.__init__(self, numX, numY)
        self.resultado = resultado
        
    def Binario(self):
        return bin(self.resultado)[2:]
    
    def Octal(self):
        return oct(self.resultado)
    
    def Hexadecimal(self):
        return hex(self.resultado)[2:]
    

class CalculadoraFinanciera(CalculadoraBasica):
    def __init__(self, numX, numY):
        CalculadoraBasica.__init__(self, numX, numY)
        self.costDolar      = 19.634
        self.costEUR        = 20.7753
        self.costPesoDolar  = 1/self.costDolar
        self.costPesoEUR    = 1/self.costEUR
        
    def DolarToPeso(self):
        return self.numX * self.costDolar
    
    def EurToPeso(self):
        return self.numX * self.costEUR
        
    def PesoToDolar(self):
        return self.numX * self.costPesoDolar
    
    def PesoToEur(self):
        return self.numX * self.costPesoEUR