/*
    UVA 1242 - Necklace
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
#include "dinics.h"
using namespace dinics;
#define INF 99999999
#define ii pair<int,int>


int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int N, M, S, T;
    for(int t = 1; true; t++){
        cin >> N >> M;
        if(N == 0 && M == 0)
            return 0;
        
        flowgraph<> H(N+2);
        for(int i = 0; i < M; i++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            H.add_edge(x, y, 1);
            H.add_edge(y, x, 1);
        }
        cin >> S >> T;
        S--; T--;
        H.add_edge(N, S, 2);
        H.add_edge(T, N+1, 2);
        
        cout << "Case " << t << ": ";
        if(H.maxflow(N, N+1) == 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}