#include "LDobleUsuario.h"

void LDobleUsuario::Insertar(string nick,string pass,int edad,int moneda ){
     NodoUsuario*nNodo=new NodoUsuario(nick,pass,edad,moneda);
     if ((cabeza==NULL) && (cola==NULL)){
            cabeza=nNodo;
            cola=nNodo;
     }else{
         cola->siguiente=nNodo;
         nNodo->anterior=cola;
         nNodo->siguiente=cabeza;
         cabeza->anterior=nNodo;
         cola=nNodo;
     }
     this->tamanio+=1;

}
void LDobleUsuario::EliminarPrimero(){
    if (this->tamanio==0){
        this->cabeza=NULL;
        this->cabeza=NULL;
    }
    else{
        NodoUsuario*nEliminado=cabeza;
        cabeza=nEliminado->siguiente;
        cabeza->anterior=cola;
        cola->siguiente=cabeza;
        nEliminado->anterior=NULL;
        nEliminado->siguiente=NULL;
        tamanio-=1;
        delete(nEliminado);
    }

}
void LDobleUsuario::EliminarUltimo(){
    if (this->tamanio==0){
        this->cabeza=NULL;
        this->cabeza=NULL;
    }
    else{
        NodoUsuario*nEliminado=cola;
        cola = nEliminado->anterior;
        cola->siguiente = cabeza;
        cabeza->anterior =cola;
        nEliminado->anterior = NULL;
        nEliminado->siguiente =NULL;
        tamanio -= 1;
        delete(nEliminado);

    }
}
int LDobleUsuario::OIndice(string nick){
    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int cont=this->tamanio;
    int manda1=-1;
    int manda2;
    while (cont!=0){
        manda1=manda1+1;
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            if(nick==NodoMostrar->nick){
                manda2=manda1;
                break;
            }
            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            cont-=1;

        }else{
            break;
        }

    }
    return manda2;
}

void LDobleUsuario::Eliminar(string nick){
    int indi=this->OIndice(nick);
    if(indi==0){
        this->EliminarPrimero();
    }else if(indi==tamanio-1){
        this->EliminarUltimo();
    }else {
        NodoUsuario*NodoMostrar;
        NodoMostrar=cabeza;
        bool pivote=true;
        int cont=this->tamanio;
        while (cont!=0){
            if((NodoMostrar!=cabeza)||(pivote!=false)){
                if(NodoMostrar->nick==nick){
                    NodoUsuario*nAnterior=NodoMostrar->anterior;
                    NodoUsuario*nSiguiente=NodoMostrar->siguiente;
                    nAnterior->siguiente=nSiguiente;
                    nSiguiente->anterior  =nAnterior;
                    NodoMostrar->anterior = NULL;
                    NodoMostrar->siguiente =NULL;
                    delete(NodoMostrar);
                    tamanio -= 1;
                    break;
                }
                NodoMostrar=NodoMostrar->siguiente;
                pivote=false;
                cont-=1;
                }else{
                    break;
                }
        }
    }


}



void LDobleUsuario::Mostrar(){

    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            cout<<"nick: "<<NodoMostrar->nick << "       Password: " << NodoMostrar->pass<< "        Edad:  " << NodoMostrar->edad<< "         Monedas: " << NodoMostrar->monedas<<endl;
            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            cont-=1;
            cout<<endl;
        }else{
            break;
        }

    }
}


void LDobleUsuario::OrdenarAcendente(){
     NodoUsuario*aux=cabeza;
      NodoUsuario*aux2;

    do{
        aux2 = aux->siguiente;
        while(aux2!=cabeza){
            if(aux->edad > aux2->edad){

                        string aux2pn=aux->nick;
                        aux->nick=aux2->nick;
                        aux2->nick=aux2pn;

                        string aux2pp=aux->pass;
                        aux->pass=aux2->pass;
                        aux2->pass=aux2pp;

                        int aux2pe=aux->edad;
                        aux->edad=aux2->edad;
                        aux2->edad=aux2pe;

                        int aux2pm=aux->monedas;
                        aux->monedas=aux2->monedas;
                        aux2->monedas=aux2pm;


            }
            aux2 = aux2->siguiente;
        }
        aux = aux->siguiente;
        aux2 = aux->siguiente;
    }while(aux2!=cabeza);
    aux = cabeza;
    do
        {

            aux = aux->siguiente;
        } while (aux != cabeza);
}

void LDobleUsuario::OrdenarDes(){
     NodoUsuario*aux=cabeza;
      NodoUsuario*aux2;

    do{
        aux2 = aux->siguiente;
        while(aux2!=cabeza){
            if(aux->edad < aux2->edad){

                        string aux2pn=aux->nick;
                        aux->nick=aux2->nick;
                        aux2->nick=aux2pn;

                        string aux2pp=aux->pass;
                        aux->pass=aux2->pass;
                        aux2->pass=aux2pp;

                        int aux2pe=aux->edad;
                        aux->edad=aux2->edad;
                        aux2->edad=aux2pe;

                        int aux2pm=aux->monedas;
                        aux->monedas=aux2->monedas;
                        aux2->monedas=aux2pm;


            }
            aux2 = aux2->siguiente;
        }
        aux = aux->siguiente;
        aux2 = aux->siguiente;
    }while(aux2!=cabeza);
    aux = cabeza;
    do
        {

            aux = aux->siguiente;
        } while (aux != cabeza);
}


int LDobleUsuario::MMoneda(string nicks){
    int total=0;

    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            if(NodoMostrar->nick==nicks){
                total=NodoMostrar->monedas;
                break;
            }
            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }
    return total;
}

void LDobleUsuario::ModificarNick(string nick1,string nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->nick){
                ENick->nick=nick2;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }

}

void LDobleUsuario::ModificarPass(string nick1,string nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->nick){
                ENick->pass=nick2;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }

}

void LDobleUsuario::ModificarEdad(string nick1,int  nick2){
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if(nick1==ENick->nick){
                ENick->edad=nick2;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }

}

void LDobleUsuario::Graficar(){

     string cGeneral="digraph G {\n"
            "node[shape = box,width=0.7,height=0.7,fillcolor=\"white\" color=\"black\"  ]\n"
            "graph [ nodesep=\"0.5\"]\n"
            "graph [pad=\"0.2\", nodesep=\"0.5\", ranksep=\"2\"]\n";

    string nodos2="";
    string cNodos="";
    string cConecciones="";
    int cont=0;
    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int contador=tamanio;
    int casa=2;
    while (contador!=0){
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            cont+=1;
            string bloque="Nick :"+NodoMostrar->nick+"\nPassword :"+NodoMostrar->pass+"\nEdad :"+to_string(NodoMostrar->edad)+"\nMonedas :"+to_string(NodoMostrar->monedas);
            cNodos+="Nodo"+to_string(cont)+"[label=\" "+ bloque +"\"]\n";
            if(NodoMostrar->siguiente==cabeza){
                cConecciones+="Nodo"+to_string(cont)+"->"+"Nodo1\n";
            }else{

                cConecciones+="Nodo"+to_string(cont)+"->";
            }



            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            contador-=1;

        }else{
            break;
        }

    }
     cGeneral+=cNodos+"edge[ dir=\"both\"]; "+"\n{rank = same;\n"+cConecciones+"\n}\n edge[dir=\"forward\"]; \n";
    cGeneral+="\n}";

    try
    {
        string path = ".\\Reportes\\";
        ofstream file;
        file.open(path + "ListaUsuarios.dot",std::ios::out);
        if(file.fail())
        {
            exit(1);
        }
        file<<cGeneral;
        file.close();
        string command = "dot -Tpdf " + path + "ListaUsuarios.dot -o  " + path + "ListaUsuarios.pdf";
        system(command.c_str());
    }
    catch(exception e)
    {
        cout<<"Ocurrio un error"<<endl;
    }



}


bool LDobleUsuario::Login(string nick,string pass){
    bool encontrado=false;
    NodoUsuario*ENick;
    ENick=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((ENick!=cabeza)||(pivote!=false)){
            if((nick==ENick->nick)&&(pass==ENick->pass)){
                encontrado=true;
                break;
            }
            ENick=ENick->siguiente;
            pivote=false;
            cont-=1;
        }else{
            break;
        }

    }
    return encontrado;

}
bool LDobleUsuario::Existe(string nick){
    bool esta=false;
    NodoUsuario*NodoMostrar;
    NodoMostrar=cabeza;
    bool pivote=true;
    int cont=this->tamanio;

    while (cont!=0){
        if((NodoMostrar!=cabeza)||(pivote!=false)){
            if(nick==NodoMostrar->nick){
                esta=true;
                break;
            }
            NodoMostrar=NodoMostrar->siguiente;
            pivote=false;
            cont-=1;

        }else{
            break;
        }

    }
    return esta;
}





