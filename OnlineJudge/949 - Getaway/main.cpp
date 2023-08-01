/*
    UVA 949 - Getaway
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

bool trafficIsAllowed(const ii from, const ii to, map<ii, vector<ii>> &trafficRestrictions){
    return trafficRestrictions.count(from) == 0 || find(trafficRestrictions[from].begin(),trafficRestrictions[from].end(), to) == trafficRestrictions[from].end();
}

bool inRange(int v, int min, int max){
    return v <= max && v >= min;
}

uint bfs(const int cols, const int rows, 
map<ii, vector<ii>> &trafficRestrictions, 
map<int, ii> &timeRestrictions) {
    uint res = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<pair<uint, uint>> q[10500];
    q[0].push_back({0, 0});
    const vector<ii> directions = {{-1,0},{+1,0},{0,-1},{0,+1}};
    
    while(not visited[rows-1][cols-1]) {
        while(q[res].empty()) {
            res += 1;
        }
        uint rc, cc; tie(rc,cc) = q[res].back();  //r current, c current
        q[res].pop_back();

        if(visited[rc][cc]) continue;
        visited[rc][cc] = true;

        for(auto direction : directions) {
            ii from = make_pair(rc, cc);
            ii to = make_pair(rc+direction.first, cc+direction.second);
            if(inRange(to.first, 0, rows-1) and inRange(to.second, 0, cols-1)
                and not visited[to.first][to.second] 
                and trafficIsAllowed(from, to, trafficRestrictions)){
                    int time;
                    for(time = res+1; timeRestrictions.count(time) > 0 && timeRestrictions[time] == to; time++){}
                    q[time].push_back(to);
            }
        }
    }
    return res;
}

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int nv, nh, r, m;
    while(cin >> nv >> nh >> r){

        map<pair<int,int>, vector<ii>> trafficRestrictions;
        for(int i = 0; i < r; i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            trafficRestrictions.emplace(make_pair(y1,x1), vector<ii>());
            trafficRestrictions[make_pair(y1,x1)].push_back(make_pair(y2,x2));
        }

        cin >> m;

        map<int, pair<int,int>> timeRestrictions;
        for(int i = 0; i < m; i++){
            int t, x, y;
            cin >> t >> x >> y;
            timeRestrictions[t] = make_pair(y,x);
        }
        
        cout << bfs(nv, nh, trafficRestrictions, timeRestrictions) << endl;
    }
    return 0;
}