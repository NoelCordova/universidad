#include<iostream>
#include<stdlib.h>
#define MAX 10

using namespace std;

int n= 0, v[MAX], I, POS;

int buscarSec(int x, int n){
	I= 0;

	while(I<=n && v[I]<x)
	I++;

	if(I>n || v[I]>x)
		return -I;
	else

	return I;
}

void insertarOrd(int y){
	if(n<MAX){
		POS= buscarSec(y, n);


		if(POS>0)
		cout<<"El elemento ya existe" <<endl;

		else{
			n++;
			POS= POS*(-1);

			for(I=n; I>POS; I--)
			v[I]= v[I-1];
			v[POS]= y;
			}
	}else cout<<"No hay espacio en el arreglo" <<endl;
}

void eliminarOrd(int y){
	if(n>0){
		POS= buscarSec(y, n);

		if(POS<0)
		cout<<"El elemento no existe" <<endl;

		else{
			n--;

			for(I=POS; I<=n; I++)
				v[I]= v[I+1];

		}
	}else cout<<"El arreglo esta vacio" <<endl;
}

void modificarOrd(int y, int x){
	insertarOrd(y);
	eliminarOrd(x);
}

void mostrarArreglo(){
	for(I=1; I<=n; I++)
	cout<<v[I] <<", ";

	cout<<"\n";
	system("pause");
}

int main(){
	int x, y, opc, t;

	do{
		system("cls");
		cout<<"1) Insertar" <<endl;
		cout<<"2) Eliminar" <<endl;
		cout<<"3) Modificar" <<endl;
		cout<<"4) Mostrar" <<endl;
		cout<<"5) Salir" <<endl;
		cin>>opc;

		switch(opc){
			case 1: cout<<"\nIngresa un valor: ";
			cin>>x;
			insertarOrd(x);
			break;

			case 2: cout<<"\n Ingrese valor a eliminar: ";
			cin>>x;
			eliminarOrd(x);
			break;

			case 3: cout<<"Ingrese nuevo valor: ";
			cin>>x;
			cout<<"Seleccione valor a modificar: ";
			cin>>y;
			modificarOrd(x, y);
			break;

			case 4: mostrarArreglo();
			break;
			}
	}while(opc !=5);

	return 0;
	system("pause");
}
