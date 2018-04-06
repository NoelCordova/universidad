#!/usr/bin/env python3

class complejo:
    def __init__(self, real, imaginario):
        self.real= real
        self.imaginario= imaginario
        
    def conjugado(self):
        return complejo(self.real, -self.imaginario)

    def imprime(self):
        if self.imaginario > 0:
            print("(", self.real, "+ i", self.imaginario, ")")
            
        elif self.imaginario < 0:
            print("(", self.real, "- i", -self.imaginario, ")")

        else: 
            print("(", self.real, ")")
            
    def imprimeC(self):
        if self.imaginario > 0:
            print("(", self.real, " - i", self.imaginario, ")")

        elif self.imaginario < 0:
            print("(", self.real, " + i", -self.imaginario, ")")

        else:
            print("(", self.real, ")")			


    def mas(self, c):
        numR= self.real + c.real
        numI= self.imaginario + c.imaginario
        return complejo(numR, numI)

    def menos(self, c):
        numR= self.real - c.real
        numI= self.imaginario - c.imaginario
        return complejo(numR, numI)

    def por(self, c):
        numR= (self.real * c.real) - (self.imaginario * c.imaginario)
        numI= (self.real * c.imaginario) + (self.imaginario * c.real)
        return complejo(numR, numR)

    def entre(self,c):
        numerador= self.por(c.conjugado())	
        denominador= c.por(c.conjugado())
        numR= float (numerador.real / denominador.real)
        numI= float (numerador.imaginario / denominador.real)
        return complejo(numR, numI)

z1= complejo(5,2)
z2= complejo(4, -2)

print("\nComplejo")
z1.imprime()
z2.imprime()

print("\nConjugado")
z1.imprimeC()
z2.imprimeC()

print("\nSuma")
z3= z1.mas(z2)
z3.imprime()

print("\nResta")
z3= z1.menos(z2)
z3.imprime()

print("\nPor")
z3= z1.por(z2)
z3.imprime()

print ("\nDivision")
z3= z1.entre(z2)
z3.imprime(); print ("\n")