#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
typedef vector<vector<int>> matriz;
int cant;

bool check(matriz &subGrafo, matriz &grafo, vector<int> &permutaciones)
{

    forn(i,subGrafo.size())
    {
        forn(j,subGrafo[i].size())
        {
            if(subGrafo[i][j] == 1)
            {
                if( grafo[permutaciones[i]][permutaciones[j]] != 1 )
                    return false;
            }
        }
    }
    cant++;
    return true;
}

void search(vector<int> &permutaciones, vector<vector<int>> &subGrafo, vector<vector<int>> &grafo, vector<bool>&usadas)
{
    if(permutaciones.size() == subGrafo.size())
    {
        forn(i,permutaciones.size()) cout << permutaciones[i] << " ";
        if(check(subGrafo, grafo, permutaciones)) cout << " SI";
        cout << endl;
    }
    else
    {
        forn(i,grafo.size())
        {
            if(usadas[i]) continue;
            usadas[i] = true;
            permutaciones.push_back(i);
            search(permutaciones, subGrafo, grafo, usadas);
            permutaciones.pop_back();
            usadas[i] = false;
        }
    }
}


int main()
{
    ifstream in("subredes11.in");
    int N;
    in >> N;
    vector<vector<int>>subGrafo(N, vector<int>(N));
    forn(i,N)
    {
        string z;
        in >> z;
        forn(j,N)
        {   
            subGrafo[i][j] = z[j] - '0';
        }
    }

    /*forn(i,subGrafo.size())
    {
        forn(j,subGrafo.size())
            cout << subGrafo[i][j] << " ";

        cout << endl;
    }*/

    int cantSr;
    in >> cantSr;

    vector<pair<int,int>> datos(cantSr);
    forn(i,cantSr)
        in >> datos[i].first >> datos[i].second;

    forn(i,cantSr)
    {
        vector<vector<int>>grafo(datos[i].first, vector<int>(datos[i].first));
        forn(j,datos[i].second)
        {
            int x, y;
            in >> x >> y;
            grafo[x-1][y-1] = 1;
            grafo[y-1][x-1] = 1;
        }
        vector<int>p;//(1,0);
        vector<bool>u(datos[i].first, false);
        //u[0] = true;

        /*forn(z,grafo.size())
        {
            forn(j,grafo.size())
                cout << grafo[z][j] << " ";

            cout << endl;
        }*/


        search(p, subGrafo, grafo, u);
        cout << cant << endl;
        cant = 0;
    }
    return 0;
}
