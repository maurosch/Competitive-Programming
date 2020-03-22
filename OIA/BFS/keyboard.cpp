#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define RAYA cout << "==================" << endl;
#define miniRAYA cout << "========" << endl;
#define mp make_pair
#define size(a) (int)(a.size())
using namespace std;
typedef pair<int,int> ii;

struct nodo
{
    int x = -1, y = -1;
    char letra = 'o';
};


int main()
{
    int col, row;

    while(cin >> row >> col)
    {
        vector<vector<char>>mapa(row, vector<char>(col));
        int solucion = 0;
        string palabra;
        queue<ii>cola;

        forn(i, row) forn(j, col) cin >> mapa[i][j];
        cin >> palabra;
        palabra += '*';

        forn(j, row)
        {
            forn(z, col) cout << mapa[j][z] << " ";
            cout << endl;
        }
        cout << palabra << endl;

        //return 0;

        cola.push(mp(0,0));
        forn(i, size(palabra))
        {
            bool visitados[row][col];
            ii padres[row][col];
            forn(j, row) forn(z, col) padres[j][z] = mp(-1,-1);
            forn(j, row) forn(z, col) visitados[j][z] = false;
            visitados[cola.front().first][cola.front().second] = true;

            while(mapa[cola.front().first][cola.front().second] != palabra[i])
            {
                ii nodo = cola.front();
                cola.pop();
                if(nodo.first > 0 and !visitados[nodo.first-1][nodo.second])
                {
                    int primero;
                    for(primero = nodo.first-1; primero > 0 and mapa[nodo.first][nodo.second] == mapa[primero][nodo.second]; primero--);
                    if(mapa[nodo.first][nodo.second] != mapa[primero][nodo.second])
                    {
                        cola.push(mp(primero, nodo.second));
                        padres[primero][nodo.second] = mp(nodo.first, nodo.second);
                        visitados[primero][nodo.second] = true;
                    }
                }

                if(nodo.first < row-1 and !visitados[nodo.first+1][nodo.second])
                {
                    int primero;
                    for(primero = nodo.first+1; primero < row-1 and mapa[nodo.first][nodo.second] == mapa[primero][nodo.second]; primero++);
                    if(mapa[nodo.first][nodo.second] != mapa[primero][nodo.second])
                    {
                        cola.push(mp(primero, nodo.second));
                        padres[primero][nodo.second] = mp(nodo.first, nodo.second);
                        visitados[primero][nodo.second] = true;
                    }
                }

                if(nodo.second > 0 and !visitados[nodo.first][nodo.second-1])
                {

                    int primero;
                    for(primero = nodo.second-1; primero > 0 and mapa[nodo.first][nodo.second] == mapa[nodo.first][primero]; primero--);
                    if(mapa[nodo.first][nodo.second] != mapa[nodo.first][primero])
                    {
                        cola.push(mp(nodo.first, primero));
                        padres[nodo.first][primero] = mp(nodo.first, nodo.second);
                        visitados[nodo.first][primero] = true;
                    }
                }
                if(nodo.second < col-1 and !visitados[nodo.first][nodo.second+1])
                {
                    int primero;
                    for(primero = nodo.second+1; primero < col-1 and mapa[nodo.first][nodo.second] == mapa[nodo.first][primero]; primero++);
                    if(mapa[nodo.first][nodo.second] != mapa[nodo.first][primero])
                    {
                        cola.push(mp(nodo.first, primero));
                        padres[nodo.first][primero] = mp(nodo.first, nodo.second);
                        visitados[nodo.first][primero] = true;
                    }
                }
                //cout << nodo.first << " " << nodo.second << endl;

            }

            int y = cola.front().first, x = cola.front().second;
            cout << "y:" << y << " x:" << x << endl;
            ii auxP = padres[y][x];
            while(auxP != mp(-1,-1))
            {
                cout << "y:" << auxP.first << " x:" << auxP.second << endl;
                solucion++;
                auxP = padres[auxP.first][auxP.second];
            }
            while(!cola.empty()) cola.pop();
            cola.push(mp(y, x));
            solucion++;
            miniRAYA
        }
        cout << solucion << endl;
        RAYA
    }
    return 0;
}
