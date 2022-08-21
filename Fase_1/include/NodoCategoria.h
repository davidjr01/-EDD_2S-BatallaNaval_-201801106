#ifndef NODOCATEGORIA_H
#define NODOCATEGORIA_H
#include "LArticulo.h"

class NodoCategoria
{
    public:
        string categoria;
        LArticulo*lista;
        NodoCategoria*siguiente;

        NodoCategoria(string cat,LArticulo*list){
            this->siguiente=NULL;
            this->categoria=cat;
            this->lista=list;
        }


    protected:

    private:
};

#endif // NODOCATEGORIA_H
