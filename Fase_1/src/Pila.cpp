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

/*string  Pila::Mostrar(int id,string refs){
    string contenido="";
    string cNodos="";
    string Cconecciones=refs+"->";
    if(cabeza == NULL){

    }else{
        int c=0;
        int cont=0;
        NodoPila*aux=cabeza;
        while(aux!=NULL){
                cont+=1;
                cNodos+="Nodos"+to_string(id)+to_string(cont)+"[label=\""+ aux->movimiento+"\"]\n";
                if(aux->siguiente!=NULL){
                    Cconecciones+="Nodos"+to_string(id)+to_string(cont)+"->";
                }else{
                    Cconecciones+="Nodos"+to_string(id)+to_string(cont);
                }

            aux=aux->siguiente;
        }
        contenido+="\n"+cNodos+Cconecciones+"\n";
    }
    return contenido;
}*/

