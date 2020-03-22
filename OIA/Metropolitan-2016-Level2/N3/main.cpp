#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int recursiva(vector<vector<int>> &grafo, vector<int> &dist, int nodo, vector<int> &hijos)
{
    if(dist[nodo] != -1) 
        return dist[nodo];

    if(grafo[nodo].size() == 0)
    {
        dist[nodo] = 0;
        return dist[nodo];
    }

    int maxDist = -1;
    
    for(int i = 0; i < grafo[nodo].size(); i++)
    {
        int aux = recursiva(grafo, dist, grafo[nodo][i], hijos);
        if(aux > maxDist)
        {
            maxDist = aux;
            hijos[nodo] = grafo[nodo][i];
        }
    }
    dist[nodo] = maxDist+1;
    return dist[nodo];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>grafo(n);

    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        forn(j, m)
        {
            int dest;
            cin >> dest;
            grafo[i].push_back(dest-1);
        }
    }

    vector<int> distancias(n, -1);
    vector<int> hijos(n, -1);
    for(int i = 0; i < n; i++)
    {
        recursiva(grafo, distancias, i, hijos);
    }

    ///Encontramos el nodo que tiene mayor distancia
    int maximaDist = -1;
    int indice = -1;
    for(int i = 0; i < n; i++)
    {
        if(distancias[i] > maximaDist)
        {
            indice = i;
            maximaDist = distancias[i];
        }
    }

    ///Emcontramos el máximo camino 
    cout << maximaDist+1 << endl;
    while(indice != -1)
    {
        cout << indice+1 << " ";
        indice = hijos[indice];
    }

    return 0;
}
