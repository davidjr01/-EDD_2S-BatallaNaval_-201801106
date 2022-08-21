#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>

using namespace std;
int MenuPrincipal();


void gotoxy();
void clear();
int  MenuPrincipal();
void titulo();

int main(){

    int op;
    do
    {
        op = MenuPrincipal();
        switch (op)
        {
            case 0: cout<<"holamundo" <<endl; getch(); break;
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




