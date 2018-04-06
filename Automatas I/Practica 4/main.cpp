#include <iostream>
#include <map>

std::map<int, char> cinta;	//Cinta
std::map<int,char>::iterator it;

int cabezal= 0;		//Posicion de cabezal
int posMin= 0;		//Posicion minima encontrada
int posMax= 0;		//Posicion maxima encontrada


/*Funcion para leer el contenido de la casilla donde se ubica el cabezal*/
char read(){
	char c= cinta[cabezal];
	return c;
}


/*Se inserta un espacio en blanco al visitar una nueva casilla*/
void insert(int cab, char c= ' '){
	cinta.insert(std::pair<int,char>(cab, ' '));
	
	if(c=='1' || c=='0' && c!=0) cinta.at(cab)= c;
	if(cab < posMin) posMin= cab;
	if(cab > posMax) posMax= cab;
}


/*Implementacion de la primitiva R (derecha)*/
bool R(){
	cabezal++;
	insert(cabezal);
	return true;
}


/*Implementacion de la primitiva L (izquierda)*/
bool L(){
	cabezal--;
	insert(cabezal);
	return true;
}

/*Implementacion de primitiva Rn (x num de veces a la Derecha)*/
bool Rn(int num){
	int cont;
	
	for(cont=1; cont<=num; cont++) R();
	return true;
}


/*Implementacion de primitiva Ln (x num de veces a la Izquierda)*/
bool Ln(int num){
	int cont;
	
	for(cont=1; cont<=num; cont++) L();
	return true;
}


bool Rx(char x){
	for(; cabezal<=posMax; cabezal++){
		if(read()==x) return true;
	}
	return false;
}


bool Lx(char x){
	for(; cabezal>=posMin; cabezal--){
		if(read()==x) return true;
	}
	return false;
}


/*Funcion para imprimir la posicion del cabezal*/
void print(bool r){
	
	std::cout<<cabezal <<"\t\b\b\b\b:: \t\b[";
	
	for (it=cinta.begin(); it!=cinta.end(); ++it){
		
		if(cabezal==it->first) std::cout<<".";
		std::cout<<it->second;
	}
	
	std::cout<<"]" <<std::endl;
}


/*Maquina de Turing*/
void MT(){
	while(true){
		print(Ln(17));
		
		if(cinta[cabezal]==32){
			print(Rn(10));
			break;
		}
		
		if(read()==49){
			print(Rn(9));
			
			if(read()==49){
				print(Rn(9));
				insert(cabezal, 49);
				
			}else{
				print(Rn(9));
				insert(cabezal, 48);
			}
			
		}else{
			print(Rn(18));
			insert(cabezal, 48);
		}
	}
}


main(){
	
	char *str;
	str= new char[8];
	
	std::cout<<"Ingrese la cadena: ";	std::cin>>str;
	
	for(; cabezal<=7; cabezal++) insert(cabezal, str[cabezal]);
	delete str;
	
	insert(cabezal);
	
	str= new char[8];
	
	std::cin>>str;
	
	for(; cabezal<=16; cabezal++) insert(cabezal, str[cabezal-9]);
	delete str;
	
	system("cls");
	
	
	MT();
	
	system("pause>0");
}

