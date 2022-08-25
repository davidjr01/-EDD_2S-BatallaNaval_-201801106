#include "LDPilas.h"
#include"NodoLPilas.h"

void LDPilas::Insertar(string nombre,Pila*lista){
    NodoLPilas*nNuevo=new NodoLPilas(nombre,lista);
    if (cabeza==NULL){
        cabeza=nNuevo;
        tamanio+=1;
     }else{
         NodoLPilas*aux=cabeza;
         while(aux->siguiente!=NULL){
                aux=aux->siguiente;
         }
         aux->siguiente=nNuevo;
         tamanio+=1;
     }

}

void LDPilas::Mostrar(){
    int xs=0;
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoLPilas*aux=cabeza;
        while(aux!=NULL){
            cout<<aux->Nombre <<endl;
            aux->lista->Mostrar();
        }
    }

}

