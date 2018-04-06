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

typedef enum {id, th, ts, i, num, pi, pd, ci, cd, cm, cms, cp, ce, com, pc,
p, dp, cmt, eof, error} token;

string tokenToString(token t){

	switch(t){

		case id: 	return "identifier";
		case th: 	return "throw";
		case num: return "numbers";
		case pi: 	return "(";
		case pd:	return ")";
		case ci: 	return "[";
		case cd: 	return "]";
		case cm: 	return "+";
		case cms: return "-";
		case cp: 	return "*";
		case ce: 	return "/";
		case com:	return ",";
		case pc: 	return ";";
		case p:		return ".";
		case dp:	return ":";

		default: return "";

	}
}

void controlador(){
  //1
  tabla["main"]["identifier"].push_back("stsequence"); tabla["main"]["identifier"].push_back(".");
  tabla["main"]["throw"].push_back("stsequence"); tabla["main"]["throw"].push_back(".");
  //2
  tabla["stsequence"]["identifier"].push_back("statement"); tabla["stsequence"]["identifier"].push_back("stsequence'");
  tabla["stsequence"]["throw"].push_back("statement"); tabla["stsequence"]["throw"].push_back("stsequence'");
  //3
  tabla["stsequence'"][";"].push_back(";"); tabla["stsequence'"][";"].push_back("statement"); tabla["stsequence'"][";"].push_back("stsequence'");
  tabla["stsequence'"]["."];
  //4
  tabla["statement"]["identifier"].push_back("assignment");
  tabla["statement"]["throw"].push_back("throwing");
  //5
  tabla["assignment"]["identifier"].push_back("identifier"); tabla["assignment"]["identifier"].push_back(":"); tabla["assignment"]["identifier"].push_back("mexpression");
  //6
  tabla["throwing"]["identifier"].push_back("throw"); tabla["throwing"]["identifier"].push_back("mexpression");
  //7
  tabla["mexpression"]["identifier"].push_back("mterm"); tabla["mexpression"]["identifier"].push_back("mexpression'");
  tabla["mexpression"]["("].push_back("mterm"); tabla["mexpression"]["("].push_back("mexpression'");
  tabla["mexpression"]["["].push_back("mterm"); tabla["mexpression"]["["].push_back("mexpression'");
  //8
  tabla["mexpression'"][")"];
  tabla["mexpression'"]["."];
  tabla["mexpression'"][";"];
  tabla["mexpression'"]["+"].push_back("+"); tabla["mexpression'"]["+"].push_back("mterm"); tabla["mexpression'"]["+"].push_back("mexpression'");
  tabla["mexpression'"]["-"].push_back("-"); tabla["mexpression'"]["-"].push_back("mterm"); tabla["mexpression'"]["-"].push_back("mexpression'");
  //9
  tabla["mterm"]["identifier"].push_back("mfactor"); tabla["mterm"]["identifier"].push_back("mterm'");
  tabla["mterm"]["("].push_back("mfactor"); tabla["mterm"]["("].push_back("mterm'");
  tabla["mterm"]["["].push_back("mfactor"); tabla["mterm"]["["].push_back("mterm'");
  //10
  tabla["mterm'"][")"];
  tabla["mterm'"]["."];
  tabla["mterm'"][";"];
  tabla["mterm'"]["+"];
  tabla["mterm'"]["-"];
  tabla["mterm'"]["*"].push_back("*"); tabla["mterm'"]["*"].push_back("mfactor"); tabla["mterm'"]["*"].push_back("mterm'");
  //11
  tabla["mfactor"]["identifier"].push_back("identifier");
  tabla["mfactor"]["("].push_back("("); tabla["mfactor"]["("].push_back("mexpression"); tabla["mfactor"]["("].push_back(")");
  tabla["mfactor"]["["].push_back("mdefinition");
  //12
  tabla["mdefinition"]["["].push_back("["); tabla["mdefinition"]["["].push_back("rowsequence"); tabla["mdefinition"]["["].push_back("]");
  //13
  tabla["rowsequence"]["numbers"].push_back("row"); tabla["rowsequence"]["numbers"].push_back("rowsequence'");
  tabla["rowsequence"]["("].push_back("row"); tabla["rowsequence"]["("].push_back("rowsequence'");
  tabla["rowsequence"]["-"].push_back("row"); tabla["rowsequence"]["-"].push_back("rowsequence'");
  //14
  tabla["rowsequence'"]["]"];
  tabla["rowsequence'"][";"].push_back(";"); tabla["rowsequence'"][";"].push_back("row"); tabla["rowsequence'"][";"].push_back("rowsequence'");
  //15
  tabla["row"]["("].push_back("expression"); tabla["row"]["("].push_back("row'");
  tabla["row"]["numbers"].push_back("expression"); tabla["row"]["numbers"].push_back("row'");
  tabla["row"]["-"].push_back("expression"); tabla["row"]["-"].push_back("row'");
  //16
  tabla["row'"]["]"];
  tabla["row'"][","].push_back(","); tabla["row'"][","].push_back("expression");
  tabla["row'"][";"];
  //17
  tabla["expression"]["numbers"].push_back("term"); tabla["expression"]["numbers"].push_back("expression'");
  tabla["expression"]["("].push_back("term"); tabla["expression"]["("].push_back("expression'");
  tabla["expression"]["-"].push_back("term"); tabla["expression"]["-"].push_back("expression'");
  //18
  tabla["expression'"][")"];
  tabla["expression'"]["]"];
  tabla["expression'"][","];
  tabla["expression'"][";"];
  tabla["expression'"]["+"].push_back("+"); tabla["expression'"]["+"].push_back("term"); tabla["expression'"]["+"].push_back("expression'");
  tabla["expression'"]["-"].push_back("-"); tabla["expression'"]["-"].push_back("term"); tabla["expression'"]["-"].push_back("expression'");
  //19
  tabla["term"]["numbers"].push_back("factor"); tabla["term"]["numbers"].push_back("term'");
  tabla["term"]["("].push_back("factor"); tabla["term"]["("].push_back("term'");
  tabla["term"]["-"].push_back("factor"); tabla["term"]["-"].push_back("term'");
  //20
  tabla["term'"][")"];
  tabla["term'"]["]"];
  tabla["term'"][","];
  tabla["term'"][";"];
  tabla["term'"]["+"];
  tabla["term'"]["-"];
  tabla["term'"]["*"].push_back("*"); tabla["term'"]["*"].push_back("factor"); tabla["term'"]["*"].push_back("term'");
  tabla["term'"]["/"].push_back("/"); tabla["term'"]["/"].push_back("factor"); tabla["term'"]["/"].push_back("term'");
  //21
  tabla["factor"]["numbers"].push_back("numbers");
  tabla["factor"]["("].push_back("("); tabla["factor"]["("].push_back("expression"); tabla["factor"]["("].push_back(")");
  tabla["factor"]["-"].push_back("-"); tabla["factor"]["-"].push_back("factor");
}

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

bool identifiers(){

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

    	retroceso();
    	aceptacion();

        if(cadena == "identity") tk= 1;
        else if(cadena == "transpose") tk= 2;
        else if(cadena == "throw") tk= 3;
        else tk= 4;

        return true;

    } else {

    	rechazo();
    	return false;

    }
}

bool numbers(){

	int estado_actual = 0, estado_anterior;
	char dato;
	string cadena = "";

	while(estado_actual != -1){

        estado_anterior = estado_actual;
        dato = siguiente();

        switch(estado_actual){

            case 0:
                if(dato == '0') estado_actual = 1;
                else if(isdigit(dato) > 0) estado_actual = 6;
                else estado_actual = -1;
                break;

            case 1:
                if(dato == '0' ||dato == '1' || dato == '2' || dato == '3' || dato == '4' || dato == '5' || dato == '6' || dato == '7') estado_actual = 2;
                else if(dato == 'x' || dato == 'X') estado_actual = 3;
                else if(dato == '.') estado_actual = 7;
	            else estado_actual = -1;
                break;

            case 2:
            	if(dato == '0' ||dato == '1' || dato == '2' || dato == '3' || dato == '4' || dato == '5' || dato == '6' || dato == '7') estado_actual = 2;
            	else estado_actual = -1;
            	break;


            case 3:
            	if(isxdigit(dato)) estado_actual = 4;
            	else estado_actual = -1;
            	break;

            case 4:
            	if(isxdigit(dato)) estado_actual = 5;
            	else estado_actual = -1;
            	break;

            case 5:
            	if(isxdigit(dato)) estado_actual = 4;
            	else estado_actual = -1;
            	break;

            case 6:
            	if(dato == '.') estado_actual = 7;
            	else if(dato == 'e' || dato == 'E') estado_actual = 8;
            	else if(isdigit(dato)) estado_actual = 6;
            	else estado_actual = -1;
            	break;

            case 7:
            	if(isdigit(dato)) estado_actual = 9;
            	else estado_actual = -1;
            	break;

            case 8:
            	if(isdigit(dato)) estado_actual = 11;
            	else if(dato == '+' || dato == '-') estado_actual = 10;
            	else estado_actual = -1;
            	break;

            case 9:
            	if(isdigit(dato)) estado_actual = 9;
            	else if(dato == 'e' || dato == 'E') estado_actual = 8;
            	else estado_actual = -1;
            	break;

            case 10:
            	if(isdigit(dato)) estado_actual = 11;
            	else estado_actual = -1;
            	break;

            case 11:
            	if(isdigit(dato)) estado_actual = 11;
            	else estado_actual = -1;
            	break;
        }

	    if(estado_actual != -1) cadena = cadena + dato;
    }

    if(estado_anterior == 1 || estado_anterior == 2 || estado_anterior == 5 || estado_anterior == 6 || estado_anterior == 9 || estado_anterior == 11) {

    	retroceso();
    	aceptacion();
    	return true;

    } else {

    	rechazo();
    	return false;

    }
}

bool caracteres(){

    int estado_actual = 0, estado_anterior;
    char dato, cadena;

    while(estado_actual != -1){

        estado_anterior = estado_actual;
        dato = siguiente();

        switch(estado_actual){

            case 0:
                if(dato == '(' || dato ==  ')' || dato == '[' || dato == ']') estado_actual = 1;
                else if(dato == '+' || dato == '-' || dato == '*' || dato == '/') estado_actual = 2;
                else if(dato == ',' || dato == ';' || dato == '.') estado_actual = 3;
                else if(dato == ':') estado_actual = 4;
                else estado_actual = -1;
                break;

            case 1: estado_actual = -1; break;
            case 2: estado_actual = -1; break;
            case 3: estado_actual = -1; break;
            case 4: estado_actual = -1; break;

        }

        if(estado_actual != -1) cadena = dato;
    }


    if(estado_anterior == 1 || estado_anterior == 2 || estado_anterior == 3 || estado_anterior == 4) {

        if(cadena == '[') tk= 1;
        else if(cadena == ']') tk= 2;
        else if(cadena == '(') tk= 3;
        else if(cadena == ')') tk= 4;

        else if(cadena == '+') tk= 5;
        else if(cadena == '-') tk= 6;
        else if(cadena == '*') tk= 7;
        else if(cadena == '/') tk= 8;

        else if(cadena == ',') tk= 9;
        else if(cadena == ';') tk= 10;
        else if(cadena == '.') tk= 11;

        else if(cadena == ':') tk= 12;

        retroceso();
        aceptacion();
        return true;

    } else {

        rechazo();
        return false;

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

	while(white_space() || comment());
  if(identifiers()){
		if(tk == 1) return i;
    else if(tk == 2) return ts;
    else if(tk == 3) return th;
    else if(tk == 4) return id;
  }

	if(numbers()) return num;

	if(caracteres()){
		if(tk == 1)       return ci;
    else if(tk == 2)  return cd;
    else if(tk == 3)  return pi;
    else if(tk == 4)  return pd;
    else if(tk == 5)  return cm;
    else if(tk == 6)  return cms;
    else if(tk == 7)  return cp;
    else if(tk == 8)  return ce;
    else if(tk == 9)  return com;
    else if(tk == 10) return pc;
  	else if(tk == 11) return p;
  	else if(tk == 12) return dp;
	}

    if(end_file()) return eof;
    else return error;

}


bool validacion(string x, string t){

	if(tabla.find(x) != tabla.end()){
		if(tabla[x].find(t) != tabla[x].end()) return true;
		else return false;
	} else return false;

}

bool llenarpila(string x, string t){

	if(validacion(x, t)){

		for(list<string>::reverse_iterator rit=tabla[x][t].rbegin(); rit!=tabla[x][t].rend(); ++rit)
			pila.push(*rit);
		return true;

	}
	else return false;
}

bool LL1(){
	
	token t = scanner();
	string x, T;

	pila.push("main");

	do{
		x= pila.top();
		pila.pop();
		T= tokenToString(t);

		if(x == T) t = scanner();
		else{

			if(!llenarpila(x, T)) t= error; //o return false;
			else;
		}

	}while(!pila.empty() && t != error && t!=eof);

	return t == eof;

}

int main(){

	char name_file[50];
	token t;
  	controlador();

	do{

		cout << "Ingrese el nombre del archivo: ";	cin >> name_file;
		archivo = fopen(name_file, "r");

	}while(archivo == NULL);

	system("cls");
	cout << "Archivo seleccionado : " << name_file << endl;
	cout << "-------------------------------" << endl;

	if(LL1()) cout<<"\nOK, archivo aceptado" << endl;
	else cout << "\nError en la linea: " << num_lineas << endl;
	
	/*do{
    	t = scanner();

    	switch(t){
        	
      case id: 	cout << "identifier" 	<< endl << endl;	break;
			case th: 	cout << "throw" 		<< endl << endl;	break;
			case num: 	cout << "numbers" 		<< endl;	break;
			case pi: 	cout << "(" 			<< endl;	break;
			case pd:	cout << ")" 			<< endl;	break;
			case ci: 	cout << "[" 			<< endl;	break;
			case cd: 	cout << "]" 			<< endl;	break;
			case cm: 	cout << "+" 			<< endl;	break;
			case cms: 	cout << "-" 			<< endl;	break;
			case cp: 	cout << "*" 			<< endl;	break;
			case ce: 	cout << "/" 			<< endl;	break;
			case com:	cout << "," 			<< endl;	break;
			case pc: 	cout << ";" 			<< endl;	break;
			case p:		cout << "." 			<< endl;	break;
			case dp:	cout << ":" 			<< endl;	break;

			case eof: cout << "\nFin de archivo\nNumero de lineas = " << num_lineas << endl; break;
        	case error: cout << "\nError en la linea: " << num_lineas << endl; break;
    	}
    }while(t != error && t != eof);*/

    fclose(archivo);
    return 0;
}
