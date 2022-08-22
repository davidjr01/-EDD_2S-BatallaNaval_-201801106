#ifndef NODOTUTORIAL_H
#define NODOTUTORIAL_H
#include <iostream>
#include <string>

using namespace std;

class NodoTutorial
{
    public:
        int x,y;
        NodoTutorial *siguiente;
        NodoTutorial(int x, int y){
            this->siguiente=NULL;
            this->x=x;
            this->y=y;

        }

    protected:

    private:
};

#endif // NODOTUTORIAL_H
