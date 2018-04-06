#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <list>
#include <string>
#include <stack>

using namespace std;

FILE *archivo;
map<string, map<string, list<string> > > tabla;
stack<string> pila;
char caracter;
int posicion_actual = 0, posicion_anterior = 0, num_lineas = 1, tk;

typedef enum {_id, th, eof, _er} token;

char siguiente(){

    char dato;
    dato = fgetc(archivo);
    posicion_actual = ftell(archivo);
    return dato;

}

void retroceso(){

    fseek(archivo, -1, SEEK_CUR);
    posicion_actual = ftell(archivo);

}

void aceptacion(){

    posicion_anterior = posicion_actual;

}

void rechazo(){

    posicion_actual = posicion_anterior;
    fseek(archivo, posicion_anterior, SEEK_SET);

}


int identifiers(){

    int estado_actual = 0, estado_anterior;
    char dato;
    string cadena = "";

    while(estado_actual != -1){

        estado_anterior = estado_actual;
        dato = siguiente();

        switch(estado_actual){

            case 0:
                if(dato == '_') estado_actual = 1;
                else if(isalpha(dato)) estado_actual = 2;
                else estado_actual = -1;
                break;

            case 1:
                if(dato == '_' || isdigit(dato)) estado_actual = 1;
                else if(isalpha(dato)) estado_actual = 2;
                else estado_actual = -1;
                break;

            case 2:
                if(isalpha(dato) || dato == '_' || isdigit(dato)) estado_actual = 2;
                else if(dato == '\'') estado_actual = 3;
                else estado_actual = -1;
                break;

            case 3:
                if(dato == '\'') estado_actual = 3;
                else estado_actual = -1;
                break;
        }

        if(estado_actual != -1) cadena = cadena + dato;
        
    }

    if(estado_anterior == 2 || estado_anterior == 3) {

        cout << "Cadena: " << cadena << endl;

        retroceso();
        aceptacion();

        if(cadena == "throw"){

            cout << "Es throw" << endl;
            return 2;

        }else{

            cout << "No es throw" << endl;
            return 1;

        }


    } else {

        cout << "ERROR en identifiers()" << endl;
        rechazo();
        return 0;

    }
}


bool white_space(){

    char dato;
    dato = siguiente();

    if((isspace(dato))){

        if(dato == '\n') num_lineas++;

        aceptacion();
        return true;

    }

    retroceso();
    return false;

}

bool end_file(){

    char dato;
    dato = siguiente();

    if(dato == EOF) return true;
    else return false;

}

token scanner(){

    while(white_space());
    if((identifiers()) == 1){

        cout << "Retorna _id" << endl;
        return _id;

    }

    else if((identifiers()) == 2){

        cout << "Retorna th" << endl;
        return th;

    }

    /*if((identifiers()) == 0){

        //cout << "ERROR" << endl;
        if(end_file()) return eof;
        return _er;

    }*/

    else if(end_file()) return eof;

    //if(end_file()) return eof;
    //else return _er;

}


int main(){

    char name_file[50];
    token t;

    /*do{

        cout << "Ingrese el nombre del archivo: ";  cin >> name_file;
        archivo = fopen(name_file, "r");

    }while(archivo == NULL);*/

    archivo = fopen("archivo.txt", "r");

    /*system("cls");
    cout << "Archivo seleccionado : " << name_file << endl;
    cout << "-------------------------------" << endl;*/
    
    do{
        t = scanner();

        switch(t){

            case _id: cout << "_id" << endl << endl;    break;
            case th:  cout << "th" << endl << endl; break;

            case eof: cout << "\nFin de archivo\nNumero de lineas = " << num_lineas; break;
            case _er: cout << "\nError en la linea: " << num_lineas; break;

        }
    }while(t != _er && t != eof);

    fclose(archivo);
    return 0;
}
