#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>

#define CTRL_IZQUIERDA 75
#define CTRL_DERECHA 77
#define CTRL_ARRIBA 72
#define CTRL_ABAJO 80

using namespace std;

void matrizCeros(int array[100][100], int i, int j){
	for(i=1; i<=10; i++){
		for(j=1; j<=10; j++){
			array[i][j]= 0;
		}
	}
}

void matrizUnos(int array[100][100], int i, int j){
	array[i-1][j-1]= 1; 	array[i-1][j]= 1; 	array[i-1][j+1]= 1;
	array[i][j-1]= 1; 		array[i][j]= 1;		array[i][j+1]= 1;
	array[i+1][j-1]= 1; 	array[i+1][j]= 1; 	array[i+1][j+1]= 1;
}

void sumaMatriz(int array[100][100], int i, int j){
	array[i-1][j-1]= array[i-1][j-1]+1; 	array[i-1][j]= array[i-1][j]+1; 	array[i-1][j+1]= array[i-1][j+1]+1;
	array[i][j-1]= array[i][j-1]+1; 		array[i][j]= array[i][j]+1; 		array[i][j+1]= array[i][j+1]+1;
	array[i+1][j-1]= array[i+1][j-1]+1; 	array[i+1][j]= array[i+1][j]+1; 	array[i+1][j+1]= array[i+1][j+1]+1;
}

void imprimirMatriz(int array[100][100], int i, int j){
	for(int i=1; i<=10; i++){
		cout<<endl <<endl;
		for(int j=1; j<=10; j++){
			cout<<array[i][j] <<" " <<" ";
		}
	}
}

void fueraRango(int array[100][100], int i, int j){
	for(i=1; i<=10; i++){
		for(j=1; j<=10; j++){
			if(array[i][j] == 9)
			array[i][j]= 0;
		}
	}
}

main(){
	srand(time(NULL));
	int array[100][100], i= rand()%10+1, j= rand()%10+1;
	bool fin= false;
	
	matrizCeros(array, i, j);
	matrizUnos(array, i, j);
	imprimirMatriz(array, i, j);
	
	while(!fin){
		if(kbhit()){
			char tecla= getch();
			
			if(tecla == CTRL_IZQUIERDA){
				system("cls");
				fueraRango(array, i, j);
				j= j-1;
				if(j-1 == 0) j= j+10;
				sumaMatriz(array, i, j);
				imprimirMatriz(array, i, j); }
				
			if(tecla == CTRL_DERECHA){
				system("cls");
				fueraRango(array, i, j);
				j= j+1;
				if(j+1 == 11) j= j-10;
				sumaMatriz(array, i, j);
				imprimirMatriz(array, i, j); }
				
			if(tecla == CTRL_ARRIBA){
				system("cls");
				fueraRango(array, i, j);
				i= i-1;
				if(i-1 == 0) i= i+10;
				sumaMatriz(array, i, j);
				imprimirMatriz(array, i, j); }
				
			if(tecla == CTRL_ABAJO){
				system("cls");
				fueraRango(array, i, j);
				i= i+1;
				if(i+1 == 11) i= i-10;
				sumaMatriz(array, i, j);
				imprimirMatriz(array, i, j); }
		}
	}
	
	cout<<endl;
	system("pause");
}
