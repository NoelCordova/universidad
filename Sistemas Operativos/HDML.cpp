#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	FILE *arch;
	char archivo[30], buffer[20], b, c;
	int direccion, cont1, cont2, i;

	cout<< "Ingresa el nombre del archivo a procesar: "; cin>> archivo;

	arch= fopen(archivo, "r");

	cout<< "\nVolcado en Hexadecimal del archivo: " << archivo <<endl;
	cout<< "\nDireccion\tValores Hexadecimales" <<endl;
	cout<< "------------\t-----------------------------------------\t----------------" <<endl;

	direccion= 0;

	while((cont1= fread(buffer, sizeof(unsigned char), 16, arch))>0){
		cout<< "%5d" <<direccion << "%08lx" <<direccion;

		direccion = direccion + 16;

		//impresion de caracteres en hexadecimal
		cont2 = 0;
		cout<<"\t";
		for ( i = 0; i < 16; i++){
			cont2 = cont2 + 1;

			
			if (cont2 <= cont1)
				cout<< "%02x" <<buffer[i];
				//printf ("%02x ", buffer[i] );
			else
				cout<< " ";
		}

		//bloque de los caracteres ascci
		cont2 = 0 ;
		for ( i = 0; i < 16; i++ ){
			cont2 = cont2 + 1;

			if ( cont2 <= cont1){
				if ((buffer [i] < 32 )||(buffer [i] > 126) )
					cout<< "\t.";
					//printf ("%c", '.');
				else
					cout<< "\t" <<buffer[i];
					//printf("%c", buffer[i]);
			}
		}
		printf("\n");

	}

printf("\n\n");

fclose(arch);

//system("pause");
 }


