/*
    UVA 1263 - Mines
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <numeric>
using namespace std;
#define INF 99999999
#define ii pair<int,int>

struct Mine {
    int x;
    int y;
};
using Graph = vector<vector<int>>;

inline bool inRange(double x, int init, int end){
    return x >= init && x <= end;
}

int solve(vector<Mine> &mines, vector<int> &sizeExplosion){
    Graph G(mines.size());
    Graph BackG(mines.size());

    for(int i = 0; i < mines.size(); i++){
        double radius = ((double)sizeExplosion[i])/2;
        double beginX = (double)(mines[i].x) - radius;
        double beginY = (double)(mines[i].y) - radius;
        double endX = (double)(mines[i].x) + radius;
        double endY = (double)(mines[i].y) + radius;

        for(int j = 0; j < mines.size(); j++){
            if(i != j && inRange(mines[j].x, beginX, endX) && inRange(mines[j].y, beginY, endY)){
                G[i].push_back(j);
                BackG[j].push_back(i);
            }
        }
    }

    vector<int> component(G.size(), -1);  //reachable component of v
    function<void(Graph&,int,int,vector<int>*)> dfs = [&component,&dfs](Graph& G, int v, int c, vector<int>* dfs_order) {
        if(component[v] >= 0) return;
        component[v] = c;
        for(auto w : G[v]) dfs(G, w, c, dfs_order);
        dfs_order->push_back(v);
    };

    //calcula las componentes de G recorriendo order, marcando cada componente
    //en CC, dejando la cantidad de componentes en c y retornando el orden de los finish
    auto components = [&component,&dfs](Graph& G, const vector<int>& order) {
        vector<int> dfs_order;
        component.assign(G.size(), -1);
        for(auto v = order.rbegin(); v != order.rend(); ++v) dfs(G, *v, *v, &dfs_order);
        return dfs_order;
    };

    //componentes fuertemente conexas; quedan guardadas en component
    vector<int> order(G.size());
    iota(order.begin(), order.end(), 0);
    components(BackG, components(G, order));

    map<int,bool> componentHasIncomingEdges;
    for(int i = 0; i < component.size(); i++){
        componentHasIncomingEdges.emplace(component[i], false);
        for(auto v : BackG[i])
            if(component[v] != component[i])
                componentHasIncomingEdges[component[i]] = true;
    }

    int sum = 0;
    for(auto v : componentHasIncomingEdges) if(v.second == false) sum++;
    
    return sum;
}

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(; t > 0; t--){
        int n;
        cin >> n;

        vector<Mine> mines(n);
        vector<int> sizeExplosion(n);
        for(int i = 0; i < n; i++){
            cin >> mines[i].x >> mines[i].y >> sizeExplosion[i];
        }

        cout << solve(mines, sizeExplosion) << endl;
    }
    return 0;
}