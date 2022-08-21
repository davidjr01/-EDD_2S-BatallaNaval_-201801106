#include "LDobleUsuario.h"

void LDobleUsuario::Insertar(string nick,string pass,int edad,int moneda ){
     NodoUsuario*nNodo=new NodoUsuario(nick,pass,edad,moneda);
     if ((cabeza==NULL) && (cola==NULL)){
            cabeza=nNodo;
            cola=nNodo;
     }else{
         cola->siguiente=nNodo;
         nNodo->anterior=cola;
         nNodo->siguiente=cabeza;
         cabeza->anterior=nNodo;
         cola=nNodo;
     }
     this->tamanio+=1;

}

void LDobleUsuario::Mostrar(){

    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            cout<<"nick: "<<NodoMostrar->nick << "Password " << NodoMostrar->pass<< "Edad:  " << NodoMostrar->edad<< "Monedas: " << NodoMostrar->monedas<<endl;
            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            cont-=1;
            cout<<endl;
        }else{
            break;
        }

    }
}

void LDobleUsuario::ModificarNick(string nick1,string nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->nick){
                ENick->nick=nick2;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }

}

void LDobleUsuario::ModificarPass(string nick1,string nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->pass){
                ENick->pass=nick2;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }

}

void LDobleUsuario::ModificarEdad(int nick1,int nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->edad){
                ENick->edad=nick2;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }

}

