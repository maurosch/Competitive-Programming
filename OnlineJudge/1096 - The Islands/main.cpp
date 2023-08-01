/*
    UVA 1096 - The Islands
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <iomanip>

using namespace std;

constexpr double INF = numeric_limits<double>::infinity();

inline double dist(const vector<pair<int,int>> &points, int i, int j){
    return hypot(points[i].first - points[j].first, points[i].second - points[j].second);
};

double bitonicTsp(const vector<pair<int,int>> &ps, int i, int j, const int forcedPointFirstPath, const int forcedPointSecondPath, vector<vector<double>> &mem, vector<vector<pair<int,int>>> &parents){
    if(i == ps.size()-1)
        return dist(ps, j, ps.size()-1);

    if(j == ps.size()-1)
        return dist(ps, i, ps.size()-1);

    if(mem[i][j] == INF){
        auto nextPosition = max(i, j)+1;
        if(nextPosition == forcedPointFirstPath){
            mem[i][j] = dist(ps, i, nextPosition) + bitonicTsp(ps, nextPosition, j, forcedPointFirstPath, forcedPointSecondPath, mem, parents);
            parents[i][j] = make_pair(nextPosition,j);
        } else if(nextPosition == forcedPointSecondPath){
            mem[i][j] = dist(ps, j, nextPosition) + bitonicTsp(ps, i, nextPosition, forcedPointFirstPath, forcedPointSecondPath, mem, parents);
            parents[i][j] = make_pair(i,nextPosition);
        } else {
            auto firstPath = dist(ps, i, nextPosition) + bitonicTsp(ps, nextPosition, j, forcedPointFirstPath, forcedPointSecondPath, mem, parents);
            auto secondPath = dist(ps, j, nextPosition) + bitonicTsp(ps, i, nextPosition, forcedPointFirstPath, forcedPointSecondPath, mem, parents);

            if(firstPath < secondPath){
                parents[i][j] = make_pair(nextPosition,j);
                mem[i][j] = firstPath;
            } else {
                parents[i][j] = make_pair(i,nextPosition);
                mem[i][j] = secondPath;
            }
        }
    }

    return mem[i][j];
}

pair<double, vector<int>> bitonicModified(const vector<pair<int,int>> &points, int b1, int b2){
    vector<vector<pair<int,int>>> parents1(points.size(), vector<pair<int,int>>(points.size(), make_pair(-1,-1)));
    vector<vector<double>> mem(points.size(), vector<double>(points.size(), INF));
    auto s1 = bitonicTsp(points, 0, 0, b1, b2, mem, parents1);

    vector<vector<pair<int,int>>> parents2(points.size(), vector<pair<int,int>>(points.size(), make_pair(-1,-1)));
    vector<vector<double>> mem2(points.size(), vector<double>(points.size(), INF));
    auto s2 = bitonicTsp(points, 0, 0, b2, b1, mem2, parents2);
    
    vector<vector<pair<int,int>>> parents;
    double sol;

    if(s1 < s2){
        parents = parents1;
        sol = s1;
    } else {
        parents = parents2;
        sol = s2;
    }
    vector<int> path;
    path.push_back(0);
    vector<int> path1;
    vector<int> path2;
    int nextX = 0, nextY = 0;
    while(true){
        if(parents[nextX][nextY].first == -1)
            break;
        if(parents[nextX][nextY].first != nextX){
            path1.push_back(parents[nextX][nextY].first);
            nextX = parents[nextX][nextY].first;
        } else {
            path2.push_back(parents[nextX][nextY].second);
            nextY = parents[nextX][nextY].second;
        }
    }
    if(path1[0] == 1){
        reverse(path2.begin(), path2.end());
        path.insert(path.end(), path1.begin(), path1.end());
        path.insert(path.end(), path2.begin(), path2.end());
    } else {
        reverse(path1.begin(), path1.end());
        path.insert(path.end(), path2.begin(), path2.end());
        path.insert(path.end(), path1.begin(), path1.end());
    }
    return make_pair(sol, path);
}

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    for(int t = 0; true; t++){
        int n, b1, b2;
        cin >> n >> b1 >> b2;

        if(n == 0)
            return 0;

        vector<pair<int,int>> positions(n);

        for(int i = 0; i < n; i++)
            cin >> positions[i].first >> positions[i].second;

        auto res = bitonicModified(positions, b1, b2);

        cout << "Case " << t+1 << ": " << setprecision(2) << fixed << res.first << endl;
        for(int i = 0; i < res.second.size(); i++)
            cout << res.second[i] << " ";
        cout << "0" << endl;
    }
    return 0;
}