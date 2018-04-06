#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#define MAX 20

using namespace std;
typedef int TipoDato;

struct Pila{
	TipoDato Tope, Elementos[MAX];
};

typedef struct Pila TipoPila;
void inicializarPila(TipoPila &p){
	p.Tope= -1;
};

int PilaVacia(TipoPila &p){
	if(p.Tope== -1)
		return 1;
	else return 0;
}

int PilaLlena(TipoPila &p){
	if(p.Tope==MAX)
		return 1;
	else return 0;
}

void PonerPila(TipoPila &p, TipoDato Dato){
	if(PilaLlena(p)==1){
		cout<<"¡Fatal Error! code: 342556 (Pila Llena)";
	}else{
		p.Tope= p.Tope+1;
		p.Elementos[p.Tope]= Dato;
	}
};

TipoDato QuitarPila(TipoPila &p){
	TipoDato Temp;
	if(PilaVacia(p)==1){
		cout<<"Subdesbordamiento";
	}else{
		Temp= p.Elementos[p.Tope];
		p.Tope= p.Tope -1;
	}
	return Temp;
}

void CadenaInversa(){
		int i; 
		TipoPila x;
		char Frase[MAX];

		inicializarPila(x);

		cout<<"Estriba una frase: " <<endl;
		cin>>Frase;
		cout<<"\n";

	for(i=0; i<strlen(Frase); i++){
		PonerPila(x, Frase[i]);
	}
	
	while(PilaVacia(x)==0){
		printf("%c", QuitarPila(x));
	}
}

int main(){
	CadenaInversa();
	cout<<"\n";
	return 0.5;
}
