#ifndef LARTICULO_H
#define LARTICULO_H
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
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
        void Mostrar(string,int);
        int Numero();
        void gotoxyz(int x, int y){
            HANDLE hCon;
            hCon = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD dwPos;
            dwPos.X = x;
            dwPos.Y = y;
            SetConsoleCursorPosition(hCon, dwPos);
        }
        string Graficar(int,string);

    protected:

    private:
};

#endif // LARTICULO_H
