/*
    UVA 10707 - 2D-Nim
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define INF 99999999
#define ii pair<int,int>
using Graph = vector<vector<int>>;

struct BoundingBox {
    int w, h;
};

BoundingBox getBoundingBox(vector<ii>& v){
    auto minX = min_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.first < v2.first; })->first;
    auto minY = min_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.second < v2.second; })->second;
    auto maxX = max_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.first < v2.first; })->first;
    auto maxY = max_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.second < v2.second; })->second;
    
    return {maxX - minX, maxY - minY};
}

void rotate(vector<ii> &v){
    auto bb = getBoundingBox(v);
    for(int i = 0; i < v.size(); i++){
        v[i] = {bb.h - v[i].second, v[i].first};
    }
}

void mirrorHorizontally(vector<ii> &v){
    auto bb = getBoundingBox(v);
    auto maxX = max_element(v.begin(), v.end())->first;
    for(int i = 0; i < v.size(); i++){
        v[i].first = bb.w - v[i].first;
    }
}

void moveToOrigin(vector<ii>& v){
    auto minX = min_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.first < v2.first; })->first;
    auto minY = min_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.second < v2.second; })->second;
    auto maxX = max_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.first < v2.first; })->first;
    auto maxY = max_element(v.begin(), v.end(), [](ii v1, ii v2) { return v1.second < v2.second; })->second;
    
    for(auto &e : v)
        e = {e.first - minX, e.second - minY};
}

vector<ii> getCanonic(vector<ii> v){
    moveToOrigin(v);
    sort(v.begin(), v.end());
    vector<ii> canonicV = v;
    
    for(int i = 0; i < 3; i++){
        rotate(v);
        sort(v.begin(), v.end());
        canonicV = min(canonicV, v);
    }
    mirrorHorizontally(v);
    sort(v.begin(), v.end());
    canonicV = min(canonicV, v);
    for(int i = 0; i < 3; i++){
        rotate(v);
        sort(v.begin(), v.end());
        canonicV = min(canonicV, v);
    }
    return canonicV;
}

bool solve(int w, int h, vector<vector<ii>> &components1,  vector<vector<ii>> &components2){
    if(components1.size() != components2.size())
        return false;

    multiset<vector<ii>> cant1;
    multiset<vector<ii>> cant2;
    for(auto v : components1)
        cant1.insert(getCanonic(v));
    for(auto v : components2)
        cant2.insert(getCanonic(v));
    
    for(auto v : cant1)
        if(cant1.count(v) != cant2.count(v))
            return false;
    for(auto v : cant2)
        if(cant1.count(v) != cant2.count(v))
            return false;

    return true;
}

bool inRange(int n){
    return n >= 0 && n <= 100;
}

void dfs(int x, int y, const vector<vector<bool>>& piecesMap, vector<vector<bool>>& visited, vector<ii>& component){
    vector<ii> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    for(int i = 0; i < 4; i++){
        int newX = x+directions[i].first;
        int newY = y+directions[i].second;
        if(inRange(newX) && inRange(newY) && piecesMap[newX][newY] && !visited[newX][newY]){
            component.push_back(make_pair(newX,newY));
            visited[newX][newY] = true;
            dfs(newX, newY, piecesMap, visited, component);
        }
    }
}

vector<vector<ii>> findComponents(vector<ii> &pieces){
    vector<vector<bool>> piecesMap(101, vector<bool>(101, false));
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    for(int i = 0; i < pieces.size(); i++)
        piecesMap[pieces[i].first][pieces[i].second] = true;

    vector<vector<ii>> components;
    for(int i = 0; i < piecesMap.size(); i++){
        for(int j = 0; j < piecesMap[i].size(); j++){
            if(piecesMap[i][j] && !visited[i][j]){
                vector<ii> component;
                component.push_back({i,j});
                visited[i][j] = true;
                dfs(i, j, piecesMap, visited, component);
                components.push_back(component);
            }
        }
    }
    return components;
}

int main(){
    #ifdef TEST
    freopen("sample7.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(; t > 0; t--){
        int w, h, n;
        cin >> w >> h >> n;

        vector<ii> pieces1(n), pieces2(n);
        for(int i = 0; i < n; i++)
            cin >> pieces1[i].first >> pieces1[i].second;
        for(int i = 0; i < n; i++)
            cin >> pieces2[i].first >> pieces2[i].second;

        auto components1 = findComponents(pieces1);
        auto components2 = findComponents(pieces2);

        cout << (solve(w, h, components1, components2) ? "YES" : "NO") << endl;
    }
    return 0;
}