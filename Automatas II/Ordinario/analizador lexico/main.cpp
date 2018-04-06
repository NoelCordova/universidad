#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

FILE *archivo;
char caracter;
int posicion_actual = 0, posicion_anterior = 0, num_lineas = 1;
string CAD;

typedef enum {id, pal_res, cor_izq, cor_der, par_izq, par_der, car_suma, car_menos, car_mult, car_div, car_coma, car_ptCom, car_dPt, op_asig, num_int, num_float, com, sgn, eof, error} token;


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

        CAD = cadena;
    	if(cadena == "int" || cadena == "float" || cadena == "if") {
            retroceso();
            aceptacion();
            return 1;
    	}

    	else {
            retroceso();
            aceptacion();
            return 2;   
        }

    } else {

    	rechazo();
    	return 0;

    }
}


int numbers(){

	int estado_actual = 0, estado_anterior;
	char dato;
	string cadena = "";

	while(estado_actual != -1){

        estado_anterior = estado_actual;
        dato = siguiente();

        switch(estado_actual){

            case 0:
                if(dato == '0') estado_actual = 1;
                else if(isdigit(dato) > 0) estado_actual = 4;
                else estado_actual = -1;
                break;

            case 1:
                if(dato == '.') estado_actual = 2;
                else estado_actual = -1;
                break;

            case 2:
                if(isdigit(dato)) estado_actual = 3;
                else estado_actual = -1;
                break;

            case 3:
                if(isdigit(dato)) estado_actual = 3;
                else estado_actual = -1;                
                break;

            case 4:
                if(isdigit(dato)) estado_actual = 4;
                else estado_actual = -1;                
                break;            
        }

	    if(estado_actual != -1) cadena = cadena + dato;
    }
    CAD = cadena;

    if(estado_anterior == 3) {
    	retroceso();
    	aceptacion();
    	return 1;

    } else if(estado_anterior == 4) {

    	retroceso();
    	aceptacion();
    	return 2;

    } else {

    	rechazo();
    	return 0;

    }
}


bool comment(){
	
	int estado_actual = 0, estado_anterior;
	char dato;
	string cadena = "";

	while(estado_actual != -1){

        estado_anterior = estado_actual;
        dato = siguiente();

        switch(estado_actual){
        	
        	case 0:
        		if(dato == '!') estado_actual = 1;
        		else estado_actual = -1;
        		break;
        		
        	case 1:
        		if(isalpha(dato) || isblank(dato) || ispunct(dato) || isdigit(dato)) estado_actual = 1;
        		else estado_actual = -1;
        		break;
        }
        
        if(estado_actual != -1) cadena = cadena + dato;
    }
    
    if(estado_anterior == 1){
    	
    	retroceso();
    	aceptacion();
    	return true;
    	
	} else {
		
		rechazo();
    	return false;
		
	}
}


int caracteres(){
	
	int estado_actual = 0, estado_anterior;
    char dato;
    string cadena = "";

    while(estado_actual != -1){

        estado_anterior = estado_actual;
        dato = siguiente();

        switch(estado_actual){

            case 0:
            	if(dato == '(' || dato ==  ')' || dato == '[' || dato == ']') estado_actual = 1;
            	else if(dato == '+' || dato == '-' || dato == '*' || dato == '/') estado_actual = 2;
            	else if(dato == ',' || dato == ';') estado_actual = 3;
            	else if(dato == ':' || dato == '=') estado_actual = 4;
            	else estado_actual = -1;
            	break;
            case 1: estado_actual = -1; break;
            case 2: estado_actual = -1; break;
            case 3: estado_actual = -1; break;
            case 4: estado_actual = -1; break;
                
        }
        
	    if(estado_actual != -1) cadena = cadena + dato;
    }


	if(estado_anterior == 1) {
		
		if(cadena == "["){
            retroceso();
            aceptacion();
            return 1;
        } else if(cadena == "]") {
            retroceso();
            aceptacion();
            return 2;
        } else if(cadena == "(") {
            retroceso();
            aceptacion();
            return 3;
        } else if(cadena == ")") {
            retroceso();
            aceptacion();
            return 4;
        }
		
	} else if(estado_anterior == 2) {
		
		if(cadena == "+") {
            retroceso();
            aceptacion();
            return 5;
        } else if(cadena == "-") {
            retroceso();
            aceptacion();
            return 6;
        } else if(cadena == "*") {
            retroceso();
            aceptacion();
            return 7;
        } else if(cadena == "/") {
            retroceso();
            aceptacion();
            return 8;
        }

	} else if(estado_anterior == 3) {
		
		if(cadena == ","){
            retroceso();
            aceptacion();
            return 9;
        } else if(cadena == ";") {
            retroceso();
            aceptacion();
            return 10;
        }
		
	} else if(estado_anterior == 4) {
		//cout << "Dos puntos:\t\t" << cadena << endl;
        if(cadena == ":"){
            retroceso();
            aceptacion();
            return 11;
        } else if (cadena == "="){
            retroceso();
            aceptacion();
            return 12;
        }
		
	} else {
		
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
    int x;
    x = identifiers();
    switch(x){
        case 1: return pal_res; break;
        case 2: return id;      break;
    }

    x = numbers();
    switch(x){
        case 1: return num_float; break;
        case 2: return num_int; break;
    }
    if(comment()) return com;

    x = caracteres();
    switch(x){
        case 1: return cor_izq; break;
        case 2: return cor_der; break;
        case 3: return par_izq; break;
        case 4: return par_der; break;
        case 5: return car_suma; break;
        case 6: return car_menos; break;
        case 7: return car_mult; break;
        case 8: return car_div; break;
        case 9: return car_coma; break;
        case 10: return car_ptCom; break;
        case 11: return car_dPt; break;
        case 12: return op_asig; break;
    }
    if(caracteres()) return sgn;
    if(end_file()) return eof;
    else return error;
    
}


int main(){
	
	char name_file[50];
	token t;
	
	do{
		
		cout << "Ingrese el nombre del archivo: ";	cin >> name_file;
		archivo = fopen(name_file, "r");
		
	}while(archivo == NULL);
	
	system("cls");
	cout << "Archivo seleccionado : " << name_file << endl;
	cout << "-------------------------------" << endl;

    do{
    	t = scanner();

    	switch(t){
            case pal_res: cout<<"pal_res(" << CAD << ")" << endl; break;
        	case id:  cout<<"id(" << CAD <<")" << endl; break;
        	case num_int: cout<<"num_int(" << CAD <<")" << endl; break;
            case num_float: cout<<"num_float" << endl; break;
        	case com: cout<<"hay un comentario" << endl; break;
        	case cor_izq: cout<<"cor_izq" << endl; break;
            case cor_der: cout<<"cor_der" << endl; break;
            case par_izq: cout<<"par_izq" << endl; break;
            case par_der: cout<<"par_der" << endl; break;
            case car_suma: cout<<"car_suma" << endl; break;
            case car_menos: cout<<"car_menos" << endl; break;
            case car_mult: cout<<"car_mult" << endl; break;
            case car_div: cout<<"car_div" << endl; break;
            case car_coma: cout<<"car_coma" <<  endl; break;
            case car_ptCom: cout<<"car_ptCom" << endl; break;
            case car_dPt: cout<<"car_dPt" << endl; break;
            case op_asig: cout<<"op_asig" << endl; break;
			case eof: cout << "\nFin de archivo\nNumero de lineas = " << num_lineas; break;
        	case error: cout << "\nError en la linea: " << num_lineas; break;
    	}
    }while(t != error && t != eof);

    CAD = "";
    fclose(archivo);
    return 0;
}
