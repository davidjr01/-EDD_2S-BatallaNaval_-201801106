#include "LCategoria.h"



void LCategoria::Insertar(string categoria,LArticulo*lista){
    NodoCategoria*nNuevo=new NodoCategoria(categoria,lista);
    if (cabeza==NULL){
        cabeza=nNuevo;
        tamanio+=1;
     }else{
         NodoCategoria*aux=cabeza;
         while(aux->siguiente!=NULL){
                aux=aux->siguiente;
         }
         aux->siguiente=nNuevo;
         tamanio+=1;
     }

}

void LCategoria::Graficar(){


     string cGeneral="digraph G {\n"
            "node[shape = box,width=0.7,height=0.7,fillcolor=\"white\" color=\"black\"  ]\n"
            "graph [ nodesep=\"0.5\"]\n"
             "rankdir=LR;\n";


    string nodos2="";
    string cNodos="";
    string cConecciones="";
    int cont=0;
    NodoCategoria*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int contador=tamanio;
    int casa=2;
    while (NodoMostrar!=NULL){

            cont+=1;
            cNodos+="NodoSA"+to_string(cont)+"[label=\""+ NodoMostrar->categoria +"\""+"]\n";
            nodos2+=NodoMostrar->lista->Graficar(cont,"NodoSA"+to_string(cont));
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
        file.open(path + "ListaCategoria.dot",std::ios::out);
        if(file.fail())
        {
            exit(1);
        }
        file<<cGeneral;
        file.close();
        string command = "dot -Tpdf " + path + "ListaCategoria.dot -o  " + path + "ListaCategoria.pdf";
        system(command.c_str());
    }
    catch(exception e)
    {
        cout<<"Ocurrio un error"<<endl;
    }



}



void LCategoria::Mostrar(){
    int xs=0;
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoCategoria*aux=cabeza;
        while(aux!=NULL){
            string casa=aux->categoria;
            aux->lista->Mostrar(casa,xs);
            xs=xs + aux->lista->Numero();
            aux=aux->siguiente;
        }
    }

}

int LCategoria::Numero(){
    int contador=0;
    if(cabeza==NULL){
            cout<<"vacia"<<endl;

    }else{
        NodoCategoria*aux=cabeza;
        while(aux!=NULL){
            contador=contador + aux->lista->Numero();
            aux=aux->siguiente;
        }
    }
    return contador;
}

bool LCategoria::Existe(string categoria){
    bool s=false;
    if(cabeza==NULL){
            s=false;
    return s;

    }else{
        NodoCategoria*aux=cabeza;
        while(aux!=NULL){
            if(categoria==aux->categoria){
                    s=true;
                    break;
            }else{
                s=false;
            }
            aux=aux->siguiente;
        }
        return s;
    }

}

void LCategoria::Buscar(string categoria,string id,int precio,string nombre,string src){
    NodoCategoria*aux=cabeza;
    while(aux!=NULL){
        if(categoria==aux->categoria){
            aux->lista->Insertar(id,precio,nombre,src);
            break;
        }
        aux=aux->siguiente;
    }
}


