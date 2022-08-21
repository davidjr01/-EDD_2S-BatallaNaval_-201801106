#include "LCategoria.h"


void LCategoria::Insertar(string categoria,LArticulo*lista){
    NodoCategoria*nNuevo=new NodoCategoria(categoria,lista);
    if (cabeza==NULL){
        cabeza=nNuevo;
        tamanio+=1;
     }else{
         NodoCategoria*aux=cabeza;
         while(aux->siguiente!=NULL){
                aux=aux->siguiente;
         }
         aux->siguiente=nNuevo;
         tamanio+=1;
     }

}
void LCategoria::Mostrar(){
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoCategoria*aux=cabeza;
        while(aux!=NULL){
            cout<<"Categoria: " <<aux->categoria<<endl;
            aux->lista->Mostrar();
            cout<<endl;
            aux=aux->siguiente;
        }
    }

}
