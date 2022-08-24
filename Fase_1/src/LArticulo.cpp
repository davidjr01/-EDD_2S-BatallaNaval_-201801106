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


void LArticulo::Mostrar(string categoria,int numero){
    int contador222=numero;
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoArticulo*aux=cabeza;

        while(aux!=NULL){
            contador222=contador222+1;
            gotoxyz(55,8+contador222);cout<<categoria;
            gotoxyz(2,8+contador222); cout<<aux->id;
            gotoxyz(16,8+contador222);cout<<aux->nombre;
            gotoxyz(95,8+contador222);cout<<aux->precio;
            aux=aux->siguiente;
        }
    }
}

int  LArticulo::Numero(){
    int contador22=0;
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoArticulo*aux=cabeza;
        while(aux!=NULL){
            contador22+=1;
            aux=aux->siguiente;
        }
    }
    return contador22;

}
