/*
    UVA 558 - Wormholes
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <queue>
#include <limits>
using namespace std;
#define ii pair<int,int>
using Digraph = vector<vector<ii>>;

//Algoritmo de Bellman-Ford, version labelling

using Edge = pair<uint, long>;
using Graph = vector<vector<Edge>>;
const long INF = std::numeric_limits<long>::max();

inline uint& vertex(Edge& e) {return e.first;}
inline long& weight(Edge& e) {return e.second;}

bool hasNegativeCycle(const Graph& G) {
    vector<uint> changed;  // vertices of shortest path that changed in the last iteration
    changed.push_back(0);
    vector<long> dist(G.size(), INF);  // minimum distance up to a given iteration
    dist[0] = 0;
    vector<uint> iter(G.size(), 0); // last iteration where a vertex was extended

    for(auto i = 1u; i <= G.size() and not changed.empty(); ++i) {
        vector<uint> extensions;
        for(auto v : changed)
        for(auto e : G[v]) 
        if(dist[v] + weight(e) < dist[vertex(e)])
        {
            if(iter[vertex(e)] != i) extensions.push_back(vertex(e));
            iter[vertex(e)] = i;
            dist[vertex(e)] = dist[v] + weight(e);
        }
        swap(extensions, changed);
    }

    return not changed.empty();
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(; t > 0; t--){
        int n, m;
        cin >> n >> m;
        Graph G(n);
        for(int i = 0; i < m; i++){
            int x, y, w;
            cin >> x >> y >> w;
            G[x].push_back(make_pair(y, w));
        }
        cout << (hasNegativeCycle(G) ? "possible" : "not possible") << endl;
    }
    return 0;
}