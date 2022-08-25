#include "ListaTutorial.h"
#include<stddef.h>
#include<iostream>
#include "string"
using namespace std;

void ListaTutorial::InsertarPrimero2(int x,int y){
    NodoTutorial*nuevo=new NodoTutorial(x,y);
     if (cabeza==NULL){
            cabeza=nuevo;
            tamanio+=1;
     }else{
         nuevo->siguiente=cabeza;
         cabeza=nuevo;
         tamanio+=1;
     }
}

void ListaTutorial::InsertarPrimero(int x,int y){
    NodoTutorial*nuevo=new NodoTutorial(x,y);
    if (cabeza==NULL){
        cabeza=nuevo;
        tamanio+=1;
     }else{
         NodoTutorial *aux=cabeza;
         while(aux->siguiente!=NULL){
                aux=aux->siguiente;
         }
         aux->siguiente=nuevo;
         tamanio+=1;
     }
}

void ListaTutorial::Mostrar(){
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        gotoxyz(10,5);cout<<"TUTORIAL";
        gotoxyz(15,7);cout<<"Tablero";

        gotoxyz(20,9);cout<<"Ancho:";
        gotoxyz(20,10);cout<<"Alto:";
        gotoxyz(15,12);cout<<"Movimientos:";
        NodoTutorial*aux=cabeza;
        int cont=0;
        while(aux!=NULL){
            cont=cont+1;
            if(cont==1){
                gotoxyz(30,9);cout<<aux->x;
                gotoxyz(30,10);cout<<aux->y;
                gotoxyz(20,15);

            }else if(cont==tamanio){
            cout<<"("<<aux->x<<"," <<aux->y<<")";
            }
            else{
            cout<<"("<<aux->x<<"," <<aux->y<<")->";
            }
            aux=aux->siguiente;
        }
    }
}


void ListaTutorial::Graficar(){
    string contenido="digraph G {\n"
            "node[shape = box,width=0.7,height=0.7,fillcolor=\"white\" color=\"black\"  ]\n"
            "{rank=same;\n";

    string cNodos="";
    string Cconecciones="";

    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoTutorial*aux=cabeza;
        int c=0;
        int cont=0;
        while(aux!=NULL){
                cont+=1;
                string ax="X:"+to_string(aux->x)+"\nY:"+to_string(aux->y);
                cNodos+="Nodos"+to_string(cont)+"[label=\" "+ax +"\"]\n";
                if(aux->siguiente!=NULL){
                    Cconecciones+="Nodos"+to_string(cont)+"->";
                }else{
                    Cconecciones+="Nodos"+to_string(cont);
                }

            aux=aux->siguiente;
        }
        contenido+="\n"+cNodos+Cconecciones+"\n";
        contenido+="}\n }";
    }
    try
    {
        string path = ".\\Reportes\\";
        ofstream file;
        file.open(path + "ColaTurorial.dot",std::ios::out);
        if(file.fail())
        {
            exit(1);
        }
        file<<contenido;
        file.close();
        string command = "dot -Tpdf " + path + "ColaTurorial.dot -o  " + path + "ColaTurorial.pdf";
        system(command.c_str());
    }
    catch(exception e)
    {
        cout<<"Ocurrio un error"<<endl;
    }

}


