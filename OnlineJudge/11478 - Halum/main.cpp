/*
    UVA 11478 - Halum
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
#define INF 99999999
#define ii pair<int,int>
using Edge = pair<uint, int>;   // vecino, peso
using Graph = vector<vector<Edge>>;

inline uint& vertex(Edge& e) {return e.first;}
inline int weight(Edge& e) {return e.second;}

bool bellmanFord(const Graph &G){
    // Bellman-Ford para chequear si hay ciclos negativos
    int n = G.size();
    vector<uint> changed;  // vertices of shortest path that changed in the last iteration
    changed.push_back(G.size()-1);
    vector<int> dist(G.size(), numeric_limits<int>::max());  // minimum distance up to a given iteration
    dist[G.size()-1] = 0;
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

bool srdHasSolution(const Graph &G, int minWeight){
    Graph GfromSrd(G.size());
    for(int i = 0; i < G.size(); i++){
        for(auto v : G[i]){
            GfromSrd[i].push_back(make_pair(vertex(v), weight(v) - minWeight));
        }
    }
    vector<Edge> aux(G.size());
    for(int i = 0; i < G.size(); i++)
        aux[i] = make_pair(i, 0);
    GfromSrd.push_back(aux);
    return not bellmanFord(GfromSrd);
}

int halum(const Graph &G){
    int maxWeight = 10;
    for(int i = 0; i < G.size(); i++)
        for(auto v : G[i])
            maxWeight = max(maxWeight, weight(v));
    
    int high = maxWeight;
    int low = 0;
    while(high-low > 1){
        int mid = (high+low)/2;
        if(srdHasSolution(G, mid))
            low = mid;
        else 
            high = mid;
    }

    if(low == maxWeight-1)
        return numeric_limits<int>::max();
    else
        return low;
}

int main(){
    #ifdef TEST
    freopen("sample5.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int V, E;
    while(cin >> V >> E){
        Graph G(V);
        for(int i = 0; i < E; i++){
            int u, v, d;
            cin >> u >> v >> d;
            u--; v--;
            G[u].push_back(make_pair(v, d));
        }
        
        auto res = halum(G);
        if(res <= 0)
            cout << "No Solution" << endl;
        else if(res == numeric_limits<int>::max())
            cout << "Infinite" << endl;
        else 
            cout << res << endl;
    }
    return 0;
}