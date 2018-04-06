#include <iostream>
#include <stdlib.h>
#define MAX 100

using namespace std;
typedef int TipoDato;

struct Cola{
	int Frente, Final;
	TipoDato elementos[MAX];
};

typedef struct Cola TipoCola;

void inicializar(TipoCola &c){
	c.Frente= -1;
	c.Final= -1;
};

int colaVacia(TipoCola c){
	if((c.Frente == -1)&&(c.Final == -1)){
		return 1;
	}else{
		return 0;
	}
}

int colaLlena(TipoCola c){
	if(c.Final == MAX-1)
		return 1;
	else
		return 0;
}

void insertarCola(TipoCola &c, TipoDato x){
	if(colaLlena(c) == 0){
		if(colaVacia(c) == 1){
			c.Final ++;
			c.Frente ++;
		}else{
			c.Final ++;
		}
		c.elementos[c.Final]= x;
	}else{
		cout<<"No hay espacio";
	}
}

void mostrarCola(TipoCola c){
	int i;
    cout<<"[";
	for(i=c.Frente; i<= c.Final; i++){
        cout<<c.elementos[i]<< " ";
	}
    cout<<"]\b";
};

TipoDato eliminarCola(TipoCola &c){
	TipoDato x;
	if (colaVacia(c) == 0)
	{
		x = c.elementos[c.Frente];
		if (c.Frente == c.Final)
			inicializar(c);
		else
			c.Frente++;
	}
	return x;
}

int main(){
    TipoCola x;
	inicializar(x);

	TipoDato t= 0, pca= 0, pcb= 0, pcc= 0;
        /*int pc1 = 0;
	    int pc2 = 0;
	    int pc3 = 0;*/

	cout<< "Computadoras super epicas  [3]" <<endl;
    cout<<"PC 1= 5s \nPC 2= 10s \nPC 3= 15s\n" <<endl;

	while (t <= 60){
		if (pca==5){
			insertarCola(x, 1);
			pca=0;
        }

		if (pcb==10){
			insertarCola(x, 2);
			pcb=0;
        }

		if (pcc==15){
			insertarCola(x, 3);
			pcc=0;
        }

		t= t+5;
		pca= pca+5;
		pcb= pcb+5;
		pcc= pcc+5;
	}
	cout<<"                Tiempo de retorno!" <<endl;
	mostrarCola(x);
}
