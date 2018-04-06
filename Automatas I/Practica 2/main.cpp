#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

main(){
	char cadena[50];

	cout<<"Ingrese la cadena a evaluar: ";	gets(cadena);
	cout<< endl;
	
	if(test(cadena)== true)cout<<"\nLa cadena [" <<cadena <<"] es aceptada";
	
	else cout<<"\nLa cadena [" <<cadena <<"] no es aceptada";
	
}
