#ifndef LISTATUTORIAL_H
#define LISTATUTORIAL_H
#include "NodoTutorial.h"


class ListaTutorial
{
    public:
        NodoTutorial *cabeza;
        int tamanio=0;
        ListaTutorial(){
            this->cabeza=NULL;
        }
        void Insertar(int,int);
        void Mostrar();

};

#endif // LISTATUTORIAL_H
