#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
typedef pair<int,int> ii;

bool valido(int x, int y, int maximos)
{
    return (x >= 0 and y >= 0 and x < maximos and y < maximos); 
}

int dfs(vector<vector<pair<char,int>>> &grafo, vector<vector<vector<int>>> &dp, ii start, string &palabra, int indice)
{
    //first es posicion horizontal. Creciente a la derecha.
    //second es posicion vertical. Creciente hacia abajo.
    if(indice == int(palabra.size())-1)
        return grafo[start.first][start.second].second;

    if(dp[start.first][start.second][indice] != -1) 
        return dp[start.first][start.second][indice];

    dp[start.first][start.second][indice] = 0;

    vector<int> x = {start.first, start.first, start.first+1, start.first-1};
    vector<int> y = {start.second-1, start.second+1, start.second, start.second};

    forn(l, 4)
    {
        int indiceX = x[l], indiceY = y[l];

        if( valido(indiceX, indiceY, int(grafo.size())) and palabra[indice+1] == grafo[indiceX][indiceY].first )
        {
            ii aux = {indiceX,indiceY};
            dp[start.first][start.second][indice] = max( dp[start.first][start.second][indice], dfs(grafo, dp, aux, palabra, indice+1) );
        }
    }

    if (dp[start.first][start.second][indice] != 0)
        dp[start.first][start.second][indice] += grafo[start.first][start.second].second;

    return dp[start.first][start.second][indice];
}

int main()
{
    ifstream in("rayuela.in");
    ofstream out("rayuela.out");
    int d, p;

    in >> d >> p;

    vector<vector<pair<char,int>>>grafo(d, vector<pair<char,int>>(d, pair<char,int>('0',0)));
    forn(i, d)
        forn(j, d)
            in >> grafo[i][j].first >> grafo[i][j].second;

    vector<string>palabras(p);
    forn(i, p)
        in >> palabras[i];

    vector<vector<vector<int>>> dp( d, vector<vector<int>>(d, vector<int>(24, -1) ) );

    forn(z, p)
    {
        int puntajeMax = 0;
        forn(k, d) forn(l, d) forn(n, 24) dp[k][l][n] = -1;
        
        forn(i, d)
        {
            forn(j, d)
            {
                if(grafo[i][j].first == palabras[z][0])
                {
                    ii aux = {i,j};
                    puntajeMax = max(puntajeMax, dfs(grafo, dp, aux, palabras[z], 0));
                }
            }
        }
        out << puntajeMax << endl;
    }

    return 0;
}