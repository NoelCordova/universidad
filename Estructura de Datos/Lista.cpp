#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int TipoDato;
struct TipoLista{
    int p;
};

void ListaVacia(){

}

void insertarDespues(TipoLista &p, TipoDato Ref, TipoDato z){
    TipoLista q, x;
    int Band= 1;

    if(ListaVacia(p)=!1){  //no esta vacia
        q= p;
        while((q->Liga!=Ref)&&(Band==1))
            if(q->Liga==NULL)
            Band= 0;
        else{
            q= q->Liga;
        }
        if(Band== 1){
            x=new Nodo;
            x->info= z;
            x->Liga= q->Liga;
            q->Liga= x;
        }
    }

}

void mostrarLista(TipoDato p){
    Lista q;
    while (q!=NULL){
        cout<<q->info;
        q= q->sig;
    }
}

void eliminarPrimero(TipoLista &p){
    TipoLista q;

    if(ListaVacia(p)==1){
        cout<<"No hay nodos";
        system("cls");
    }else{
        q= p;
        p= q->Liga;
        delete q;
    }
};

void eliminarUltimo(TipoLista &p){
    TipoLista q, t;

    if(ListaVacia(p)==1){
        cout<<"No hay nodos";
        system("cls");
    }else{
        q= p;
        while(q->Liga!=NULL){
            t= q;
            q= q->Liga;
        }
    }
    if(p==q)
        p= NULL;
    else
        t->Liga= NULL;
    delete q;
}

void eliminarX(TipoLista &p, TipoDato x){
    TipoLista q, t;
    int Band= 1;

    if(ListaVacia(p)==1){
        cout<<"No hay nodos";
        system("cls");
    }else{
        q= p;
        while((q->info!=x)&&(Band==1)){
            if(q->Liga==NULL)
                Band= 0;
            else{
                t= q;
                q= q->Liga;
            }
        }
    }

    if(Band==1){
        if(p==q)
            p= q->Liga;
        else
            t->Liga= q->Liga;
        delete q;
    }
}

void eliminarAntes(TipoLista &p, TipoDato x){
    TipoDato q, t, r;
    int Band= 1;

    if(ListaVacia(p)==1){
        cout<<"No hay nodos";
        system("cls");
    }else{
        t= p;
        q= p;
        while((q->info!=x)&&(Band==1)){
            if(q->==NULL)
                Band= 0;
            else
                r= t;
                t= q;
                q= q->Liga;
        }
    }
    if(Band==1){
        if(p==q)
            cout<<"No es posible";
        else{
            if(p==t)
                p= t->Liga
            else
                r->Liga= t->Liga;
            delete t;
        }
    }
}

void eliminarDespues(TipoLista &p, TipoDato x){
    TipoLista q, t;
    int Band= 1;

    if(ListaVacia(p)==1){
        cout<<"No hay nodos";
        system("cls");
    }else{
        q= p;
        while((q->info!=x)&&(Band==1))
            if(q->Liga==NULL)
                Band= 0;
        else
            q= q->Liga;
    }

    if (Band==1){
        if(q->Liga==NULL)
            cout<<"No se puede";
        else{
            t= q->Liga;
            q->Liga= t->Liga;
            delete t;
        }
    }
}

int main(){
    cout<<"Hola";
}
