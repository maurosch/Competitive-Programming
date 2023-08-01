/*
    UVA 11228 - Transportation system
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
#include <math.h>
using namespace std;
#define INF 99999999
#define ii pair<int,int>

constexpr int UNVISITED = numeric_limits<int>::max();
constexpr int VISITED = UNVISITED - 1;

double dist(ii v1, ii v2){
    return sqrt(pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2));
}

tuple<int,int,int> prim(const vector<ii>& positions, const int r){    
    double amountRailroads = 0, roads = 0, railroads = 0;
    //Version cuadratica de prim
    int n = positions.size();
    vector<double> prim(n, UNVISITED);
    prim[0] = 0;
    int ans = 0;
    for(int e = 0; e < n; ++e) {
        auto v = min_element(prim.begin(), prim.end()) - prim.begin();
        ans += prim[v];
        if(prim[v] < r)
            roads += prim[v];
        else {
            amountRailroads++;
            railroads += prim[v];
        }

        prim[v] = VISITED;
        for(int w = 0; w < n; ++w) if(prim[w] != VISITED) {
            prim[w] = min(prim[w], dist(positions[v], positions[w]));
        }
    }
    return make_tuple(amountRailroads, round(roads), round(railroads));
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
        int n, r;
        cin >> n >> r;
        vector<ii> positions(n);
        for(int i = 0; i < n; i++)
            cin >> positions[i].first >> positions[i].second;

        auto res = prim(positions, r);
        cout << "Case #" << tn+1 << ": "<< get<0>(res)+1 << " " << get<1>(res) << " " << get<2>(res) << endl;
    }
    return 0;
}