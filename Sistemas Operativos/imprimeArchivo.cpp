#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

FILE *arch;
char c;

main(){
	arch= fopen("Hello.txt", "r");
	
	if(arch == NULL){
		cout<<"Error. No se encontro el archivo";
		//system("pause >0");
	}else{
		
		//system("cls");
		
		while(feof(arch) == 0){
			c= fgetc(arch);
			cout<<c;
		}
	}
	
	fclose(arch);
	//system("pause >0");
	return 0;
}
