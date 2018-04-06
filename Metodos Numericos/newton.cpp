#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void despeje1(int cons[], int exp[], int constante){
	float x= 0, res= 1, d1, d2;	//Declaracion de variables
	int  diferencia, k= 0;
	
	cout<<"k\tx\n--------------------------\n";
	
	while(x != res){	//Condicion para que termine el programa si se repiten
		diferencia= x - res;	//se van guardando los resultados
		
		if((diferencia < -100) || (diferencia > 100)){	//Condicion para resultados que se alejan
			cout<<"\nLa ecuacion 1 no tiene raiz, el valor se aleja!" <<endl;
			return;
		}
		
		x= res;		//Se guarda el resultado
		cout<<k <<"\t" <<x <<endl;
		d1= ((-cons[2] * pow(x,exp[2])) + (-cons[1] * pow(x,exp[1])) -constante)/cons[3];	//Se aplica el punto fijo
		
		if((d1 < 0) && (exp[3]%2 == 0)){	//Condicion para resultados negativos
			cout<<"\nLa ecuacion 1 no tiene raiz, no hay raices pares negativas!" <<endl;
			return;
		}
		
		if((d1 < 0) && (exp[3]%2 != 0)){	//Se va llenando la tabulacion
			d2= pow(-d1, 1.0/exp[3]);
			res= -d2;
		}else{
			d2= pow(d1, 1/exp[3]);
			res= d2;
		}
		k++;	//Es una variable contador, y se incrementa
	}
}

void despeje2(int cons[], int exp[], int constante){	//Mismo procedimiento que el anterior
	float x= 0, res= 1, d1, d2;
	int  diferencia, k= 0;
	
	cout<<"k\tx\n--------------------------\n";
	
	while(x != res){
		diferencia= x - res;
		
		if((diferencia < -100) || (diferencia > 100)){
			cout<<"\nLa ecuacion 2 no tiene raiz, el valor se aleja!" <<endl;
			return;
		}
		
		x= res;
		cout<<k <<"\t" <<x <<endl;
		d1= ((-cons[3] * pow(x,exp[3])) + (-cons[1] * pow(x,exp[1])) -constante)/cons[2];
		
		if((d1 < 0) && (exp[2]%2 == 0)){
			cout<<"\nLa ecuacion 2 no tiene raiz, no hay raices pares negativas!" <<endl;
			return;
		}
		
		if((d1 < 0) && (exp[2]%2 != 0)){
			d2= pow(-d1, 1.0/exp[2]);
			res= -d2;
		}else{
			d2= pow(d1, 1/exp[2]);
			res= d2;
		}
		k++;
	}
}

void despeje3(int cons[], int exp[], int constante){	//Mismo procedimiento que el anterior
	float x= 0, res= 1, d1, d2;
	int  diferencia, k= 0;
	
	cout<<"k\tx\n--------------------------\n";
	
	while(x != res){
		diferencia= x - res;
		
		if((diferencia < -100) || (diferencia > 100)){
			cout<<"\nLa ecuacion 3 no tiene raiz, el valor se aleja!" <<endl;
			return;
		}
		
		x= res;
		cout<<k <<"\t" <<x <<endl;
		d1= ((-cons[3] * pow(x,exp[3])) + (-cons[2] * pow(x,exp[2])) -constante)/cons[1];
		
		if((d1 < 0) && (exp[1]%2 == 0)){
			cout<<"\nLa ecuacion 3 no tiene raiz, no hay raices pares negativas!" <<endl;
			return;
		}
		
		if((d1 < 0) && (exp[1]%2 != 0)){
			d2= pow(-d1, 1.0/exp[1]);
			res= -d2;
		}else{
			d2= pow(d1, 1/exp[1]);
			res= d2;
		}
		k++;
	}
}
	

void newton(int cons[], int exp[], int constante){
	float xn, res, fx, dx;	//Declaracion de variables
	
	while(xn != res){	//Condicion para que termine el programa si se repiten
		xn= res;		//Se van remplazando los valores
		fx= (cons[3] * pow(xn, exp[3])) + (cons[2] * pow(xn, exp[2])) + (cons[1] * pow(xn, exp[1])) + constante; //Se calcula la f(x)
		dx= ((cons[3] * exp[3]) * pow(xn, exp[3]-1)) + ((cons[2] * exp[2]) * pow(xn, exp[2]-1)) + ((cons[1] * exp[1]) * pow(xn, exp[1]-1)); //Se deriva f(x)
				
		if(dx==0){	//Condicion si resultado es 0
			cout<<"\nEl resultado es 0, no tiene raiz.\n" <<endl;
			return;
		}
				
		res= xn - (fx/dx);	//Se calcula el valor
		cout<<"\t"<<xn <<"\t\t"; cout<<"\t"<<res <<endl; //Se imprime el resultado
	}
}

int main(){
	int opc, cons[3], exp[3], constante, xn, res, fx, dx;	//Declaracion de variables
	
	system("/usr/bin/clear");	//Comando para limpiar pantalla en linux
	for(int i=3; i>=1; i--){	//Ciclo paara ir guardando los valores
				cout<<"Dame el valor de la constante [" <<i <<"] :";	cin>>cons[i]; //Valores de constante
				
				if(i != 10){
					cout<<"Dame el valor del exponente [" <<i <<"] :";	cin>>exp[i]; //Valores de exponentes
				}
				cout<<"\n";
			}
			cout<<"Dame el valor de la constante: ";	cin>>constante; //Constante sin exponente
			
	system("/usr/bin/clear");	
	cout<<"\nLa ecuacion a utilizar es: [" <<cons[3] <<"x^" <<exp[3] <<"] + [" <<cons[2] <<"x^" <<exp[2] <<"] + [" <<cons[1] <<"x^" <<exp[1] <<"] + [" <<constante <<"]"; //Imprime ecuacion a evaluar
	
	cout<<"\n\n1) Punto fijo\n2) Newton\nOpcion [ ]\b\b"; cin>>opc;	//Menu de usuario
	
	switch(opc){
		case 1:{system("/usr/bin/clear");		//Inicia el proceso 1
			despeje1(cons, exp, constante);		//Se llama al primer metodo
			cout<<"\n-----------------------\n";
			despeje2(cons, exp, constante);		//se llama segundo metodo
			cout<<"\n-----------------------\n";
			despeje3(cons, exp, constante);		//Se llama al tercer metodo
		}
		break;
		
		case 2:{ system("/usr/bin/clear");		//Inicia el proceso 2
			
			cout<<"Ecuacion 1: x = " <<"("<<-cons[2] <<"x^"<<exp[2] <<" " <<-cons[1] <<"x^" <<exp[1] <<" " <<-constante <<")" <<"^" <<"(1/" <<exp[3] <<")\n" <<endl; //Ecuacion equivalente
			cout<<"Ecuacion 2: x = " <<"("<<-cons[3] <<"x^"<<exp[3] <<" " <<-cons[1] <<"x^" <<exp[1] <<" " <<-constante <<")" <<"^" <<"(1/" <<exp[2] <<")\n" <<endl; //Ecuacion equivalente
			cout<<"Ecuacion 3: x = " <<"("<<-cons[3] <<"x^"<<exp[3] <<" " <<-cons[2] <<"x^" <<exp[2] <<" " <<-constante <<")" <<"^" <<"(1/" <<exp[1] <<")\n" <<endl; //Ecuacion equivalente
			
			newton(cons, exp, constante); //Se llama al metodo
		}
	}
}
