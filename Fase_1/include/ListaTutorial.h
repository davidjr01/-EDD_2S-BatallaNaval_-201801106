#ifndef LISTATUTORIAL_H
#define LISTATUTORIAL_H
#include "NodoTutorial.h"
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "NodoArticulo.h"


class ListaTutorial
{
    public:
        NodoTutorial *cabeza;
        int tamanio=0;
        ListaTutorial(){
            this->cabeza=NULL;
        }
        void InsertarPrimero2(int,int);
        void InsertarPrimero(int,int);
        void Mostrar();
        void Graficar();
        void gotoxyz(int x, int y){
            HANDLE hCon;
            hCon = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD dwPos;
            dwPos.X = x;
            dwPos.Y = y;
            SetConsoleCursorPosition(hCon, dwPos);
        }

};

#endif // LISTATUTORIAL_H
