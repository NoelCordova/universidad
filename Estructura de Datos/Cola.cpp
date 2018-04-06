#include <iostream>
#include <stdlib.h>
#define MAX 20

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

	for(i=c.Frente; i<= c.Final; i++)
    cout<<"  " <<c.elementos[i]<< " ";
	cout<<"\nFrente= " <<c.Frente <<endl;
	cout<<"Final= " <<c.Final <<endl;
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
	TipoDato i, y, opc, n;

	do{
        cout<<"   Ingreso de datos a una cola :3\n" <<endl;
        cout<<" // 1) Insertar cola\n // 2) Eliminar dato\n // 3) Mostrar\n // 4) Salir\n\n  Opcion [ ]\b\b";
		cin>>opc;

		switch (opc){
		case 1: cout<<"\n  Cuantos datos deseas ingresar?: ";
                cin>>n;

                for(i=0; i<n; i++){
                    cout<<"  Dato " <<i+1 <<": ";
                    cin>>y;
                    insertarCola(x, y);
                }
                break;

		case 2: cout<<"\nDato eliminado: " << eliminarCola(x) << "\n";
                break;

		case 3: mostrarCola(x);
                break;

		default: cout<<"ADIOS! :)" <<endl;
                break;
		}
		system("pause");
		system("cls");

    }while(opc <4);
}
