#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)


void cuantaAgua(int nodo, vector<vector<ii>> &arbol, vector<int> &c, int &aguaUsada, vector<int> &queries)
{
    queries[nodo] = aguaUsada+1;
    sort(arbol[nodo].rbegin(), arbol[nodo].rend());
    if(!arbol[nodo].empty())
    {    
        int dif = c[nodo]-arbol[nodo][0].first;
        forn(i, arbol[nodo].size())
        {
            if(i > 0) dif = arbol[nodo][i-1].first - arbol[nodo][i].first;
            aguaUsada += dif;
            cuantaAgua(arbol[nodo][i].second, arbol, c, aguaUsada, queries);
        }
        aguaUsada += arbol[nodo][arbol[nodo].size()-1].first;
    }
    else
    {
        aguaUsada += c[nodo];
    }
}

int main()
{
    int T;
    cin >> T;
    vector<vector<ii>> arbol(T, vector<ii>());
    vector<int> c(T);

    forn(i, T) 
        cin >> c[i];

    forn(i, T-1)
    {
        int desde, dist, hasta;
        cin >> desde >> dist >> hasta;
        arbol[desde-1].push_back( make_pair(dist, hasta-1) );
    }

    vector<int> queries(T);
    int z = 0;
    cuantaAgua(0, arbol, c, z, queries);

    /*forn(i, T)
    {
        cout << queries[i] << " ";
    }cout << endl;
    */
    sort(queries.begin(), queries.end());

    int Q;
    cin >> Q;
    forn(i, Q)
    {
        int K;
        cin >> K;

        //Busqueda Binaria
        int lo = 0, hi = T;
        while(hi-lo > 1)
        {
            int medio = (lo+hi)/2;
            if( queries[medio] <= K )
                lo = medio;
            else
                hi = medio;
        }
        cout << lo+1 << " ";
    }
    return 0;
}
