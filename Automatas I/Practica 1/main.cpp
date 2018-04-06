#include <iostream>
#include "funciones.h"

using namespace std;

main() {
	char a[50], b[50];
	int num;
	
	cout<<"Ingrese la cadena A: ";		gets(a);
	cout<<"Ingrese la cadena B: ";		gets(b);
	cout<<"Num entero para potencia: ";		cin>>num;
	cout<<"\n- - - - - - - - - - - - - -" <<endl <<endl;
	
	//---------------------------------------------------------
	cout<<"\n\tCadena A\n" <<endl;
	cout<<"Longitud de la cadena: " <<lenght(a) <<endl;
	cout<<"Alfabeto minimo: "; alphabet(a); cout<<endl;
	cout<<"Potencia de cadena: " <<power(a, num);
	
	//--------------------------------------------------------
	cout<<"\n\n\n\tCadena B\n" <<endl;
	cout<<"Longitud de la cadena: " <<lenght(b) <<endl;
	cout<<"Alfabeto minimo: "; alphabet(b); cout<<endl;
	cout<<"Potencia de cadena: " <<power(b, num) <<endl;
	
	//--------------------------------------------------------
	if(equals(a, b)==1) cout<<"\n\nLas cadenas A y B son iguales!" <<endl;
	else cout<<"\n\nLas cadenas A y B son diferentes..." <<endl;
	cout<<"\nConcatenacion de cadenas A y B: " <<catenate(a, b) <<endl;
	cout<<"\nConcatenacion de cadenas B y A: " <<catenate(b, a) <<endl;
	
}
