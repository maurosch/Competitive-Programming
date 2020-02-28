/*
http://juez.oia.unsam.edu.ar/#/task/frutales/statement
Schiavinato Mauro
14/02/2018
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
// Generamos un prefix sum Array 2D para frutales y otro para pinos
// Vamos por cada casilla y calculamos para cada una 
// el mayor rectangulo posible de crear utilizando esa casilla como 
// esquina del rectangulo con la mayor cant de frutales.
// Esto lo hacemos mediante una busqueda binaria y el prefix sum de frutales
// Para saber el máximo tamaño que se puede agrandar el rectangulo en cada casilla
// podemos hacer una busqueda lineal con el prefix sum de pinos pero se pasa de tiempo.
// Más rápido sería una busqueda binaria con el prefix sum pero tampoco pasa el tiempo dado. 
// Usando un truquito de completar al revez la tabla podemos reutilizar valores anteriores
// ya que el tamaño máximo en una casilla es el tamaño de la casilla diagonal derecha arriba +1
// y así nos ahorramos una busqueda lineal/binaria.
// La complejidad con este truquito sigue siendo igual a la de usar 2 búsquedas binarias:
// O(n^2 * log(n)) pero se reduce la constante omitida y pasa en el tiempo dado

int sumaRect(matriz &a, int x1, int y1, int x2, int y2)
{
    return abs(a[y2][x2]-a[y1-1][x2]-a[y2][x1-1]+a[y1-1][x1-1]);
}

int main()
{
    ifstream in("frutales.in");
    ofstream out("frutales.out");
    int ancho, alto, cantPinos, cantFrutales;
    in >> ancho >> alto >> cantPinos >> cantFrutales;

    matriz mapaFrutales(alto,vector<int>(ancho));
    matriz mapaPinos(alto,vector<int>(ancho));
    matriz mapaSumaFrutales(alto+1,vector<int>(ancho+1));
    matriz mapaSumaPinos(alto+1,vector<int>(ancho+1));
    
    matriz largoRect(alto+2,vector<int>(ancho+2)); //Guardamos máx rect en cada casilla para reutilizar
    forn(i, largoRect.size()) largoRect[i][largoRect[0].size()-1] = -1;
    forn(i, largoRect[0].size()) largoRect[largoRect.size()-1][i] = -1;

    forn(i,cantPinos)
    {
        int x, y;
        in >> x >> y;
        x--; y--;
        mapaPinos[y][x] = 1;
        largoRect[y+1][x+1] = -1;
    }
    forn(i,cantFrutales)
    {
        int x, y;
        in >> x >> y;
        x--; y--;
        mapaFrutales[y][x] = 1;
    }

    forsn(i,1,mapaSumaFrutales.size())
    {
        forsn(j,1,mapaSumaFrutales[0].size())
        {
            mapaSumaFrutales[i][j] = mapaSumaFrutales[i][j-1] + mapaSumaFrutales[i-1][j] - mapaSumaFrutales[i-1][j-1] + mapaFrutales[i-1][j-1];
            mapaSumaPinos[i][j] = mapaSumaPinos[i][j-1] + mapaSumaPinos[i-1][j] - mapaSumaPinos[i-1][j-1] + mapaPinos[i-1][j-1];
        }
    }

    int bestX, bestY, bestFrutales = 0, longBase;
    for(int i = mapaSumaFrutales.size()-1; i >= 1; i--)
    {
        for(int j = mapaSumaFrutales[0].size()-1; j >= 1; j--)
        {
            if(mapaPinos[i-1][j-1] == 0)
            {
                ///busqueda binaria para max de frutales
                largoRect[i][j] = min(min(largoRect[i+1][j+1],largoRect[i][j+1]),largoRect[i+1][j])+1;
                int c = sumaRect(mapaSumaFrutales, j, i, j+largoRect[i][j], i+largoRect[i][j]);
                int hi = largoRect[i][j];
                int lo = 0;

                while(hi-lo > 1)
                {
                    int medio = (hi+lo)/2;
                    if(sumaRect(mapaSumaFrutales, j, i, j+medio, i+medio) < c)
                        lo = medio;
                    else
                        hi = medio;
                }
                if(c > bestFrutales or (c == bestFrutales and hi < longBase))
                {
                    bestFrutales = c;
                    bestX = j;
                    bestY = i;
                    longBase = hi;
                }
            }
        }
    }

    out << bestX-1 << " " << bestY-1 << endl << longBase+1 << endl << bestFrutales;
    return 0;
}




