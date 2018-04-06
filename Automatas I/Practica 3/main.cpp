#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

main() {
	string w;
	grammar G;


	cout<<"Ingrese una cadena: ";	cin>>w;		cout<<endl;


	if(CYK(G, w) == true){
		cout<<"La cadena es aceptada :)" <<endl;
	}else{
		cout<<"La cadena no es aceptada :(" <<endl;
	}


	system("pause>0");
}
