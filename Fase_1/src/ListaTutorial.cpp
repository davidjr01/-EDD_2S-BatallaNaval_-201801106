#include "ListaTutorial.h"
#include<stddef.h>
#include<iostream>
#include "string"
using namespace std;

void ListaTutorial::InsertarPrimero(int x,int y){
    NodoTutorial*nuevo=new NodoTutorial(x,y);
     if (cabeza==NULL){
            cabeza=nuevo;
            tamanio+=1;
     }else{
         nuevo->siguiente=cabeza;
         cabeza=nuevo;
         tamanio+=1;
     }
}
void ListaTutorial::Mostrar(){
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoTutorial*aux=cabeza;
        while(aux!=NULL){
            cout<<"X=  "<<aux->x<<"     Y=  " <<aux->y<<endl;
            aux=aux->siguiente;
        }
    }
}
