#include "LDPilas.h"
#include"NodoLPilas.h"

void LDPilas::Insertar(string nombre,Pila*lista){
    NodoLPilas*nNuevo=new NodoLPilas(nombre,lista);
    if (cabeza==NULL){
        cabeza=nNuevo;
        tamanio+=1;
     }else{
         NodoLPilas*aux=cabeza;
         while(aux->siguiente!=NULL){
                aux=aux->siguiente;
         }
         aux->siguiente=nNuevo;
         tamanio+=1;
     }

}

/*void LDPilas::Mostrar(){


     string cGeneral="digraph G {\n"
            "node[shape = box,width=0.7,height=0.7,fillcolor=\"white\" color=\"black\"  ]\n"
            "graph [ nodesep=\"0.5\"]\n";


    string nodos2="";
    string cNodos="";
    string cConecciones="";
    int cont=0;
    NodoLPilas*NodoMostrar=cabeza;
    int contador=tamanio;
    int casa=2;
    while (NodoMostrar!=NULL){

            cont+=1;
            cNodos+="NodoSA"+to_string(cont)+"[label=\""+ NodoMostrar->Nombre+"\""+"]\n";
            nodos2+=NodoMostrar->lista->Mostrar(cont,"NodoSA"+to_string(cont));
            if(NodoMostrar->siguiente==NULL){
                cConecciones+="NodoSA"+to_string(cont);
            }else{

                cConecciones+="NodoSA"+to_string(cont)+"->";
            }

            NodoMostrar=NodoMostrar->siguiente;
    }
    cGeneral+=cNodos+ +"\n{rank = same;\n"+cConecciones+"\n}\n edge[dir=\"forward\"]; \n";
    cGeneral+=nodos2;
    cGeneral+="\n}";



    try
    {
        string path = ".\\Reportes\\";
        ofstream file;
        file.open(path + "ListaPilas.dot",std::ios::out);
        if(file.fail())
        {
            exit(1);
        }
        file<<cGeneral;
        file.close();
        string command = "dot -Tpdf " + path + "ListaPilas.dot -o  " + path + "ListaPilas.pdf";
        system(command.c_str());
    }
    catch(exception e)
    {
        cout<<"Ocurrio un error"<<endl;
    }



}*/

void LDPilas::Mostrar(){



    int cont=0;
    NodoLPilas*NodoMostrar=cabeza;
    int contador=tamanio;
    int casa=2;
    while (NodoMostrar!=NULL){
            cout<<NodoMostrar->Nombre<<endl;
            NodoMostrar->lista->Mostrar();
            NodoMostrar=NodoMostrar->siguiente;
    }





}


