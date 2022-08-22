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

bool LCategoria::Existe(string categoria){
    bool s=false;
    if(cabeza==NULL){
            s=false;
    return s;

    }else{
        NodoCategoria*aux=cabeza;
        while(aux!=NULL){
            if(categoria==aux->categoria){
                    s=true;
                    break;
            }else{
                s=false;
            }
            aux=aux->siguiente;
        }
        return s;
    }

}

void LCategoria::Buscar(string categoria,string id,int precio,string nombre,string src){
    NodoCategoria*aux=cabeza;
    while(aux!=NULL){
        if(categoria==aux->categoria){
            aux->lista->Insertar(id,precio,nombre,src);
            break;
        }
        aux=aux->siguiente;
    }
}


