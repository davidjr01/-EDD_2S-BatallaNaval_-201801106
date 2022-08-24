 #include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include<nlohmann/json.hpp>
#include "LDobleUsuario.h"
#include "LCategoria.h"
#include "LArticulo.h"
#include "ListaTutorial.h"

using namespace std;
using namespace nlohmann;

LDobleUsuario *LUsuario=new LDobleUsuario();
LCategoria *Lcategoria=new LCategoria();
ListaTutorial*Ltutorial=new ListaTutorial();
string varibleUsuario="";
string varibleEdad="";



int MenuPrincipal();
void gotoxy();
void clear();
int  MenuPrincipal();
void titulo();
void CargaMasiva();
void Registrar();
void tituloRegistro();
void Logueado();
void TituloBienvenido();
void Login();
void TituloLogin();
void TituloUser();
void VerArticulo();



int main(){
    VerArticulo();
    getch();
    int x=0;
    int op=10;
    do
    {
        op = MenuPrincipal();
        switch (op)
        {
            case 0: clear(); CargaMasiva(); getch(); break;
            case 1: clear();Registrar();  break;
            case 2: clear(); Login();/*Logueado();*/  break;
            case 3: clear(); LUsuario->Mostrar(); getch(); break;break;

        }
    } while (op != 4);

    return 0;

}
void clear()
{
    system("cls");
}

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void VerArticulo(){ ///////////////////////////////////////////////////////////////
    gotoxy(85,5);cout<<"TOTAL  Tokens   "<<"10000";
    gotoxy(2,6);cout<<"TIENDA";
    gotoxy(7,7);cout<<"ID";



}
void ModificarUsuario(){
     int opcion2=0;
    while(opcion2!=4){

            string nick,pass;
            int edad;
            clear();
            gotoxy(10,5); cout<<"1.  NICK";
            gotoxy(10,6);cout<< "2.  EDAD";
            gotoxy(10,7); cout<<"3.  PASSWORD";
            gotoxy(10,8);cout<< "4.  SALIR";
            gotoxy(10,11);cin>>opcion2;
            switch (opcion2){
            case 1:{
                clear();
                cout<<"Ingrese Nick  : ";
                cin>>nick;
                if(LUsuario->Existe(nick)==true){
                    cout<<"YA EXISTE UN USUARIO CON ESE NOMBRE";
                    getch();

                }else{
                     LUsuario->ModificarNick(varibleUsuario,nick);
                    varibleUsuario=nick;
                    cout<<"SE HA ACTUALIZADO";
                    getch();

                }
            } break;
            case 2:{
                clear();
                cout<<"INGRESE PASWORD : ";
                cin>>pass;
                LUsuario->ModificarPass(varibleUsuario,pass);
                cout<<"SE HA ACTUALIZADO";
                getch();

            } break;
            case 3: {
                clear();
                cout<<"INGRESE EDAD : ";
                cin>>edad;
                LUsuario->ModificarEdad(varibleUsuario,edad);
                varibleEdad=edad;
                cout<<"SE HA ACTUALIZADO";
                getch();
            } break;

        }


    }

}
void Login(){
    clear();
    string lousuario;
    string lopass;
    TituloLogin();
    gotoxy(20,15); cout<<"USUARIO :";
    gotoxy(20,17); cout<<"PASSWORD :";
    gotoxy(20 +15,15); cin>>lousuario;
    gotoxy(20 +15,17); cin>>lopass;
    if(LUsuario->Existe(lousuario)==true){
        varibleUsuario=lousuario;
        clear();
        TituloBienvenido();
        Sleep(1000);
        clear();
        Logueado();

    }else{
        gotoxy(20 +15,20); cout<<"USUARIO O PASSWORD INCORRECTO";
        getch();
    }





}

void Logueado(){
    int opcion=0;
    while(opcion!=6){
            clear();
            TituloUser();
            gotoxy(10,14); cout<<"1.  EDITAR INFORMACION";
            gotoxy(10,15);cout<< "2.  ELIMINAR CUENTA";
            gotoxy(10,16); cout<<"3.  VER TUTORIAL";
            gotoxy(10,17);cout<< "4.  VER ARTICULOS DE LA TIENDA";  ///////////////////////////////////////////////////////////////
            gotoxy(10,18);cout<< "5.  REALIZAR MOVIMIENTOS";
            gotoxy(10,19);cout<< "6.  SALIR"<<endl;
            gotoxy(10,21); cin>>opcion;
            switch (opcion){
            case 1: clear();ModificarUsuario(); getch(); break;
            case 2: clear();cout<<"eliminar"; getch(); break;
            case 3: clear();cout<<"tutorial"; break;
            case 4: clear();VerArticulo(); break;
            case 5: break;
        }


    }

}
void Registrar(){
    string iusuario,ipass;
    int iedad;
    tituloRegistro();
    gotoxy(10,13); cout<<"USUARIO :";
    gotoxy(10,15); cout<<"PASSWORD :";
    gotoxy(10,17); cout<<"Edad :";
    gotoxy(28,13); cin>>iusuario;
    gotoxy(28,15); cin>>ipass;
    gotoxy(28,17); cin>>iedad;
    if(LUsuario->Existe(iusuario)==true){
        gotoxy(28,20);cout<<"ERROR , NOMBRE DE USUARIO YA ESTA REGISTRADO";
        getch();
    }else{
        LUsuario->Insertar(iusuario,ipass,iedad,0);
        gotoxy(28,20);cout<<"SE REGISTRO EL USUARIO";
        getch();
    }




}

void CargaMasiva(){


    ifstream AJson("C:/Users/david/Desktop/json.json");
    nlohmann::json  objeto= nlohmann::json::parse(AJson);
    int tusuario=objeto["usuarios"].size();
    int tarticulos=objeto["articulos"].size();
    int ttutorial=objeto["tutorial"].size();

    for(int i=0;i<=tusuario -1;i++){
            string nicks=objeto["usuarios"][i]["nick"].get<string>();
            string passs=objeto["usuarios"][i]["password"].get<string>();
            string edads=objeto["usuarios"][i]["edad"].get<string>();
            string moneds=objeto["usuarios"][i]["monedas"].get<string>();
            int edads2=stoi(edads);
            int moneds2=stoi(moneds);
            if(LUsuario->Existe(nicks)==false){
                LUsuario->Insertar(nicks,passs,edads2,moneds2);
            }
    }

    for (int i=0; i<=tarticulos-1;i++){
            string categoria=objeto["articulos"][i]["categoria"].get<string>();
            string id=objeto["articulos"][i]["id"].get<string>();
            string precio=objeto["articulos"][i]["precio"].get<string>();
            string nombre=objeto["articulos"][i]["nombre"].get<string>();
            string src=objeto["articulos"][i]["src"].get<string>();
            int precio2=stoi(precio);
            if(Lcategoria->Existe(categoria)==true){
                Lcategoria->Buscar(categoria,id,precio2,nombre,src);
            }else{
                LArticulo *Larti=new LArticulo();
                Larti->Insertar(id,precio2,nombre,src);
                Lcategoria->Insertar(categoria,Larti);
            }
    }
    string ancho=objeto["tutorial"]["ancho"].get<string>();
    string alto=objeto["tutorial"]["alto"].get<string>();
    int ancho2=stoi(ancho);
    int alto2=stoi(alto);
    Ltutorial->InsertarPrimero(ancho2,alto2);

    for(int i=0;i<objeto["tutorial"]["movimientos"].size();i++){
            string x=objeto["tutorial"]["movimientos"][i]["x"].get<string>();
            string y=objeto["tutorial"]["movimientos"][i]["y"].get<string>();
            int x2=stoi(x);
            int y2=stoi(y);
            Ltutorial->InsertarPrimero(x2,y2);

    }
    cout<<"Los Datos fueron cargados con exito";




}






int  MenuPrincipal(){
    string m[5];
    m[0] = "   1. Carga Masiva";
    m[1] = "   2. Registro de Usuario";
    m[2] = "   3. Login";
    m[3] = "   4. Reportes";
    m[4] = "   5. Salir";
    char lec;
    int aux = 0, c, pos = 0;
    while (aux != 13)
    {
        clear();
        titulo();
        for (c = 0; c < 5; c++)
        {
            gotoxy(15, (c+7) * 2);
            if (pos == c)
            {
                cout <<">>> ";
            }
            cout << m[c];
        }

        lec = getch();
        aux = (int)lec;
        if (aux == 72)
        {
            if (pos > 0)
            {
                pos = pos - 1;
            }
            else
            {
                pos = 4;
            }
        }
        if (aux == 80)
        {
            if (pos < 4)
            {
                pos = pos + 1;
            }
            else
            {
                pos = 0;
            }
        }
    }
    return pos;

}
void TituloLogin(){
    int xs=21;


    gotoxy(9+xs,3); cout<<"$$\\       $$$$$$\\   $$$$$$\\  $$$$$$\\ $$\\   $$\\ ";
    gotoxy(9+xs,4); cout<<"$$ |     $$  __$$\\ $$  __$$\\ \\_$$  _|$$$\\  $$ |";
    gotoxy(9+xs,5); cout<<"$$ |     $$ /  $$ |$$ /  \\__|  $$ |  $$$$\\ $$ |";
    gotoxy(9+xs,6); cout<<"$$ |     $$ |  $$ |$$ |$$$$\\   $$ |  $$ $$\$$ |";
    gotoxy(9+xs,7); cout<<"$$ |     $$ |  $$ |$$ |\\_$$ |  $$ |  $$ \\$$$$ |";
    gotoxy(9+xs,8); cout<<"$$ |     $$ |  $$ |$$ |  $$ |  $$ |  $$ |\\$$$ |";
    gotoxy(9+xs,9); cout<<"$$$$$$$$\\ $$$$$$  |\\$$$$$$  |$$$$$$\\ $$ | \\$$ |";
    gotoxy(9+xs,10); cout<<"\\________|\\______/  \\______/ \\______|\\__|  \\__|";

}

void titulo(){
    gotoxy(9,3); cout<<"$$$$$$$\\             $$\\               $$\\ $$\\                 $$\\   $$\\                              $$\\";
    gotoxy(9,4); cout<<"$$  __$$\\            $$ |              $$ |$$ |                $$$\\  $$ |                             $$ |";
    gotoxy(9,5); cout<<"$$ |  $$ | $$$$$$\\ $$$$$$\\    $$$$$$\\  $$ |$$ | $$$$$$\\        $$$$\\ $$ | $$$$$$\\ $$\\    $$\\ $$$$$$\\  $$ |";
    gotoxy(9,6); cout<<"$$$$$$$\\ | \\____$$\\\\_$$  _|   \\____$$\\ $$ |$$ | \\____$$\\       $$ $$\\$$ | \\____$$\\\\$$\\  $$  |\\____$$\\ $$ |";  ///
    gotoxy(9,7); cout<<"$$  __$$\\  $$$$$$$ | $$ |     $$$$$$$ |$$ |$$ | $$$$$$$ |      $$ \\$$$$ | $$$$$$$ | \$$\\$$  / $$$$$$$ |$$ |";
    gotoxy(9,8); cout<<"$$ |  $$ |$$  __$$ | $$ |$$\\ $$  __$$ |$$ |$$ |$$  __$$ |      $$ |\\$$$ |$$  __$$ | \\$$$  / $$  __$$ |$$ |";
    gotoxy(9,9); cout<<"$$$$$$$  |\\$$$$$$$ | \\$$$$  |\\$$$$$$$ |$$ |$$ |\\$$$$$$$ |      $$ | \\$$ |\\$$$$$$$ |  \\$  /  \\$$$$$$$ |$$ |";
    gotoxy(9,10); cout<<"\\_______/  \\_______|  \\____/  \\_______|\\__|\\__| \\_______|      \\__|  \\__| \\_______|   \\_/    \\_______|\\__|";

}

void tituloRegistro(){
    int px=30;
    int py=2;
    gotoxy(px,3-py); cout<<" _____           _     _";
    gotoxy(px,4-py); cout<<"| ___ \\         (_)   | |";
    gotoxy(px,5-py); cout<<"| |_/ /___  __ _ _ ___| |_ _ __ ___ ";
    gotoxy(px,6-py); cout<<"|    // _ \\/ _` | / __| __| '__/ _ \\ ";
    gotoxy(px,7-py); cout<<"| |\\ \\  __/ (_| | \\__ \\ |_| | | (_) |";
    gotoxy(px,8-py); cout<<"\\_| \\_\\___|\\__, |_|___/\\__|_|  \\___/ ";
    gotoxy(px,9-py); cout<<"            __/ |                    ";
    gotoxy(px,10-py); cout<<"           |___/";

}
void TituloBienvenido(){

    gotoxy(9,9); cout<<"$$$$$$$\\  $$$$$$\\ $$$$$$$$\\ $$\\   $$\\ $$\\    $$\\ $$$$$$$$\\ $$\\   $$\\ $$$$$$\\ $$$$$$$\\   $$$$$$\\ ";
    gotoxy(9,10); cout<<"$$  __$$\\ \\_$$  _|$$  _____|$$$\\  $$ |$$ |   $$ |$$  _____|$$$\\  $$ |\\_$$  _|$$  __$$\\ $$  __$$\\ ";
    gotoxy(9,11); cout<<"$$ |  $$ |  $$ |  $$ |      $$$$\\ $$ |$$ |   $$ |$$ |      $$$$\\ $$ |  $$ |  $$ |  $$ |$$ /  $$ |";
    gotoxy(9,12); cout<<"$$$$$$$\\ |  $$ |  $$$$$\\    $$ $$\\$$ |\\$$\\  $$  |$$$$$\\    $$ $$\\$$ |  $$ |  $$ |  $$ |$$ |  $$ |";
    gotoxy(9,13); cout<<"$$  __$$\\   $$ |  $$  __|   $$ \\$$$$ | \\$$\\$$  / $$  __|   $$ \\$$$$ |  $$ |  $$ |  $$ |$$ |  $$ |";
    gotoxy(9,14); cout<<"$$ |  $$ |  $$ |  $$ |      $$ |\\$$$ |  \\$$$  /  $$ |      $$ |\\$$$ |  $$ |  $$ |  $$ |$$ |  $$ |";
    gotoxy(9,15); cout<<"$$$$$$$  |$$$$$$\\ $$$$$$$$\\ $$ | \\$$ |   \\$  /   $$$$$$$$\\ $$ | \\$$ |$$$$$$\\ $$$$$$$  | $$$$$$  |";
    gotoxy(9,16); cout<<"\\_______/ \\______|\\________|\\__|  \\__|    \\_/    \\________|\\__|  \\__|\\______|\\_______/  \\______/";



}
void TituloUser(){
   gotoxy(9,3); cout<<"___ ___ _______ _______ _______ ";
   gotoxy(9,4); cout<<"|   Y   |   _   |   _   |   _   \\";
   gotoxy(9,5); cout<<"|.  |   |   1___|.  1___|.  l   /";
   gotoxy(9,6); cout<<"|.  |   |____   |.  __)_|.  _   1";
   gotoxy(9,7); cout<<"|:  1   |:  1   |:  1   |:  |   |";
   gotoxy(9,8); cout<<"|::.. . |::.. . |::.. . |::.|:. |";
   gotoxy(9,9); cout<<"`-------`-------`-------`--- ---'";
}




