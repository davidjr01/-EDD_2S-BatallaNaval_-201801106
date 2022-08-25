#ifndef PILA_H
#define PILA_H
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "NodoPila.h"
using namespace std;

class Pila
{
    public:
        NodoPila *cabeza;
        int tamanio=0;
        Pila(){
            this->cabeza=NULL;
        }
        void Insertar(string);
        string Mostrar(int,string);
        void Graficar();

    protected:

    private:
};

#endif // PILA_H
