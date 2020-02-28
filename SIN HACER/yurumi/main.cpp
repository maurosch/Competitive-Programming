/*
http://juez.oia.unsam.edu.ar/#/task/yurumi/statement
Schiavinato Mauro
/02/2018
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define rforn(i, n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
typedef pair<int,int> ii;
typedef vector<vector<int> > matriz;

// Explicación:


int sumaRect(matriz &a, int x1, int y1, int x2, int y2)
{
    return abs(a[y2][x2]-a[y1-1][x2]-a[y2][x1-1]+a[y1-1][x1-1]);
}

int main()
{
    ifstream in("yurumi.in");
    ofstream out("yurumi.out");
    int ancho, alto, obstaculos;
    in >> alto >> ancho >> obstaculos;

    matriz mapaObstaculos(alto,vector<int>(ancho));
    matriz mapaSumaObstaculos(alto+1,vector<int>(ancho+1));
    matriz largoRect(alto+2,vector<int>(ancho+2)); //Guardamos máx rect en cada casilla para reutilizar
    
    forn(i, largoRect.size()) 
        largoRect[i][largoRect[0].size()-1] = -1;
    forn(i, largoRect[0].size()) 
        largoRect[largoRect.size()-1][i] = -1;

    forn(i,obstaculos)
    {
        int x, y;
        in >> y >> x;
        x--; y--;
        mapaObstaculos[y][x] = -1;
        largoRect[y+1][x+1] = -1;
    }
    
    int bestX, bestY, longBase = 0;
    for(int i = mapaSumaObstaculos.size()-1; i >= 1; i--)
        for(int j = mapaSumaObstaculos[0].size()-1; j >= 1; j--)
            if(mapaObstaculos[i-1][j-1] == 0)
            {
                largoRect[i][j] = min(min(largoRect[i+1][j+1],largoRect[i][j+1]),largoRect[i+1][j])+1;
                if(largoRect[i][j] > longBase)
                {
                    bestX = j;
                    bestY = i;
                    longBase = largoRect[i][j];
                }
            }



    int bestX2, bestY2, longBase2 = 0;
    for(int i = mapaSumaObstaculos.size()-1; i >= 1; i--)
        for(int j = mapaSumaObstaculos[0].size()-1; j >= 1; j--)
            if(mapaObstaculos[i-1][j-1] == 0)
            {
                largoRect[i][j] = min(min(largoRect[i+1][j+1],largoRect[i][j+1]),largoRect[i+1][j])+1;
                if(largoRect[i][j] > )
            }

    out << bestX-1 << " " << bestY-1 << endl << longBase+1 << endl << bestFrutales;
    return 0;
}




