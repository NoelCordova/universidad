#include <iostream> //librerias para c++
#include <cstdlib>
#include <cmath>

using namespace std;

main(){
	float x, constante, derivada, x0= 0, x1 =1;	//declaracion de variables
	
	system("/usr/bin/clear");	//Comando para  limpiar pantalla en linux
	cout<<"Ingresa el valor de la 'X': ";	cin>>x;		//Ingreso de datos
	cout<<"Ingresa el valor de la 'Constante': ";	cin>>constante;	//Ingreso de datos
	
	system("/usr/bin/clear");
	if(constante > 0){ cout<<"Ecuacion a utilizar [" <<x <<"x² + " <<constante <<"]"; }	//Condicion para escribir la ecuacion
	else { cout<<"Ecuacion a utilizar [" <<x <<"x² " <<constante <<"]"; }	//si es mayor a cero poner un +
	cout<<"\n\nx0\t\tDerivada\tx1" <<endl;
	
	while(x0 != x1){	//Condicion para que termine el proceso de raices
		x0= x1;			//Estas variables con una especie de contador para que se cumple la condicion del while
		
		derivada= (x * 2 * x0);	//Calculo de derivada
		if(derivada == 0) { cout<<"\nERROR! El resultado es 0, no existe la raiz de 0"; }	//mensaje de error si la derivada es 0
		
		x1= -pow(x*x0, 2) + constante;	//se empieza a aplicar la formula de raices complejas
		x1= -x1/derivada;
		x1= x0 - x1;		
		cout<<"\n" <<x0 <<"\t\t" <<derivada <<"\t\t" <<x1;
	}
	cout<<"\n\nEl resultado es: " <<x1 <<endl;	//Resultado final :)
}
