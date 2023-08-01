/*
    UVA 10048 - Audiophobia
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
using Edge = tuple<uint, uint, uint>;  //capacidad, vertice, vertice
constexpr uint CAPACITY = 0;
constexpr uint V = 1;
constexpr uint W = 2;

struct UF {
    vector<uint> p, s;
    
    UF(uint n) : p(n+1), s(n+1, 1) {
        for(auto i = 0u; i <= n; ++i) p[i] = i;
    }
    
    void unite(uint v, uint w) {
        v = find(v), w = find(w);
        if(v == w) return;
        if(s[v] < s[w]) swap(v, w);
        p[w] = v;
        s[v] += s[w]; 
    }
    
    uint find(uint v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }
        
};

int solve(uint N, vector<Edge> E, uint s, uint t){
    UF uf(N);
    uint edge;
    for(edge = 0u; edge < E.size() and uf.find(s) != uf.find(t); ++edge)
        uf.unite(get<V>(E[edge]), get<W>(E[edge]));

    if(edge == E.size() and uf.find(s) != uf.find(t))
        return 1;
    
    auto capacity = get<CAPACITY>(E[edge-1]);
    return capacity;
}


int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int C, S, Q;
    cin >> C >> S >> Q;
    for(int testNumber = 1; true; testNumber++){
        cout << "Case #" << testNumber << endl;

        vector<Edge> E(S);
        for(auto& e : E){
            cin >> get<V>(e) >> get<W>(e) >> get<CAPACITY>(e);
            get<CAPACITY>(e) *= -1;
        }

        sort(E.begin(), E.end(), greater<Edge>());
        
        for(int i = 0; i < Q; i++){
            int c1, c2;
            cin >> c1 >> c2;
            int sol = solve(C, E, c1, c2)*(-1);
            if(sol == -1)
                cout << "no path" << endl;
            else
                cout << sol << endl;
        }

        cin >> C >> S >> Q;
        if(C == 0 and S == 0 and Q == 0)
            return 0;
        cout << endl;
    }
    return 0;
}