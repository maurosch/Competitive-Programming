/*
    UVA 12745 - Wishmaster
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <functional>
#include <unordered_map>
using namespace std;
#define INF 99999999
#define ii pair<int,int>
using Graph = vector<vector<int>>;

int flipNegativeAndPositive(int n, int number){
    return number > n ? number - n : number + n;
}

bool wishesCanBeMade(int n, Graph G, Graph BackG){
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
    
    unordered_map<int,set<int>> itemsByComponents;
    for(int i = 0; i < component.size(); i++){
        itemsByComponents.emplace(component[i], set<int>());
        itemsByComponents[component[i]].insert(i);
        if(itemsByComponents[component[i]].count(flipNegativeAndPositive(n,i)) > 0)
            return false;
    }
    return true;
}


int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(int tn = 0; tn < t; tn++){
        int n, m;
        cin >> n >> m;

        Graph G(2*n+1);
        Graph BackG(2*n+1);
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            if(x < 0) x = -x + n;
            if(y < 0) y = -y + n;
            G[x].push_back(flipNegativeAndPositive(n,y));
            G[y].push_back(flipNegativeAndPositive(n,x));

            BackG[flipNegativeAndPositive(n,y)].push_back(x);
            BackG[flipNegativeAndPositive(n,x)].push_back(y);
        }
        cout << "Case " << tn+1 << ": " << (wishesCanBeMade(n, G, BackG) ? "Yes" : "No") << endl;
    }
    return 0;
}