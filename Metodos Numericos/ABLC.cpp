#include <iostream>
#include <stdlib.h>

using namespace std;

main(){
	float base; float particiones; float res;
	int opc;
	
	do{
		system("cls");
		
		cout<<"\n	Ingresa el tamano de la base: [  ]\b\b\b";		cin>> base;
		cout<<"\n	Ingresa el numero de particiones: [  ]\b\b\b"; 	cin>> particiones;
	
		for(int i = 1; i < particiones; i++){
			base= base/particiones;
			res+= base * ((i*base) * (i*base));
		}
	
		cout<<"\n\n-------------------------------------------------\n";
		cout<<"	El area bajo la curva es de " <<res <<endl;
		cout<<"-------------------------------------------------";
		
		system("pause >0");	system("cls");
	
		cout<<"\n	Introduzca '1' para continuar, o '0' para salir:  [ ]\b\b"; 		
		cin>>opc;

	}while(opc != 0);
	
	system("cls");
	
	cout<<"\n	made in ITS Zapopan <3";
	
	return 0;	
}
