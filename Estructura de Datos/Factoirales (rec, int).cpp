#include <iostream>
#include <stdlib.h>

using namespace std;

int factorialRec(int n){
	if(n==0 || n==1){
		return 1;
	}
	else{
		return n*factorialRec(n-1);
	}
}

int factorialInt(int n){
	int a= 1;
	
	if(n==0 || n==1){
		return 1;
	}
	else{
		for(n; n>=1; n--){
			a= (a * n);
		}
		return a;	
	}
}

int main(){
	int opc, n, fac;
	
	do{
		system("cls");
		
		cout<<"-----FACTORIALES-----" <<endl;
		cout<<"1) Factorial recursivo" <<endl <<"2) Factorial iterativo" <<endl <<"3) Salir" <<endl;
		cin>>opc;
		
		system("cls");
		switch(opc){
			case 1: 	cout<<"                    FACORIAL RECURSIVO" <<endl <<"---------------------------------------------------" <<endl; 
						cout<<"Ingrese el valor al que desea calcular el factorial: ";
						cin>>n;
	
				if(n<0){
					cout<<"¡Ingrese numero positivo!";
					cin>>n;
				}
				
				fac= factorialRec(n);
				cout<<n <<"! = " <<fac <<endl;
				
				system("pause"); break;
				
			case 2:		cout<<"                    FACORIAL ITERATIVO" <<endl <<"---------------------------------------------------" <<endl;
						cout<<"Ingrese el valor al que desea calcular el factorial: ";
						cin>>n;
	
				if(n<0){
					cout<<"¡Ingrese numero positivo!";
					cin>>n;
				}
				
				fac= factorialInt(n);
				cout<<n <<"! = " <<fac <<endl;
				
				system("pause"); break;
				
			default: cout<<"Opcion invalida" <<endl;
		}
	}while(opc <4);
	
	return 0;
	system("pause");
}

