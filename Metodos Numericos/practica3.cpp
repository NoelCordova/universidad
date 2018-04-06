#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int opc, opc2, m, b, m2, b2, x, y;
	int a[4][4], x2, y2, z, r, determinante;
	
	system("/usr/bin/clear");
	cout<<"\tElija la forma en que desea evaluar la ecuacion\n\t1) y= mx + b\t2) x + y + z= a";
	cout<<"\n\n\tOpcion [ ]\b\b"; 	cin>>opc;
	
	
	switch(opc){
		case 1: 
		
			system("/usr/bin/clear");		//limpia pantalla
			cout<<"Forma de la ecuacion:   y= mx + b" <<endl;
	
			//lectura de datos para la primer ecuacion
			cout<<"\nPrimer ecuacion!";					
			cout<<"\nIngrese el valor para m: "; 	cin>> m;
			cout<<"Ingrese el valor para b: ";	cin>> b;
				
			//lectura de datos para la segunda ecuacion
			cout<<"\nSegunda ecuacion!";
			cout<<"\nIngrese el valor para m: "; 	cin>> m2;
			cout<<"Ingrese el valor para b: ";	cin>> b2;
	
			system("/usr/bin/clear");
			//impresion de ecuaciones
			if(b > 0) {cout<<"Ecuacion 1:  y= " <<m <<"x +" <<b <<endl;}
			else {cout<<"Ecuacion 1:  y= " <<m <<"x " <<b <<endl;}
			if(b2 > 0) {cout<<"\nEcuacion 2:  y= " <<m2 <<"x +" <<b2 <<endl;}
			else {cout<<"\nEcuacion 2:  y= " <<m2 <<"x " <<b2 <<endl;}

			if(m == m2 && b == b2){		//Sobrepuestas
				cout<<"\nEl sistema no tiene solucion, las lineas son sobrepuestas." <<endl;
				
				cout<<"\nVolver a realizar este metodo?\n1) Si\n2) No";
				cout<<"\n\nOpcion[ ]\b\b"; 	cin>>opc2;
			}else if(m == m2){			//Paralelas
				cout<<"\nEl sistema no tiene solucion, las lineas son paralelas." <<endl;
			}
		break;
		
		case 2:
			system("/usr/bin/clear");
	
			for(int i=1; i<=3; i++){
				cout<<"\n";
				for(int j=1; j<=4; j++){
					system("/usr/bin/clear");
					cout<<"Ingrese los valores indicados..." <<endl;
					cout<<"\nPosicion [" <<i <<"] [" <<j <<"] : ";
					cin>> a[i][j];
				}
			}
	
			system("/usr/bin/clear");
			cout<<"La ecuacion a utilizar es: \n";

			for(int i=1; i<=3; i++){
				cout<<"\n";
				cout<<"[ ";
				for(int j=1; j<=3; j++){
					cout<< a[i][j] <<" ";
				}
				cout<<"]";
				cout<< " = [ " << a[i][4] << " ]";
			}
	
			cout<<"\n\n";
	
			determinante= ((a[1][1]*a[2][2]*a[3][3]) + (a[1][2]*a[2][3]*a[3][1]) + (a[1][3]*a[2][1]*a[3][2]) - (a[1][3]*a[2][2]*a[3][1]) - (a[1][2]*a[2][1]*a[3][3]) - (a[1][1]*a[2][3]*a[3][2]));
	
			if(determinante != 0){
				cout<<"El determinante es: " <<determinante <<", si se puede proceder :)" <<endl;
		
				x2= (((a[1][4]*a[2][2]*a[3][3]) + (a[1][2]*a[2][3]*a[3][4]) + (a[1][3]*a[2][4]*a[3][2]) - (a[1][3]*a[2][2]*a[3][4]) - (a[1][2]*a[2][4]*a[3][3]) - (a[1][4]*a[2][3]*a[3][2]))/determinante);
				y2= (((a[1][1]*a[2][4]*a[3][3]) + (a[1][4]*a[2][3]*a[3][1]) + (a[1][3]*a[2][1]*a[3][4]) - (a[1][3]*a[2][4]*a[3][1]) - (a[1][4]*a[2][1]*a[3][3]) - (a[1][1]*a[2][3]*a[3][4]))/determinante);
				z= (((a[1][1]*a[2][2]*a[3][4]) + (a[1][2]*a[2][4]*a[3][1]) + (a[1][4]*a[2][1]*a[3][2]) - (a[1][4]*a[2][2]*a[3][1]) - (a[1][2]*a[2][1]*a[3][4]) - (a[1][1]*a[2][4]*a[3][2]))/determinante);
		
				cout<<"\nEl punto de cruce: (" <<x2 <<", " <<y2 <<", " <<z <<")" <<endl;
			}else{
				cout<<"El determinante es: " <<determinante <<"\nError! el determinanante tiene que ser mayor a 0" <<endl;
			}
		break;
	}	
}
