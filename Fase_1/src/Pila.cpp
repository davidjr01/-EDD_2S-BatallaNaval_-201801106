#include"NodoPila.h"
#include "Pila.h"
#include<stddef.h>
#include<iostream>
#include "string"


void Pila::Insertar(string jugada){
    NodoPila*nuevo=new NodoPila(jugada);
     if (cabeza==NULL){
            cabeza=nuevo;
            tamanio+=1;
     }else{
         nuevo->siguiente=cabeza;
         cabeza=nuevo;
         tamanio+=1;
     }
}
void Pila::Mostrar(){
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoPila*aux=cabeza;
        int cont=0;
        while(aux!=NULL){
            cout<<aux->movimiento<<endl;
            aux=aux->siguiente;
        }
    }
}

