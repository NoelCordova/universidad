#include<iostream>
#include "funciones.h"

using namespace std;

int lenght(char *a){
	int i= 0;
	
	while(a[i] != '\0'){
		if(a[i] !='\0')	i++;
	}
	return i;
}

bool equals(char *a, char *b){
	int i= 0;
	
	if(lenght(a) != lenght(b)) return false;
	else{
		while(i <= lenght(a)){
			if(a[i] == b[i]) i++;	
			else return false;
		}
		return true;
	}
}

void alphabet(char *a){
	char cadena[50];
	int i=0, i2, cont=0;
	cadena[0]= a[0];
	
	cout<<"[" <<cadena[0] <<",";
	for( ; i<lenght(a); i++){
		for(i2=0;i2<lenght(cadena); i2++){
			if(cadena[i2]==a[i]) break;
			if(i2>=lenght(cadena)-1){
				cadena[cont]= a[i];
				cout<<cadena[cont] <<",";
				cont++;
			}
		}
	}
	cout<<"\b]";
}

char *catenate(char *a, char *b){
	int contC=0, i= 0;
	char *cad;
	int tam= lenght(a)+lenght(b);
	cad= new char[tam];
	
	while(a[i] != '\0'){
		cad[contC]= a[i];
		contC++;
		i++;
	}
		
	
	i=0;
	while(b[i] != '\0'){
		cad[contC]= b[i];
		contC++;
		i++;
	}
	cad[tam]='\0';
	
	return cad;
	delete cad;
}

char *power(char *a, int n){
	int cont= 1, contC= 0;
	char *cad;
	int tam= (lenght(a)*n)+1;
	cad= new char[tam];
	
	
	while(cont <= n){
		int i=0;
		while(a[i] != '\0'){
			cad[contC]= a[i];
			contC++;
			i++;
		}
		cont++;
	}

	cad[tam-1]='\0';
	return cad;
	delete cad;
}

