#ifndef LDPILAS_H
#define LDPILAS_H
#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "LArticulo.h"
#include "NodoLPilas.h"
#include "Pila.h"
using namespace std;



class LDPilas
{
    public:
        NodoLPilas*cabeza;
        int tamanio=0;
        LDPilas(){
            this->cabeza=NULL;
        }
        void Insertar(string,Pila*lista);
        void Mostrar();


    protected:

    private:
};

#endif // LDPILAS_H
