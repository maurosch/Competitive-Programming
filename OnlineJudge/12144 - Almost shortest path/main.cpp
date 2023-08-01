/*
    UVA 12144 - Almost Shortest Path
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
#define INF 99999999
#define ii pair<int,int>
using Digraph = vector<vector<ii>>;

vector<int> dijkstra(const Digraph& D, int from) {
    vector<int> dist(D.size(), numeric_limits<int>::max());
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, from});
    while(not q.empty()) {
        auto u = q.top();
        q.pop();
        if(dist[u.second] < numeric_limits<int>::max()) continue;
        dist[u.second] = u.first;
        for(auto v : D[u.second]) 
            q.push({u.first + v.first, v.second});
    }
    return dist;
}

int solve(const Digraph& D, const int s, const int t){
    auto distancesFromS = dijkstra(D, s);
    
    Digraph inverseD(D.size());
    for(int i = 0; i < D.size(); i++)
        for(int j = 0; j < D[i].size(); j++)
        inverseD[D[i][j].second].push_back(make_pair(D[i][j].first, i));

    auto distancesToT = dijkstra(inverseD, t);

    Digraph filteredD(D.size());
    for(int i = 0; i < D.size(); i++)
        for(int j = 0; j < D[i].size(); j++)
            if(distancesFromS[i] + distancesToT[D[i][j].second] + D[i][j].first != distancesFromS[t])
                filteredD[i].push_back(make_pair(D[i][j].first, D[i][j].second));

    int res = dijkstra(filteredD, s)[t];
    return res == numeric_limits<int>::max() ? -1 : res;
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    while(true){
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        if(n == m && n == 0)
            return 0;

        vector<vector<ii>> G(n);
        for(int i = 0; i < m; i++){
            int x, y, w;
            cin >> x >> y >> w;
            G[x].push_back(make_pair(w, y));
        }
        
        cout << solve(G, s, t) << endl;
    }
    return 0;
}