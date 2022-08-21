#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include <iostream>
#include <string>

using namespace std;

class NodoUsuario
{
    public:
       string nick;
       string pass;
       int edad,monedas;
       NodoUsuario*siguiente;
       NodoUsuario*anterior;

       NodoUsuario(string nick_,string pass_,int edad_,int monedas_){
           this->siguiente=NULL;
           this ->anterior=NULL;
           this->nick=nick_;
           this->pass=pass_;
           this->monedas=monedas_;
           this->edad=edad_;
       }
};

#endif // NODOUSUARIO_H
