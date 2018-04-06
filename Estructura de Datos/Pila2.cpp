#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

using namespace std;
typedef int TipoDato;

struct Pila{
	TipoDato tope, elementos[MAX];
};

typedef struct Pila TipoPila;
void inicializarPila(TipoPila &p){
	p.tope= -1;
};

int pilaVacia(TipoPila &p){
	if(p.tope == -1 )
	return 1;

	else return 0;
}

int pilaLlena(TipoPila &p){
	if(p.tope == MAX)
	return 1;

	else return 0;
}

void ponerPila(TipoPila &p, TipoDato Dato){
	if(pilaLlena(p)==1){
	cout<<"Pila Llena!\n";
	}else{
	     p.tope= p.tope+1;
	     p.elementos[p.tope]= Dato;
	}
};

TipoDato quitarPila(TipoPila &p){
	TipoDato Temp;
	if(pilaVacia(p)==1){
	     cout<<"Subdesbordamiento";
	}else{
	     Temp= p.elementos[p.tope];
	     p.tope= p.tope -1;
	}
	return Temp;
}

void DecimalToBinary(){

	TipoPila x;
	int Cociente, Dividendo, Divisor=2, Residuo;

	inicializarPila(x);
	cout<<"Dame valor del dividendo: ";
	cin>>Dividendo;

	do{
		Cociente= Dividendo/Divisor;
		Residuo= Dividendo%Divisor;
		ponerPila(x, Residuo);



	}while(Cociente>=Divisor);
	ponerPila(x, Cociente);

		while(pilaVacia(x)==0){
		printf("%c", quitarPila(x));
	}
}

int main(){
	DecimalToBinary();

	return 0;


}

