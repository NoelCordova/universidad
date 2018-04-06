#!/usr/bin/python3
import sys
from PyQt5.QtWidgets import (QWidget, QPushButton, QLineEdit, QComboBox, QApplication, QLabel)

xl= []
yl= []

class Actividad7(QWidget):
	def __init__(self):
		super().__init__()
		self.ventana()
		
	def ventana(self):
		#Etiquetas
		self.entrada = QLineEdit("Numero de datos", self)
		self.entrada.move(5,5)
		self.combo = QComboBox(self)
		self.combo.move(160,5)
		x= QLabel("X:", self)
		x.move(5,40)
		btn= QPushButton("Calcular", self)
		btn.move(190,35)
		y = QLabel("f(X):", self)
		y.move(5,70)
		self.entradax = QLineEdit(self)
		self.entradax.move(35,35)
		self.entraday = QLineEdit(self)
		self.entraday.move(35,65)
		btn2= QPushButton("Borrar Todo", self)
		btn2.move(190,65)
		self.valor = QLineEdit("Valor a estimar en",self)
		self.valor.move(5,95)
		self.ecuacion= QLabel("Y=",self)
		self.ecuacion.move(5,130)

		#Eventos
		self.entrada.textChanged[str].connect(self.combobox)
		self.combo.activated[str].connect(self.cambio)
		self.entradax.textChanged[str].connect(self.x)
		self.entraday.textChanged[str].connect(self.y)
		btn.clicked.connect(self.boton)
		self.entrada.selectionChanged.connect(self.sel1)
		self.entradax.selectionChanged.connect(self.sel2)
		self.entraday.selectionChanged.connect(self.sel3)
		self.valor.selectionChanged.connect(self.sel4)
		btn2.clicked.connect(self.borrar)
		#Ventana
		self.setGeometry(300, 300, 310, 150)
		self.setWindowTitle("Polinomios de interpolacion de Langrange")
		self.show()
	
	def combobox(self, text):
		self.combo.clear()
		self.entradax.clear()
		self.entraday.clear()
		if text =='':
			text='0'
		for c in range(int(text)):
			self.combo.addItem(str(c+1))
			if len(xl)<= c:
				xl.append(0.0)
				yl.append(0.0)
		if text != "0":
			self.entradax.setText(str(xl[self.combo.currentIndex()]))
			self.entraday.setText(str(yl[self.combo.currentIndex()]))
			
	def cambio(self, text):
		self.entradax.setText(str(xl[int(text)-1]))
		self.entraday.setText(str(yl[int(text)-1]))
	def x(self, text):
		if text == "" or text == '-':
			text= "0"
		xl[self.combo.currentIndex()]= float(text)
	def y(self, text):
		if text == "" or text == '-':
			text= "0"
		yl[self.combo.currentIndex()]= float(text)
	def boton(self):
		if self.valor.text() == "": #Si el usuario deja en blanco el valor a conocer se conocera que es 0
			self.valor.setText("0")
		datos= int(self.entrada.text()) #datos es el numero de datos ingresados por el usuario
		cx= float(self.valor.text())#cx sera el valor que el usuario quiera conocer
		suma=0 #Se declara la sumatoria
		for c in range(datos): #Este for funciona para movernos en I
			pro=1 #Se declara la variable producto
			for c2 in range(datos):#Este for funciona para movernos en J
				if c2!=c: #Si I es diferente a J se realizara la operacion producto 
					pro*= (cx-xl[c2])/(xl[c]-xl[c2]) #Producto de
			pro*= yl[c] #Al final de pasar por cada J se multiplica por f(X) en el cual I esta actualmente
			suma+= pro #pro pasa a ser parte de la Sumatoria
		self.ecuacion.setText("Y= " + str(suma)) #Al final se imprime la Sumatoria
		self.ecuacion.adjustSize()
	def sel1(self):
		self.entrada.clear()
	def sel2(self):
		self.entradax.clear()
	def sel3(self):
		self.entraday.clear()
	def sel4(self):
		self.valor.clear()
	def borrar(self):
		for c in range(len(xl)):
			xl[c]= 0.0
			yl[c]= 0.0
		self.sel1()
		self.sel2()
		self.sel3()
		self.sel4()
if __name__ == '__main__':
	app = QApplication(sys.argv)
	A= Actividad7()
	sys.exit(app.exec_())
