#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void insercion(char proceso[], int tiempo[]){
    for(int i = 0; i < 5; i++){
        cout<<"Ingrese el tiempo para el proceso '" << proceso[i] <<"' : ";
        cin>>tiempo[i];
    }
 }

 void FIFO(){
    int v, suma= 0;
    float prom = 0.0;

	cout<<"Cual es el numero de casillas que ocuparas? : ";
	cin>> v;
	int a[v];

	for(int cont= 0; cont < v; cont++){
		cout<<"Numero de la casilla #" <<cont+1 <<": ";
		cin>> a[cont];
	}

    system("cls");
	for(int cont= 0; cont < v; cont++){
        suma= a[cont] + suma;
        cout<<"Tiempo de retorno en #" <<cont+1 <<": " <<suma <<endl;
        prom+=suma;
    }
    prom=prom/v;
    cout<<"\n\nPromedio: " <<prom <<endl;
    getch();
}

 void RR(char proceso[], int tiempo[]){
    int quantum= 0, t= 0;
    float TRP = 0.0;

    insercion(proceso, tiempo);
    for (int i= 0; i<5; i++) {quantum+= tiempo[i];}
    quantum= quantum/5;
    system("cls");

    cout<<"El valor del numero Quantum es: " <<quantum <<"\n\n";
    for(int i= 0; i<5; i++){
        if(quantum >= tiempo[i]){
            t+= tiempo[i];
            TRP+= t;
            tiempo[i]= 0;
            cout<<"El tiempo de retorno de '" <<proceso[i] <<"' es: " <<t <<endl;

        }else{
        t= t + quantum;
        tiempo[i]-= quantum;
        }
    }

    for(int i =0; i<5; i++){
        if(tiempo[i] != 0){
         t= t + tiempo[i];
         TRP += t;
         cout<<"El tiempo de retorno de '" <<proceso[i] <<"' es: " <<t <<endl;
        }
     }

     TRP= TRP /5;
     printf("\nTRP de Round Robin %.1f\n", TRP);
     getch();
    }


void sfc(int d[], int v){
    int aux;
	float prom= 0;

	for (int con1= 1; con1 < v; con1++){
		for(int con2 = 0; con2 < v-1 ; con2++){
			if(d[con2] > d[con2+1]){
				aux= d[con2];
				d[con2]= d[con2+1];
				d[con2+1]= aux;
			}
		}
	}

	aux=0;
	for(int con1= 0; con1 < v; con1++){
		aux+=d[con1];
		prom+=aux;
		cout<<"Tiempo de retorno en #" <<d[con1] <<": " <<aux <<endl;
	}

	prom= prom/v;
	cout<<"\n\nPromedio: " <<prom <<endl;
	getch();
}

void SJF(){
    int v, suma= 0;
    float prom = 0.0;

	cout<<"Cual es el numero de casillas que ocuparas? : ";
	cin>> v;
	int a[v];

	for(int cont= 0; cont < v; cont++){
		cout<<"Numero de la casilla #" <<cont+1 <<": ";
		cin>> a[cont];
	}
    system("cls");
	sfc(a, v);
}

void prioridad(int mat[], int pro){
	int con=0, tf=0, aux, final[5], c[]={5, 4, 3, 2, 1}, com[5]={5, 4, 3, 2, 1}, co;
	float prom=0;

	while(con!=5){
        if(mat[con] <= pro || con==4){
        tf+= mat[con];
        final[con]= tf;
        com[con]= 0;
        con++;
    }else{
        com[con]-=1;
        mat[con]-=pro;
        tf+=pro;

            for(co= con; com[co]<=com[co+1] && co<4; co++){
				aux= mat[co];
				mat[co]= mat[co+1];
				mat[co+1]= aux;
				aux= com[co];
				com[co]= com[co+1];
				com[co+1]= aux;
				aux= c[co];
				c[co]= c[co+1];
				c[co+1]= aux;

            }
        }
    }
    system("cls");

	for(con=0; con<5; con++){
		prom+=final[con];
		cout<<"Tiempo de retorno en #" <<c[con] <<": " <<final[con] <<endl;
	}

	prom/=5;
	cout<<"\n\nPromedio: " <<prom <<endl;
	getch();
}


main(){
	int opc;
	do{
        system("cls");
        cout<<"       -- PLANIFICACION DE PROCESOS! --       \n";
		cout<<"   \n\nEscoja un medio de planificacion   "<< endl;
		cout<<"   1. FIFO\n";
		cout<<"   2. SJF\n";
		cout<<"   3. Round Robin\n";
		cout<<"   4. Prioridad\n";
		cout<<"   5. Salir\n";
		cout<<"   \n\nOpcion [ ]\b\b";
		cin >> opc;
        system("cls");

		switch(opc){
			case 1:
				FIFO();
			break;
			case 2:
				SJF();
			break;
			case 3: {
			    char proceso[]={'A','B','C','D','E'};
                int tiempo [5];
                RR(proceso, tiempo);
                break;
                }

			case 4:
			    int pri, num, ma[5]={0, 0, 0, 0, 0}, cont=0, sum=0;
                cout<<"Ingresa los 5 datos: \n";
                while(cont<5){

                    cout<<" Tiempo: "; cin>> num;
                    cout<<" Prioridad: "; cin>> pri;

                    if(pri<6 && pri>0){
                        if(ma[(-pri)+5]== 0){
                        ma[(-pri)+5]= num;
                        sum+=num;
                        cont++;
                        }
                        else
                        printf("Lo siento ya haz insertado un numero");
                    }
                    else
                    printf("Ese numero de prioridad esta fuera de los rangos");
                }
                sum=sum/5;
                prioridad(ma, sum);

                break;
		}
	}while(opc<=4);
	printf("Hasta pronto! :)");
}
