#!/usr/bin/python3

#import numpy as func
#import matplotlib.pyplot as graf
import sys
from PyQt5.QtWidgets import (QWidget, QPushButton, QLineEdit, QComboBox, QApplication, QLabel)
xl= []
yl= []
#def grafica():
	
class Example(QWidget):
	def __init__(self):
		super().__init__() 
		self.ventana()
	def ventana(self):
		#Planteamiento de etiquetas
		self.inp= QLineEdit("Numero de datos", self)
		self.inp.move(5,5)
		self.x= QLineEdit(self)
		self.x.move(5,50)
		self.y= QLineEdit(self)
		self.y.move(160,50)
		lbl= QLabel("x", self)
		lbl.move(5, 30)
		lbl2= QLabel("y", self)
		lbl2.move(160, 30)
		self.lbl3= QLabel(self)
		self.lbl3.move(5,75)
		self.inp2=QLineEdit("Conocer X en",self)
		self.inp2.move(5,100)
		self.lbl4= QLabel("y=...", self)
		self.lbl4.move(160,100)
		self.com= QComboBox(self)
		self.com.move(160,5)
		but= QPushButton("Calcular", self)
		but.move(5,130)
		
		
		#Eventos
		self.com.activated[str].connect(self.onAc)
		self.inp.textChanged[str].connect(self.combo)
		self.x.textChanged[str].connect(self.lx)
		self.y.textChanged[str].connect(self.ly)
		self.inp.selectionChanged.connect(self.bor)
		self.x.selectionChanged.connect(self.bor2)
		self.y.selectionChanged.connect(self.bor3)
		self.inp2.selectionChanged.connect(self.bor4)
		but.clicked.connect(self.boton)

		#Ventana
		self.setGeometry(300, 300, 350, 160)
		self.setWindowTitle('Regresion Lineal')
		self.show()
#Metodos de los eventos
	def boton(self):
		sp=0
		ss=0
		ym= 0
		xm= 0
		b1=0
		b0=0
		te= int(self.inp.text())
		for c in range(te):
			ym+= yl[c]
			xm+= xl[c]
		c=0
		ym/=te
		xm/=te
		for c in range(te):
			sp+= (xl[c]-xm)*(yl[c]-ym)
			ss+= (xl[c]-xm)**2
		b1= sp/ss
		b0= ym-(b1*xm)
		if self.inp2.text() == '':
			self.inp2.setText("0")
		cp= float(self.inp2.text()) 		
		r= b0+(b1*cp)
		self.lbl4.setText("y="+str(r))
		self.lbl4.adjustSize()
		self.lbl3.setText("y="+str(b0)+"+("+str(b1)+"x)")
		self.lbl3.adjustSize()
	def bor(self):
		self.inp.clear()
	def bor2(self):
		self.x.clear()
	def bor3(self):
		self.y.clear()
	def bor4(self):
		self.inp2.clear()
	def combo(self, text):
		self.com.clear()
		if text =='':
			text='0'
		for c in range(int(text)):
			self.com.addItem(str(c+1))
			if len(xl)<= c:
				xl.append(0)
				yl.append(0)

	def lx(self, text):
		if text == "":
			text= "0"
		xl[(self.com.currentIndex())]= float(text)
	def ly(self, text):
		if text == "":
			text= "0"
		yl[(self.com.currentIndex())]= float(text)
	def onAc(self, text):
		
		if self.x.text()== " ":
			xl[int(text)-1]= 0
		if self.y.text()== " ":
			yl[int(text)-1]= 0
		self.x.setText(str(xl[int(text)-1]))
		self.y.setText(str(yl[int(text)-1]))


if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
