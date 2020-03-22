#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
const int inf = 999999999;

int djs(vector<vector<int>> &grafo)
{
    priority_queue<pair<int,int>> q;
    vector<int>dist(grafo.size(), inf);
    vector<bool>visitado(grafo.size(),false);
    dist[0] = 0;

    q.push(make_pair(0,0));
    while(!q.empty())
    {
        auto nodo = q.top().second;
        q.pop();
        if(visitado[nodo]) 
            continue;
        visitado[nodo] = true;
        forn(i, grafo.size())
        {
            if(grafo[nodo][i] != -1 and dist[i] > dist[nodo]+grafo[nodo][i])
            {
                dist[i] = dist[nodo]+grafo[nodo][i];
                q.push(make_pair(-dist[i],i));
            }
        }
    }
    return dist.back();
}

int main()
{
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>grafo(n, vector<int>(n,-1));
    forn(i,m)
    { 
        int a,b,c;
        cin >> a >> b >> c;
        grafo[a-1][b-1] = c;
        grafo[b-1][a-1] = c;
    }

    int si = djs(grafo);
    int s = si;
    forn(i, n)
    {
        forn(j, n)
        {
            if(grafo[i][j] != -1)
            {
                grafo[i][j] *= 2;
                s = max(s, djs(grafo));
                grafo[i][j] /= 2;
            }
        }
    }
    
    cout << s-si << endl;
    return 0;
}