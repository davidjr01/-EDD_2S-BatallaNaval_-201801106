#ifndef LCATEGORIA_H
#define LCATEGORIA_H
#include "LArticulo.h"
#include<stddef.h>
#include<iostream>
#include "string"
#include "NodoCategoria.h"
using namespace std;

class LCategoria
{
    public:
        NodoCategoria*cabeza;
        int tamanio=0;

        LCategoria(){
            this->cabeza=NULL;
        }
        void Insertar(string,LArticulo*lista);
        void Mostrar();
        bool Existe(string);
        void Buscar(string ,string ,int ,string ,string );

    protected:

    private:
};

#endif // LCATEGORIA_H
