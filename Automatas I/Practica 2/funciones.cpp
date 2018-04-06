#include "funciones.h"
#include <iostream>

using namespace std;

int lenght(char *a){
	int i= 0;
	
	while(a[i] != '\0'){
		if(a[i] !='\0')	i++;	
	}
	return i;
}

int delta(int state, char c){
	switch(state){
		case 0:
			if(c >= '0' && c <= '9') return 1;
			if(c == '.' || c =='e' || c == 'E' || c == '+' || c == '-') return -1;
			break;

		case 1:
			if(c >= '0' && c <= '9') return 1;
			if(c == '.') return 2;
			if(c == 'e' || c == 'E') return 3;
			if(c == '+' || c == '-') return -1;
			break;

		case 2:
			if(c >= '0' && c <= '9') return 4;
			if(c == '.' || c == 'e' || c == 'E' || c == '+' || c == '-') return -1;
			break;

		case 3:
			if(c >= '0' && c <= '9') return 6;
			if(c == '+' || c == '-') return 5;
			if(c == 'e' || c == 'E') return -1;
			break;

		case 4:
			if(c >= '0' && c <= '9') return 4;
			if(c == 'e' || c == 'E') return 3;
			if(c == '.' || c == '+' || c == '-') return -1;
			break;

		case 5:
			if(c >= '0' && c <= '9') return 6;
			if(c == '.' || c == 'e' || c == 'E' || c == '+' || c == '-') return -1;
			break;

		case 6:
			if(c >= '0' && c <= '9') return 6;
			if(c == '.' || c == 'e' || c == 'E' || c == '+' || c == '-') return -1;
			break;
			
		case 7:
			if(c != (c >= '0' && c <= '9' || c == '.' || c == 'e' || c == 'E' || c == '+' || c == '-')) return -1;
			
		default:
			return -1;
			break;
	}
}

int cont= 0;
int process(int a, char *c){
	
	cout<<"Init" <<"   [" <<a <<"]  :  " <<c[cont] <<endl;
	
	for(; cont<lenght(c); cont++){
		if(a != -1){
			a= delta(a, c[cont]);
			if(a == 1 || a== 4 || a==6){
				cout<<"Estado [" <<a <<"]  :  " <<c[cont+1] <<"  :  Aceptado"<<endl;	
			} else cout <<"Estado [" <<a<<"]  :  " <<c[cont+1] <<endl;
		}
		//else cout<<"Estado ["<<a<<"]"<<endl;	
	}
	return a;
}

bool test(char *c){
	int init= 0, state;
	
	state= process(init, c);
	
	if(state == 1 || state == 4 || state == 6){
		//cout<<"Estado [" <<state <<"] : " <<c <<"true";
		return true;
	}else return false;
}

