#ifndef LDOBLEUSUARIO_H
#define LDOBLEUSUARIO_H

 #include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "NodoUsuario.h"

class LDobleUsuario
{
    public:
        NodoUsuario*cabeza;
        NodoUsuario*cola;
        int tamanio=0;
        LDobleUsuario(){
            this->cabeza=NULL;
            this->cola=NULL;
        }
        void Insertar(string,string,int,int);
        void EliminarPrimero();
        void EliminarUltimo();
        void Graficar();
        void ModificarNick(string,string);
        void ModificarPass(string,string);
        void ModificarEdad(string,int);
        void Mostrar();
        int OIndice(string);
        bool Login(string,string);
        void Eliminar(string);
        bool Existe(string);
        int MMoneda(string);
        void OrdenarAcendente();
        void OrdenarDes();

    protected:

    private:
};

#endif // LDOBLEUSUARIO_H
