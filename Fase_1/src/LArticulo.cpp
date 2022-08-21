#include "LArticulo.h"
#include "NodoArticulo.h"
#include<stddef.h>
#include<iostream>
#include "string"
using namespace std;

void LArticulo::Insertar(string id,int precio,string nombre,string src){
    NodoArticulo*nNuevo=new NodoArticulo(id,precio,nombre,src);
    if (cabeza==NULL){
        cabeza=nNuevo;
        tamanio+=1;
     }else{
         NodoArticulo *aux=cabeza;
         while(aux->siguiente!=NULL){
                aux=aux->siguiente;
         }
         aux->siguiente=nNuevo;
         tamanio+=1;
     }
}


void LArticulo::Mostrar(){
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoArticulo*aux=cabeza;
        while(aux!=NULL){
            cout<<"Id: "<<aux->id<<"    Precio: "<<aux->precio<<"    Nombre: "<<aux->nombre<<"    src: "<<aux->src<<endl;
            aux=aux->siguiente;
        }
    }
}
