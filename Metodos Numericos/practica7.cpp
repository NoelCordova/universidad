#include<iostream>
#include<cstdlib>

using namespace std;

main(){
	system("/usr/bin/clear");	//Funcion para limpiar pantalla en linux
	int polinomio;				//Declaracion de variables
	float punto, suma=0;
	
	cout<<"TamaÃ±o del polinomio: "; 	cin>>polinomio;		cout<< endl;	//Se pregunta al usuario el tamaño 
	float xi[polinomio], fxi[polinomio], numerador, denominador;			//para aqui hacer listas en base al tamaño y no gastar memoria
	
	for(int n=1; n<=polinomio; n++){						
		cout<<"Ingrese el dato para xi [" <<n <<"] : "; 	cin>>xi[n];		//Se agragan datos a lista 
		cout<<"Ingrese el dato para f(xi) [" <<n <<"] : "; 	cin>>fxi[n];	//Se agregan datos a lista
		cout<< endl;
	}
	
	cout<<"Punto a estimar : ";		cin>>punto;		//Punto a evaluar
	
	for(int n=1; n<=polinomio; n++){		//Aqui empieza el proceso
		float prom= 1;
		for(int n2=1; n2<=polinomio; n2++){	//Proceso para evaluar los contadores
			if (n2!=n){						//Condicion
				prom*= (punto-xi[n2])/(xi[n]-xi[n2]);	//Formula 
			}else{
				prom*= fxi[n]; 	//Si los contadores son iguales se hace eso
			}
		}
		suma+= prom;	//Sumatoria
	}
	
	cout<<suma <<endl;	//Se imprime a pantalla el resultado
}
