/*
    UVA 1108 - Mining Your Own Business
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
#define INF 99999999

using Graph = vector<vector<int>>;
using Edge = pair<int, int>;
using BCC = vector<Edge>;

pair<int64_t,int64_t> escapeShafts(Graph &G){
    // Paso 1: encontrar la particion en componentes biconexas de G
    vector<int> level(G.size(), -1);    //nivel dfs
    vector<int> low(G.size(), G.size()+1);    //low dfs
    vector<Edge> open_bccs;    //stack con los vertices de la bccs no cerradas
    set<int> puntosArticulacion;
    
    function<void(int, int, vector<BCC>*)> find_bccs = [&puntosArticulacion, &G,&level,&low,&open_bccs,&find_bccs](int v, int l, vector<BCC>* res) {
        level[v] = low[v] = l;
        for(auto w : G[v]) {
            if(level[w] == -1) { //tree edge
                open_bccs.push_back({v,w});
                find_bccs(w, l+1, res);
                low[v] = min(low[v], low[w]);
                // Punto de articulacion? (o raiz y su bcc)
                if(low[w] >= l) {
                    puntosArticulacion.insert(v);
                    
                    res->push_back({});
                    do {
                        res->back().push_back(open_bccs.back());
                        open_bccs.pop_back();
                    } while(res->back().back() != Edge(v,w));
                }
            } else if(level[w] < level[v]-1) {// back edge
                open_bccs.push_back({v,w});
                low[v] = min(low[v], level[w]);
            }
        }
    };

    vector<BCC> bccs;
    for(auto v = 0u; v < G.size(); ++v)
        if(level[v] == -1)
            find_bccs(v, 0, &bccs);

    if(bccs.size() == 1)
        return {2, (int64_t) G.size() * (G.size()-1) / 2}; 

    int cantHijos = 0;
    for(auto v = 0u; v < G.size(); ++v)
        if(level[v] == 1)
            cantHijos++;

    if(cantHijos > 1){
        puntosArticulacion.insert(0);
    } else {
        puntosArticulacion.erase(0);
    }

    vector<set<int>> bccsByNodes(bccs.size());
    for(int i = 0; i < bccs.size(); i++)
        for(auto edge : bccs[i]){
            bccsByNodes[i].insert(edge.first);
            bccsByNodes[i].insert(edge.second);
        }

    int64_t amountEscapeShafts = 0, possibilities = 1;

    for(int i = 0; i < bccsByNodes.size(); i++){
        int cantPuntosArticulacion = 0;
        for(auto node : bccsByNodes[i])
            cantPuntosArticulacion += puntosArticulacion.count(node);

        if(cantPuntosArticulacion < 2){
            amountEscapeShafts += 1;
            possibilities *= bccsByNodes[i].size()-1;
        }
    }

    return {amountEscapeShafts, possibilities};
}

int main(){
    #ifdef TEST
    freopen("sample7.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t = 0;
    for(;;t++){
        int n;
        cin >> n;
        if(n == 0) return 0;

        vector<Edge> edges(n);
        int maxN = 0;
        for(int i = 0; i < n; i++){
            cin >> edges[i].first >> edges[i].second;
            maxN = max(maxN, max(edges[i].first, edges[i].second));
        }

        Graph G(maxN);
        for(int i = 0; i < n; i++){
            G[edges[i].first-1].push_back(edges[i].second-1);
            G[edges[i].second-1].push_back(edges[i].first-1);
        }

        
        auto sol = escapeShafts(G);
        if(sol.first == 0)
            cout << "Case " << t+1 << ": 1 1" << endl;
        else
            cout << "Case " << t+1 << ": " << sol.first << " " << sol.second << endl;
    }
    return 0;
}