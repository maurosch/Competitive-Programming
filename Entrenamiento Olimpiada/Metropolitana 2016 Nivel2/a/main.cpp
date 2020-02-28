#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int desde = 0;
    int n = 10;

    vector<vector<int>> grafo();
    stack<int> pila;
    vector<bool> visitados(n, false);

    pila.push(desde);
    while(!pila.empty())
    {
        int nodo = pila.top();
        pila.pop();
        for(int i = 0; i < grafo[nodo].size(); i++)
        {
            int nodoAdj = grafo[nodo][i];
            if(!visitados[nodoAdj])
            {
                visitados[nodoAdj] = true;
                pila.push(nodoAdj);
            }
        }
    }

    return 0;    
}