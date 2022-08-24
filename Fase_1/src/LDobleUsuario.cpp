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
            cout<<"nick: "<<NodoMostrar->nick << "       Password: " << NodoMostrar->pass<< "        Edad:  " << NodoMostrar->edad<< "         Monedas: " << NodoMostrar->monedas<<endl;
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
            if(nick1==ENick->nick){
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

void LDobleUsuario::ModificarEdad(string nick1,int  nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->nick){
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


bool LDobleUsuario::Login(string nick,string pass){
    bool encontrado=false;
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if((nick==ENick->nick)&&(pass==ENick->pass)){
                encontrado=true;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }
    return encontrado;

}
bool LDobleUsuario::Existe(string nick){
    bool esta=false;
    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            if(nick==NodoMostrar->nick){
                esta=true;
                break;
            }
            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            cont-=1;
            cout<<endl;
        }else{
            break;
        }

    }
    return esta;
}

void LDobleUsuario::Eliminar(string nick){

}



