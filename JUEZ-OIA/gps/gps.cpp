#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
typedef pair<int,int> ii;
typedef pair<long long,int> li;

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
    /*if(M == 0)
    {
        vector<long long> r;
        r.push_back(0);
        return r;
    }*/

    vector<vector<ii>> grafo(N);
    forn(i, M)
        grafo[origen[i]-1].push_back({destino[i]-1, tiempo[i]});

    vector<vector<long long>> distancias(N);
    priority_queue<li> cola;

    if(comienzo != fin)
        distancias[comienzo-1].push_back(0);
    cola.push({0, comienzo-1});

    bool terminar = false;
    while(!terminar and !cola.empty())
    {
        int nodoActual = cola.top().second;
        long long distLlegue = -cola.top().first;
        cola.pop();

        distancias[nodoActual].push_back(distLlegue);
        if(int(distancias[fin-1].size()) == K)
        {
            break;
        }

        if(int(distancias[nodoActual].size()) <= K+1)
        {
            for(auto z : grafo[nodoActual])
            {
                int nodoAdj = z.first, peso = z.second;
                long long dist = distLlegue+peso;
                cola.push({-dist, nodoAdj});
            }
        }
    }

    //if(comienzo == fin) 
      // distancias[comienzo-1].erase(distancias[comienzo-1].begin());

    return distancias[fin-1];
}
