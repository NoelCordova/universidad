#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

FILE *arch;
char c;

int minuscula(char c){
	if(islower(c)) return 1;
	else return 0;
};

int mayuscula(char c){
	if(isupper(c)) return 1;
	else return 0;
};

int palabra(char c){
	if((minuscula(c)==1) || (mayuscula(c)==1))
		return 1;
	else
		return 0;
};

int vocal(char c){
	if(palabra(c)==1){
		c= toupper(c);
		if((c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U'))
			return 1;
		else
			return 2;
	}else
	 return 0;
};

int numero(char c){
	if(isdigit(c)) return 1;
	else return 0;
};

int space(char c){
	if(isspace(c)) return 1;
	else return 0;
};

int simbolo(char c){
	if((palabra(c)!= 1) || (numero(c)!=1))
		return 1;
	else
		return 0;
};

int im(char c){
	if(simbolo(c)==1){
		if(c>=0 && c<32)
			return 1;
		else
			return 2;
	}
};

int signo(char c){
	if(ispunct(c)) return 0;
	else return 0;
};


int linea(char c){
	if(c==10)
		return 1;
	else
		return 0;
};

int main(){
	int let= 0, min= 0, may= 0, voc= 0, con= 0, num= 0, esp= 0, sim= 0, noimp= 0, punt= 0, imp= 0, lin= 0;
	
	cout<< endl;	
	arch = fopen("Hello.txt", "r");
	//system("cls");

	while (feof(arch)==0){
		c= fgetc(arch);
		cout<<c;
		let+= palabra(c);
		min+= minuscula(c);
		may+= mayuscula(c);

			if(vocal(c)!=0){
				if(vocal(c)==1)
					voc++;
				else
					con++;
			}

		num+= numero(c);
		esp+= space(c);
		sim+= simbolo(c);

		if(im(c)!=0){
			if(im(c)==1)
				noimp++;
			else
				imp++;
		}

		punt+=signo(c);
		lin+=linea(c);
	}

	fclose (arch);

	cout<<"\n\nNumero de letras: " <<let <<"\nMayuscula: " <<may <<"\nMinuscula: " <<min <<"\nVocales: " <<voc;
	cout<<"\nConstante: " <<con <<"\nNumero: " <<num <<"\nEspacios: " <<esp <<"\nSimbolos: " <<sim;
	cout<<"\nSimbolos Imprimibles: " <<imp <<"\nSimbolos No Imprimibles: " <<noimp <<"\nSignos de puntuacion: " <<punt <<"\nLinea: " <<lin <<endl;
}
