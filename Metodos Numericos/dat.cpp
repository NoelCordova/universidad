#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

main(){
	int valores;				//Variable
	system("/usr/bin/clear");	//Funcion que limpia pantalla en linux
	
	cout<<"Cuantos valores ingresaras? : ";		cin>>valores;	//Se pide el numero de filas para la tabla
	double listX[valores], listY[valores], mediaX, mediaY, sumListX;	//Listas que se adaptan al tamaño anterior
	double sumListY, newX, newX2, b0, b1;	//Variables
	
	system("/usr/bin/clear");
	cout<<"Valores que ingresaras: " <<valores <<endl;		//Recordatorio 
	for(int i=1; i<=valores; i++){
		cout<<"\nValor en X [" <<i <<"] : "; 	cin>>listX[i];	//Ingreso de datos para X
		cout<<"Valor en Y [" <<i <<"] : ";		cin>>listY[i];	//Ingreso de datos para Y
		
		mediaX+= listX[i];	//Se hace la sumatoria de la lista X
		mediaY+= listY[i];	//Se hace la sumatoria de la lista Y
	}
	
	mediaX/=valores;	//Calculo de la media de X
	mediaY/=valores;	//Calculo de la media de Y
	
	system("/usr/bin/clear");
	cout<<"\tLista X\t\t\tLista Y\t\t(X - Media X) * (Y - Media Y)\t\t(X - Media X)²" <<endl;
	
	for(int i=1; i<=valores; i++){
		newX= (listX[i]-mediaX) * (listY[i]-mediaY);	//Se calcula la primera ecuacion (X - Media X) * (Y - Media Y)
		newX2= pow(listX[i]-mediaX,2);					//Se calcula la segunda ecuacion (X - Media X)²
		cout<<"\n"<<i <<".\t" <<listX[i] <<"\t\t\t"<<listY[i] <<"\t\t" <<newX <<"\b\t\t\t\t\t" <<newX2;	//Se llena la tabla
		
		sumListX+=newX;		//Sumatoria de la primera ecuacion
		sumListY+=newX2;	//Sumatoria de la segunda ecuacion
	}
	cout<<"\n------------------------------------------------------------------------------------------------------------" <<endl;
	cout<<"\t" <<mediaX <<"\t\t\t" <<mediaY <<"\t\t" <<sumListX <<"\b\t\t\t\t\t" <<sumListY; //Se muestran las sumatorias
	
	b1= sumListX/sumListY;	cout<<"\n\nB1 = " <<b1 <<endl;	//Se calcula y se imprime el resultado de B1
	b0= mediaY-(b1*mediaX);		cout<<"B0 = " <<b0 <<endl;	//Se calcula y se imprime el resultado de B0
}
