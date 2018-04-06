#include <iostream>
#include <stdlib.h>

using namespace std;

int a[21], cont, suma, prom, M= 0, m= 100;

void ingresarDato(){
	for(cont=1; cont<=20; cont++){
		cout<<"Ingrese el valor numero (" <<cont <<") para el arreglo: ";
		cin>>a[cont];
	}
}

int promedio(){
	for(cont=1; cont<=20; cont++){
		suma= suma+a[cont];
	}
	prom= suma/20;
	cout<<"\nPromedio: " <<prom;
}

int mayor(){
	for(cont=1; cont<=20; cont++){
		if(a[cont] > M){
		M= a[cont];
		}	
	}
	 cout<<"\nNumero mayor: " <<M;	
}

int menor(){
	for(cont=1; cont<=20; cont++){
		if(a[cont] < m){
			m= a[cont];
		}
	}
	cout<<"\nNumero menor: " <<m;
}

int main(){

	ingresarDato();
	promedio();
	mayor();
	menor();

	cout<<"\n";
	
	return 0;
}
	
