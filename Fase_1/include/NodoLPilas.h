#ifndef NODOLPILAS_H
#define NODOLPILAS_H
#include "Pila.h"

class NodoLPilas
{
    public:
        string Nombre;
        Pila*lista;
        NodoLPilas*siguiente;

        NodoLPilas(string cat,Pila*list){
            this->siguiente=NULL;
            this->Nombre=cat;
            this->lista=list;
        }

    protected:

    private:
};

#endif // NODOLPILAS_H
