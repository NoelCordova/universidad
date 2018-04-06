#include <iostream>
#include <stdlib.h>

using namespace std;

int i, j, mA[3][3], mB[3][3], mC[3][3];

int matriz(){
	for(i=1; i<4; i++){
    	for(j=1; j<4; j++){
    		
    		cout<<"Ingrese la posicion " <<"(" <<i <<")" <<"(" <<j <<")" <<" de la matriz A: ";
            cin >>mA[i][j]; 
    	}
    }
	system("cls");

	for  (i=1; i<4; i++){
        for  (j=1; j<4; j++){
        	
            cout<<"Ingrese la posicion " <<"(" <<i <<")" <<"(" <<j <<")" <<" de la matriz B: ";
            cin >>mB[i][j];
        }
    }
    system("cls");
	
}

void Suma(){
	for(i=1; i<4; i++){
		for(j=1; j<4; j++){
		mC[i][j]= (mA[i][j] + mB[i][j]);
				cout<<mC[i][j] <<" ";
		}cout<<"\n";
	}
}

void Resta(){
	for(i=1; i<4; i++){
		for(j=1; j<4; j++){
		mC[i][j]= (mA[i][j] - mB[i][j]);
				cout<<mC[i][j] <<" ";
		}cout<<"\n";
	}
}

void Multiplicacion(){
	for(i=1; i<4; i++){
		for(j=1; j<4; j++){
		mC[i][j]= (mA[i][j] * mB[i][j]);
				cout<<mC[i][j] <<" ";
		}cout<<"\n";
	}
}

int main(){
	int opc;
	
	matriz();
	
	cout<<"Que operacion quiere realizar?" <<endl; 
    cout<<"1) Suma" <<endl <<"2) Resta" <<endl <<"3) Multiplicacion\n" <<endl;
    cout<<"Opcion: ";	cin>>opc;
	
	switch(opc){
	case 1: Suma(); break;
    case 2: Resta(); break;
	case 3: Multiplicacion(); break;
	}
	return 0;
}
