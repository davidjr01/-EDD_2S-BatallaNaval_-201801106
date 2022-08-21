#ifndef LDOBLEUSUARIO_H
#define LDOBLEUSUARIO_H

#include<stddef.h>
#include<iostream>
#include "string"
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
        void ModificarNick(string,string);
        void ModificarPass(string,string);
        void ModificarEdad(int,int);
        void Mostrar();
        bool Login(string,string);
        void Eliminar(string);

    protected:

    private:
};

#endif // LDOBLEUSUARIO_H
