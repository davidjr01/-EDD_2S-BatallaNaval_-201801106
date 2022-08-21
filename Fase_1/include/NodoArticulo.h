#ifndef NODOARTICULO_H
#define NODOARTICULO_H
#include<stddef.h>
#include"string"
using namespace std;

class NodoArticulo
{
    public:
        int precio;
        string id,nombre,src;
        NodoArticulo*siguiente;
        NodoArticulo(string id_,int precio_,string nombre_,string src_){
            this->siguiente==NULL;
            this->id=id_;
            this->precio=precio_;
            this->nombre=nombre_;
            this->src=src_;
        }


    protected:

    private:
};

#endif // NODOARTICULO_H
