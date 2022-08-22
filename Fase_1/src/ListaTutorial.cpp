#include "ListaTutorial.h"
#include<stddef.h>
#include<iostream>
#include "string"
using namespace std;

ListaTutorial::InsertarPrimero(int x,int y){
    NodoTutoriale*nuevo=new NodoTutorial(x,y);
     if (cabeza==NULL){
            cabeza=nuevo;
            tamanio+=1;
     }else{
         nuevo->siguiente=cabeza;
         cabeza=nuevo;
         tamanio+=1;
     }
}
ListaTutorial::Mostrar(){
    if(cabecera==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoListaSimple*aux=cabecera;
        while(aux!=NULL){
            cout<<aux->valor<<endl;
            aux=aux->siguiente;
        }
    }
}
