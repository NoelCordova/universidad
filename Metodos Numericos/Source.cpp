#include <iostream>
#include <stdlib.h>

using namespace std;


void metodo2(){
	int i = 1, iteraciones;
	float a, b, c, ordenada, pa, pb, pc;
	system("cls");

	cout << "Forma de la ecuacion: (a, b)^2, c";
	cout << "\n\nIngrese el valor de A : ";			cin >> a;
	cout << "\nIngrese el valor de B : ";			cin >> b;
	cout << "\nIngrese el valor de C : ";			cin >> c;
	cout << "\nNum de iteraciones: ";				cin >> iteraciones;

	cout << "\n\n---------------------------------------------" << endl;
	ordenada = (b*b) + c;														//Ordenada al origen "eje Y"
	cout << "Punto ordenada al origen: " << ordenada;
	cout << "\nEl vertice esta en el punto (" << -(b) << ", " << c << ")";		//El vertice 
	cout << "\n---------------------------------------------" << endl;

	cout << "\n\nIngrese el valor para el punto 'A': ";		cin >> pa;
	pb = -(b);

	cout << "\nIteracion\t" << "Punto 'A'\t" << "Punto 'B'\t" << "Punto 'C'\t" << endl <<endl;

	do{
		pc = pa + pb / 2;

		if (pc > 0) { pa = pc; }
		else { pb = pc; }
		cout << i << "\t\t" << pa << "\t\t" << pb << "\t\t" << pc << "\t\t" << endl;
		i++;
	} while (i <= iteraciones);
}

int main(){
	int opc;

	cout << "Elija la forma que ingresara los datos a la ecuacion: \n\n1) a^2, b, c\n2) (a, b)^2, c" << endl;
	cin >> opc;

	switch (opc){
	case 1: cout << "Work in progress :)" << endl;
		break;

	case 2: metodo2();
		break;

	default: cout << "Error. No existe esa opcion!" << endl;
	}

	system("pause >0");
	return 0;
}