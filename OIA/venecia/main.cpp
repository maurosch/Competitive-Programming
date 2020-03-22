#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

void recursiva(int nodo, vector<vector<pair<int,int>>> &grafo, vector<bool> &visitados, vector<int> &s)
{
    forn(i, grafo[nodo].size())
    {
        int numeroEnlace = grafo[nodo][i].second;
        if(!visitados[numeroEnlace])
        {
            visitados[numeroEnlace] = true;
            s.push_back(grafo[nodo][i].second);
            recursiva(grafo[nodo][i].first, grafo, visitados, s);
            s.push_back(grafo[nodo][i].second);
        }
    }
}


int main()
{
    int N, M, S;
    cin >> N >> M >> S;
    vector<vector<pair<int,int>>> grafo(N);
    forn(i,M)
    {
        int a, b, l;
        cin >> a >> b >> l;
        grafo[a-1].push_back(make_pair(b-1,i));
        grafo[b-1].push_back(make_pair(a-1,i));
    }

    vector<bool>visitados(M, false);
    vector<int> s;

    recursiva(S-1, grafo, visitados, s);

    cout << s.size() << endl;
    forn(i, s.size())
        cout << s[i]+1 << " ";

    return 0;
}