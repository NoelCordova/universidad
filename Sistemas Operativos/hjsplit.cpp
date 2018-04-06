#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

FILE *arch, *arch2;
char NomArch[30], NomArch2[30], numVolumen[4], valor[3], c;
int numPartes, tamArch, conteoBytes;
float tamPartes;

void generarVolumen(int i){
	int x;
	numVolumen[0]= '\0';
	numVolumen[0]= '.';

	snprintf(valor, 10,"%d", i);
	for(x=1; x<=(3-(strlen(valor))); x++) { numVolumen[x]= '0'; }
	numVolumen[x]= '\0';
	strcat(numVolumen, valor);
}

void Unir(){
	cout<< "Escriba el nombre del archivo con extencion .001: ";	cin>> NomArch2;
	arch2= fopen(NomArch2, "r");
	
	if(arch2 == NULL) { cout<<"Error"; }
	else{
		fclose(arch2);
		
		strncpy(NomArch, NomArch2, strlen(NomArch2)-4);
		NomArch2[0]= '\0';
		strcat(NomArch2, NomArch);
		
		arch= fopen(NomArch, "w");
		
		int i=0;
		do{
			i++;
			generarVolumen(i);
			
			NomArch2[0]= '\0';
			strcat(NomArch2, NomArch);
			strcat(NomArch2, numVolumen);
			
			arch2= fopen(NomArch2, "r");
			if(arch2 == NULL) break;
			while(!feof(arch2)){
				c= fgetc(arch2);
				//if(c!='ÿ'); 
				putc(c, arch);
			}
			fclose(arch2);	
		}while(1);
		fclose(arch);
	}
}

void Separar(){
	cout<<"Ingresa el nombre del archivo: ";	cin>>NomArch;
	cout<<"\nVista preliminar del archivo\n------------------------------------\n";
	
	arch= fopen(NomArch, "r");
	if(arch==NULL){
		cout<<"El archivo " <<NomArch <<" no existe!" <<endl;
	}else{
		
		while(feof(arch) == 0){
			c= fgetc(arch);
			cout<<c;
		}
		cout<<"\n------------------------------------\n";
	
		//poner el apuntador al final del archivo
		fseek(arch, 0, SEEK_END);
	
		cout<< "Tamano: " <<ftell(arch) <<" bytes" <<endl;
		tamArch= ftell(arch);
	
		//Poner el apuntador al inicio
		fseek(arch, 0, SEEK_SET);
	
		cout<<"\nEn cuantas partes desea dividir el archivo? : ";	cin>> numPartes;
		tamPartes= tamArch/numPartes;
	
		cout<<"Tamano de las partes divididas: " <<tamPartes <<endl;
	
		cout<<"Se esta dividiendo el archivo con extension " << numVolumen;
			cout<<"\nPress to continue...";		cin.get();
		
		for(int i=1; i<=numPartes; i++){
			generarVolumen(i);
			
			

			//se inicializa NomArch2 como cadena vacia
			NomArch2[0]='\0';
	
			//se anade el nombre de archivo original
			strcat(NomArch2, NomArch);

			//se le agrega
			strcat(NomArch2, numVolumen);


			arch2= fopen(NomArch2, "w");
			conteoBytes= 1;
			
			
			while(!feof(arch)){
				if((conteoBytes <= tamPartes) || (numPartes == i)){
				c= fgetc(arch);
				//if(c!='ÿ')
				putc(c, arch2);
				conteoBytes++; 
			}
			else
				break;
			}
		fclose(arch2);
		}
	}
}

int main(){
	int opc;
	system("/usr/bin/clear");
	
	cout<<"Opcion:\n1) Separar\n2) Unir\n3) Salir";		
	cout<<"\n\nEleccion[ ]\b\b";	cin>>opc;
	
	switch(opc){
		case 1: Separar();
		break;
		
		case 2: Unir();
		break;
		
		default: cout<<"Adios";
	}
	return 0;
}
