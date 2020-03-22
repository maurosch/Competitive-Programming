#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
typedef pair<int,int> ii;

void recursiva(int nodo, vector<vector<ii>> &arbol, int &llenados, ii &s, int K)
{
    sort(arbol[nodo].rbegin(), arbol[nodo].rend());
    forn(i, arbol[nodo].size())
        recursiva(arbol[nodo][i].second, arbol, llenados, s, K);

    llenados++;
    if(llenados == K)
    {
        s.second = nodo;
        s.first = 1;
        llenados++;
    }
}

int main()
{
    int T, K;
    cin >> T;
    vector<vector<ii>> arbol(T, vector<ii>());
    forn(i, T-1)
    {
        int desde, hasta, dist;
        cin >> desde >> dist >> hasta;

        arbol[desde-1].push_back( make_pair(dist, hasta-1) );
    }
    cin >> K;

    ii aux;
    int z = 0;
    recursiva(0, arbol, z, aux, K);
    cout << aux.second+1 << " " << aux.first << endl;

    return 0;
}
