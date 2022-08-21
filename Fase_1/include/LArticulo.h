#ifndef LARTICULO_H
#define LARTICULO_H
#include "NodoArticulo.h"
using namespace std;

class LArticulo
{
    public:
        NodoArticulo *cabeza;
        int tamanio=0;
        LArticulo(){
            this->cabeza=NULL;
        }
        void Insertar(string,int,string,string);
        void Mostrar();
        NodoArticulo Devolver();

    protected:

    private:
};

#endif // LARTICULO_H
