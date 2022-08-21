 #include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>
#include<nlohmann/json.hpp>
#include "LDobleUsuario.h"

using namespace std;
using namespace nlohmann;

LDobleUsuario *LUsuario=new LDobleUsuario();



int MenuPrincipal();
void gotoxy();
void clear();
int  MenuPrincipal();
void titulo();
void CargaMasiva();




int main(){

    int op;
    do
    {
        op = MenuPrincipal();
        switch (op)
        {
            case 0:  CargaMasiva(); getch(); break;
            case 1:  break;  /*Estudiantes->graficar(); getch();*/
            case 2:  break;
            case 3:  break;
            case 4: break;
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

void CargaMasiva(){
    clear();
    ifstream AJson("C:/Users/david/Desktop/json.json");
    nlohmann::json  objeto= nlohmann::json::parse(AJson);
    int tusuario=objeto["usuarios"].size();
    int tarticulos=objeto["articulos"].size();
    int ttutorial=objeto["tutorial"].size();

    for(int i=0;i<tusuario;i++){
            string nicks=objeto["usuarios"][i]["nick"].get<string>();
            string passs=objeto["usuarios"][i]["password"].get<string>();
            string edads=objeto["usuarios"][i]["edad"].get<string>();
            string moneds=objeto["usuarios"][i]["monedas"].get<string>();
            int edads2=stoi(edads);
            int moneds2=stoi(moneds);
            LUsuario->Insertar(nicks,passs,edads2,moneds2);

    }


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




