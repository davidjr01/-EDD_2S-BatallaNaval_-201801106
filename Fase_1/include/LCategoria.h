#ifndef LCATEGORIA_H
#define LCATEGORIA_H
 #include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "LArticulo.h"
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
        int Numero();
        void gotoxys(int x, int y){
            HANDLE hCon;
            hCon = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD dwPos;
            dwPos.X = x;
            dwPos.Y = y;
            SetConsoleCursorPosition(hCon, dwPos);
        }
        bool Existe(string);
        void Buscar(string ,string ,int ,string ,string );
        void Graficar();

    protected:

    private:
};

#endif // LCATEGORIA_H
