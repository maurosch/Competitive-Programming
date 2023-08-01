/*
    UVA 10987 - Antifloyd
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 99999999
#define ii pair<int,int>
#define matrix vector<vector<int>>

bool possible(const vector<vector<int>>& distance, vector<pair<int,int>>& cables){
    int n = distance.size();
    vector<vector<bool>> cablesMatrix(n, vector<bool>(n,true));
    
    //floyd warshall
    for(auto z = 0; z < n; ++z){
        for(auto v = 0; v < n; ++v) {
            for(auto w = 0; w < n; ++w){
                if(distance[v][z] + distance[z][w] < distance[v][w])
                    return false;
                if(z != v && z != w && distance[v][z] + distance[z][w] == distance[v][w])
                    cablesMatrix[v][w] = false;        
            }
        }
    }

    for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(cablesMatrix[i][j])
                    cables.push_back(make_pair(j, i));

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
        int n;
        cin >> n;

        vector<vector<int>> distances(n, vector<int>(n, 0));
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                cin >> distances[i][j];
                distances[j][i] = distances[i][j];
            }
        }

        cout << "Case #" << tn+1 << ":" << endl;
        
        vector<pair<int,int>> cables;
        if(!possible(distances, cables)){
            cout << "Need better measurements." << endl;
        } else {
            cout << cables.size() << endl;
            sort(cables.begin(), cables.end());
            for(int i = 0; i < cables.size(); i++){
                cout << cables[i].first+1 << " " << cables[i].second+1 << " " << distances[cables[i].first][cables[i].second] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}