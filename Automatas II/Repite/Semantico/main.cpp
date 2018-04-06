#ifdef __linux__
#define limpiar "clear"
#endif // __linux__
 
#ifdef __MINGW32__
#define limpiar "cls"
#endif // __MINGW32__
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <sstream>

using namespace std;

//Parche para que la funcion to_string funcione en el compilador windows.
template <typename T>
string to_string(T value)
{
	ostringstream os ;
	os << value ;
	return os.str() ;
}

FILE *archivo;
int posicion_actual = 0, posicion_anterior = 0, num_lineas = 1;
char caracter;
string CAD;

typedef enum {id, pal_res_int, pal_res_float, pal_res_if, cor_izq, cor_der, par_izq, par_der, car_suma, car_menos, car_mult, car_div, car_coma, car_ptCom, car_dPt, car_comi, op_asig, num_int, num_float, com, eof, er_tam, er_tam_int, er_tam_float, error} token;


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

    if(estado_anterior == 2 || estado_anterior == 3){
        CAD = cadena;
        //Error en tamano
        if(cadena.length() > 10){
            retroceso();
            aceptacion();
            return -1;
        }else if(cadena == "int"){
            retroceso();
            aceptacion();
            return 1;
        }else if(cadena == "float"){
            retroceso();
            aceptacion();
            return 2;
        }else if(cadena == "if"){
            retroceso();
            aceptacion();
            return 3;
        }else{
            retroceso();
            aceptacion();
            return 4;   
        }

    }else{
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
                else if (dato == ',') estado_actual = 5;
                else estado_actual = -1;
                break;

            case 2:
                if(isdigit(dato)) estado_actual = 3;
                else if (dato == ',') estado_actual = 5;
                else estado_actual = -1;
                break;

            case 3:
                if(isdigit(dato)) estado_actual = 3;
                else estado_actual = -1;
                break;

            case 4:
                if(isdigit(dato)) estado_actual = 4;
                else if(dato == '.') estado_actual = 2;
                else if (dato == ',') estado_actual = 5;
                else estado_actual = -1;                
                break;
                
            case 5:
            	estado_actual = -1;
            	break;
                
        }

        if(estado_actual != -1) cadena = cadena + dato;
    }
    CAD = cadena;

    if(estado_anterior == 3) {
        if(cadena.length() > 5){
            retroceso();    
            aceptacion();
            return -1;
    	}
        
        retroceso();
        aceptacion();
        return 1;

    } else if(estado_anterior == 4) {
        if(cadena.length() > 5){
            retroceso();    
            aceptacion();
            return -2;
        }
        retroceso();
        aceptacion();
        return 2;
        
    
	} else if(estado_anterior == 5){
		retroceso();
		aceptacion();
		return 0;
	
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
                else if(dato == ',' || dato == ';' || dato == '"') estado_actual = 3;
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


    if(estado_anterior == 1){
        if(cadena == "["){
            retroceso();
            aceptacion();
            return 1;
        }else if(cadena == "]"){
            retroceso();
            aceptacion();
            return 2;
        }else if(cadena == "("){
            retroceso();
            aceptacion();
            return 3;
        }else if(cadena == ")"){
            retroceso();
            aceptacion();
            return 4;
        }
        
    }else if(estado_anterior == 2){
        
        if(cadena == "+"){
            retroceso();
            aceptacion();
            return 5;
        }else if(cadena == "-"){
            retroceso();
            aceptacion();
            return 6;
        }else if(cadena == "*"){
            retroceso();
            aceptacion();
            return 7;
        }else if(cadena == "/"){
            retroceso();
            aceptacion();
            return 8;
        }

    }else if(estado_anterior == 3){
        
        if(cadena == ","){
            retroceso();
            aceptacion();
            return 9;
        }else if(cadena == ";"){
            retroceso();
            aceptacion();
            return 10;
        }else if(cadena == "\""){
            retroceso();
            aceptacion();
            return 13;
        }
        
    }else if(estado_anterior == 4){
        if(cadena == ":"){
            retroceso();
            aceptacion();
            return 11;
        }else if (cadena == "="){
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
        case 1:  return pal_res_int; break;
        case 2:  return pal_res_float; break;
        case 3:  return pal_res_if; break;
        case 4:  return id;      break;
        case -1: return er_tam; break;
    }

    x = numbers();
    switch(x){
        case 1:  return num_float; break;
        case 2:  return num_int; break;
        case -1: return er_tam_float; break;
        case -2: return er_tam_int; break;
    }

    x = caracteres();
    switch(x){
        case 1:  return cor_izq; break;
        case 2:  return cor_der; break;
        case 3:  return par_izq; break;
        case 4:  return par_der; break;
        case 5:  return car_suma; break;
        case 6:  return car_menos; break;
        case 7:  return car_mult; break;
        case 8:  return car_div; break;
        case 9:  return car_coma; break;
        case 10: return car_ptCom; break;
        case 11: return car_dPt; break;
        case 12: return op_asig; break;
        case 13: return car_comi; break;
    }

    if(comment()) return com;
    if(end_file()) return eof;
    else return error;
}


int main(){
    char name_file[50];
    token t;
    string cadTokens = "", errores[50];
    int i = 0;
       
    do{
        
        cout << "Ingrese el nombre del archivo: ";  cin >> name_file;
        archivo = fopen(name_file, "r");
        
    }while(archivo == NULL);
    
    system(limpiar);
    cout << "Archivo seleccionado : " << name_file << endl;
    cout << "-------------------------------" << endl;

    do{
        t = scanner();

        switch(t){
            case pal_res_int:   cadTokens= cadTokens + "pal_res_int|";      break;
            case pal_res_float: cadTokens= cadTokens + "pal_res_float|";    break;
            case pal_res_if:    cadTokens= cadTokens + "pal_res_if|";       break;
            case id:            cadTokens= cadTokens + "id(" + CAD + ")|";      break;
            case num_int:       cadTokens= cadTokens + "num_int(" + CAD + ")|"; break;
            case num_float:     cadTokens= cadTokens + "num_float(" + CAD + ")|"; break;
            case com:           cadTokens= cadTokens + "com|"; break;
            case cor_izq:       cadTokens= cadTokens + "cor_izq|"; break;
            case cor_der:       cadTokens= cadTokens + "cor_der|"; break;
            case par_izq:       cadTokens= cadTokens + "par_izq|"; break;
            case par_der:       cadTokens= cadTokens + "par_der|"; break;
            case car_suma:      cadTokens= cadTokens + "car_suma|"; break;
            case car_menos:     cadTokens= cadTokens + "car_menos|"; break;
            case car_mult:      cadTokens= cadTokens + "car_mult|"; break;
            case car_div:       cadTokens= cadTokens + "car_div|"; break;
            case car_coma:      cadTokens= cadTokens + "car_coma|"; break;
            case car_ptCom:     cadTokens= cadTokens + "car_ptCom|"; break;
            case car_comi:      cadTokens= cadTokens + "car_comi|"; break;
            case car_dPt:       cadTokens= cadTokens + "car_dPt|"; break;
            case op_asig:       cadTokens= cadTokens + "op_asig|"; break;
            case eof:           cadTokens= cadTokens + "eof\n"; break;
            case er_tam_int:    cadTokens= cadTokens + "error|";
                                errores[i] = "er_tam_int - ln: " + to_string(num_lineas); i = i+1; break;

            case er_tam_float:  cadTokens= cadTokens + "error|";
                                errores[i] = "er_tam_float - ln: " + to_string(num_lineas); i = i+1; break;

            case er_tam:        cadTokens= cadTokens + "error|";
                                errores[i] = "er_tam - ln: " + to_string(num_lineas); i = i+1; break;

            case error:         cadTokens= cadTokens + "error|";
                                errores[i] = "er_car - ln: " + to_string(num_lineas); i = i+1; break;
        }

    }while(t != eof);

    if(errores[0] == ""){
        cout << "Tira de tokens:" << endl << cadTokens << "\nNumero de lineas: " << num_lineas << endl;    
    } else {
        cout << "Error(es) en tira de tokens:" << endl << cadTokens << endl;
        cout << "Lista de errores:" << endl;

        for(int i=0; i<=50; i++){
            if(errores[i] == "") break;
            else cout << errores[i] << endl;
        }

        cout << "\nNumero de lineas: " << num_lineas << endl;
    }

    fclose(archivo);
    return 0;
}
