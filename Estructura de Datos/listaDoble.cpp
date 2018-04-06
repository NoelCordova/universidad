#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int TipoDato;

struct nodo{
    struct nodo *ant;
    TipoDato info;
    struct nodo *sig;
};

typedef struct nodo *ListaDoble;

void inicializarLista(ListaDoble &p, ListaDoble &f){
    p= NULL;
    f= NULL;
};

TipoDato listaVacia(ListaDoble p, ListaDoble f){
    return (p==NULL && f==NULL);
};

void insertarInicio(ListaDoble &p, ListaDoble &f, TipoDato x){
    ListaDoble q;
    q= new nodo;
    q-> info= x;
    q-> ant= NULL;

    if(listaVacia(p, f)==1){
        q-> sig= NULL;
        p= q;
        f= q;
    }
    else{
        q-> sig= p;
        p-> ant= q;
        p= q;
    }
};

void insertarFinal(ListaDoble &p, ListaDoble &f, TipoDato x){
    ListaDoble q;
    q= new nodo;
    q-> info= x;
    q-> sig= NULL;

    if(listaVacia(p, f)==1){
        q-> ant= NULL;
        p= q;
        f= q;
    }
    else{
        q-> ant= f;
        f-> sig= q;
        f= q;
    }
};

void insertarAntes(ListaDoble &p, ListaDoble &f, TipoDato z, TipoDato REF){
    ListaDoble q, t, x;
    TipoDato Band= 1;

    if(listaVacia(p, f)==0){
        q= p;
        while((q-> info !=REF)&&Band== 1){
            if(q-> sig==NULL) {Band= 0;}
            else {q= q-> sig;}
        }
        if(Band==1){
            x= new nodo;
            x-> info= z;

            if(p= q){
                x-> sig= q;
                q-> ant= x;
                x-> ant= NULL;
                p= x;
            }
            else{
                t= q-> ant;
                x-> sig= q;
                q-> ant= x;
                x-> ant= t;
                t-> sig= x;
            }
        }
    }
};

void insertarDespues(ListaDoble &p, ListaDoble &f, TipoDato z, TipoDato REF){
    ListaDoble q, t, x;
    TipoDato Band= 1;

    if(listaVacia(p, f)==0){
        q= p;
        while((q-> info !=REF)&&(Band== 1)){
            if(q-> sig==NULL) {Band= 0;}
            else {q= q-> sig;}
        }

        if(Band== 1){
            x= new nodo;
            x-> info= z;

            if(f==q){
                x-> sig= NULL;
                q-> sig= x;
                x-> ant= q;
                f= x;
            }
            else{
                t= q-> sig;
                x-> sig= t;
                t-> ant= x;
                x-> ant= q;
                q-> sig= x;
            }
        }
    }
};

void eliminarPrimero(ListaDoble &p, ListaDoble &f){
    ListaDoble q;
    if(listaVacia(p, f)==0){
        q=p;
        if(p==f) {
            p= NULL;
            q= NULL;
        }
        else{
            p= q-> sig;
            p->ant= NULL;
            }
        delete q;
    }
};

void eliminarUltimo(ListaDoble &p, ListaDoble &f){
    ListaDoble q;
    if(listaVacia(p, f)==0){
        q= f;
        if(p==f){
            p= NULL;
            f= NULL;
        }
        else{
            f= q-> ant;
            f-> sig= NULL;
            }
        delete q;
    }
};

void eliminarX(ListaDoble &p, ListaDoble &f, TipoDato REF){
    ListaDoble q, t, r;
    TipoDato Band= 1;

    if(listaVacia(p, f)== 0){
        q= p;
        while((q->info != REF)&&(Band= 1))
            if(p-> sig== NULL) {Band= 0;}
            else {q= q-> sig;}

            if(Band==1){
                if(p==f) {p= NULL; f= NULL;}
                else if(q==f) {f= q-> ant; f-> sig= NULL;}
                else if(p==q) {p= q-> sig; p-> ant= NULL;}
                else{
                    t= q-> ant;
                    r= q-> sig;
                    t-> sig= r;
                    r-> ant= t;
                }
                delete q;
            }

    }
};

void eliminarAntesX(ListaDoble &p, ListaDoble &f, TipoDato REF){
    ListaDoble q, t, r;
    TipoDato Band= 1;

    if(listaVacia(p, f)==0){
        q= p;
        while((q->info != REF)&&(Band= 1)){
            if(p-> sig== NULL) {Band= 0;}
            else {q= q-> sig;}

            if(Band== 1){
                if(p!=q) {t= q-> ant;}
                else if(p==t) {p= q; p-> ant= NULL;}
                else {r= t-> ant; r-> sig= q; q-> ant= r;}
            }
            delete q;
        }
    }
};

void mostrarLista(ListaDoble p){
    ListaDoble q;
    q= p;

    while(q!= NULL){
        cout<<q-> info <<" ";
        q= q->sig;
    }
    cout<<"\n";
    system("pause");
};

int main(){
    TipoDato opc, dato, dato2;
    ListaDoble x, y;
    inicializarLista(x, y);

    do{
        cout<<"1) Insertar al inicio!\n2) Insertar al final!\n3) Insertar Antes!\n4) Insertar despues!\n";
        cout<<"5) Eliminar primero!\n6) Eliminar ultimo!\n7) Eliminar 'X'\n8) Eliminar antes de 'X'\n";
        cout<<"9) Mostrar :3\n10) Salir\n" <<endl;
        cout<<"Opcion [ ]\b\b";
        cin>>opc;


        switch(opc){
        case 1: cout<<"Ingresa un valor a la lista (AL PRINCIPIO! ^^) : ";
                cin>>dato;
                insertarInicio(x, y, dato);
                break;

        case 2: cout<<"Ingresa un valor a la lista (AL FINAL! :D) : ";
                cin>>dato;
                insertarFinal(x, y, dato);
                break;

        case 3: cout<<"dato: ";
                cin>>dato;
                cout<<"\nreferencia: ";
                cin>>dato2;
                insertarAntes(x, y, dato, dato2);
                break;

        case 4: cout<<"dato: ";
                cin>>dato;
                cout<<"\nreferencia: ";
                cin>>dato2;
                insertarDespues(x, y, dato, dato2);
                break;

        case 5: eliminarPrimero(x, y);
                break;

        case 6: eliminarUltimo(x, y);
                break;

        case 7: cout<<"ref: ";
                cin>>dato;
                eliminarX(x, y, dato);
                break;

        case 8: break;

        case 9: mostrarLista(x);
                break;

        default: system("cls"); cout<<"                                  Adios :'(" <<endl;
                system("pause");
        }
        system("cls");
    }while(opc<=9);
}
