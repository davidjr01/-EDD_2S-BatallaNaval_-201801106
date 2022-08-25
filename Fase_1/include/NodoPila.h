#ifndef NODOPILA_H
#define NODOPILA_H
#include<stddef.h>
#include"string"
using namespace std;

class NodoPila
{
    public:
        string movimiento;
        NodoPila*siguiente;
        NodoPila(string movimiento_){
            this->siguiente==NULL;
            this->movimiento=movimiento_;
        }

    protected:

    private:
};

#endif // NODOPILA_H
