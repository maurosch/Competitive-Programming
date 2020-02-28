#include <iostream>
#include <fstream>
#define For(i,n) for(int i = 0; i < n; i++)
#define rFor(i,n) for(int i = n-1; i >= 0; i--)
#define RAYA cout << "==============" << endl;
using namespace std;
#define MAX_COORD 15
enum tablero
{
    r45,
    r135,
    recto,
    vacio,
};

enum direc
{
    arr,
    aba,
    izq,
    der,
};

void mover(int tablero[MAX_COORD][MAX_COORD], bool tableroBool[MAX_COORD][MAX_COORD], int x, int y, direc direccion)
{
    //cout << y << " " << x << endl;
    while(!tableroBool[y][x])
    {
        switch(tablero[y][x])
        {
            case tablero::r45:
                tableroBool[y][x] = true;
                if(direccion == direc::der) direccion = direc::arr;
                else if(direccion == direc::izq) direccion = direc::aba;
                else if(direccion == direc::aba) direccion = direc::izq;
                else if(direccion == direc::arr) direccion = direc::der;
            break;
            case tablero::r135:
                tableroBool[y][x] = true;
                if(direccion == direc::der) direccion = direc::aba;
                else if(direccion == direc::izq) direccion = direc::arr;
                else if(direccion == direc::aba) direccion = direc::der;
                else if(direccion == direc::arr) direccion = direc::izq;
            break;
            case tablero::recto:
                tableroBool[y][x] = true;
                if(direccion == direc::aba) direccion = direc::arr;
                else if(direccion == direc::arr) direccion = direc::aba;
                else if(direccion == direc::izq) direccion = direc::der;
                else if(direccion == direc::der) direccion = direc::izq;
            break;
        }
        switch (direccion) {
            case direc::aba: y--; break;
            case direc::arr: y++; break;
            case direc::izq: x--; break;
            case direc::der: x++; break;
        }
    }
}

void construir(int tablero[MAX_COORD][MAX_COORD], int x1, int y1, int x2, int y2)
{

    if(y1 == y2 and x2 < x1)
    {
        //HORIZONTAL E IZQUIERDA
        for(int i = min(x1, x2); i < max(x1, x2); i++)
        {
            tablero[y1-1][i] = tablero::recto;
        }
        return;
    }
    if(y1 == y2 and x1 < x2)
    {
        //HORIZONTAL Y DERECHA
        for(int i = min(x1, x2); i < max(x1, x2); i++)
        {
            tablero[y1][i] = tablero::recto;
        }
        return;
    }

    if(x1 == x2 and y2 < y1)
    {
        //YENDO VERTICAL Y PARA ABAJO
        for(int i = min(y1, y2); i < max(y1, y2); i++)
        {
            tablero[i][x1] = tablero::recto;
        }
        return;
    }
    if(x1 == x2 and y1 < y2)
    {
        //YENDO VERTICAL Y PARA ARRIBA
        for(int i = min(y1, y2); i < max(y1, y2); i++)
        {
            tablero[i][x1-1] = tablero::recto;
        }
        return;
    }

    if(x2 > x1 and y2 > y1)
    {
        //DIAGONAL PARA ARRIBA Y DERECHA "/"
        for(int i = min(x1, x2), j = min(y1, y2); i < max(x1, x2); i++, j++)
            tablero[j][i] = tablero::r45;
        return;
    }
    if(x2 < x1 and y2 > y1)
    {
        //DIAGONAL PARA ARRIBA E IZQUIERDA "\"
        for(int i = min(x1, x2), j = min(y1, y2); i < max(x1, x2); i++, j++)
            tablero[j][i] = tablero::r135;
        return;
    }
    if(x2 > x1 and y2 < y1)
    {
        //DIAGONAL PARA ABAJO Y DERECHA "\"
        for(int i = min(x1, x2), j = min(y1, y2); i < max(x1, x2); i++, j++)
            tablero[j][i] = tablero::r135;
        return;
    }
    if(x2 < x1 and y2 < y1)
    {
        //DIAGONAL PARA ABAJO E IZQUIERDA "/"
        for(int i = min(x1, x2), j = min(y1, y2); i < max(x1, x2); i++, j++)
            tablero[j][i] = tablero::r45;
        return;
    }
}

int main()
{
    ifstream in("billar.in");
    ofstream out("billar.out");
    int n, xRect, yRect, xRect2, yRect2;
    int tablero[MAX_COORD][MAX_COORD];
    bool tableroBool[MAX_COORD][MAX_COORD];
    For(i, MAX_COORD){
        For(j, MAX_COORD){
            tablero[i][j] = tablero::vacio;
            tableroBool[i][j] = false;
        }
    }

    in >> n;
    int anteriorX, anteriorY;
    in >> anteriorX >> anteriorY;
    anteriorX++; anteriorY++;
    int primX = anteriorX, primY = anteriorY;
    For(i, n-1)
    {
        int x, y;
        in >> x >> y; x++; y++;
        construir(tablero, anteriorX, anteriorY, x, y);
        anteriorX = x; anteriorY = y;
    }
    construir(tablero, anteriorX, anteriorY, primX, primY);
    in >> xRect >> yRect >> xRect2 >> yRect2;
    int xRectMin = min(xRect, xRect2)+1;
    int xRectMax = max(xRect, xRect2);
    int yRectMin = min(yRect, yRect2)+1;
    int yRectMax = max(yRect, yRect2);
    rFor(i, MAX_COORD)
    {
        For(j, MAX_COORD)
        {
            if(tablero[i][j] == tablero::r45) cout << "4" << " ";
            if(tablero[i][j] == tablero::r135) cout << "5" << " ";
            if(tablero[i][j] == tablero::recto) cout << "&" << " ";
            if(tablero[i][j] == tablero::vacio) cout << "V" << " ";
        }
        cout << endl;
    }
    for(int i = yRectMin; i <= yRectMax; i++)
    {
        mover(tablero, tableroBool, xRectMin, i, direc::izq);
        mover(tablero, tableroBool, xRectMin, i, direc::der);
    }
    for(int i = xRectMin; i <= xRectMax; i++)
    {
        mover(tablero, tableroBool, i, yRectMin, direc::arr);
        mover(tablero, tableroBool, i, yRectMin, direc::aba);
    }
    rFor(i, MAX_COORD)
    {
        For(j, MAX_COORD)
        {
            if(tableroBool[i][j]) cout << "*" << " ";
            else cout << "N" << " ";
        }
        cout << endl;
    }


    return 0;
}
