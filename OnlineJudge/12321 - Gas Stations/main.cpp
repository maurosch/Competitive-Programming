/*
    UVA 12321 - Gas Stations
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int howManyGasStationsToRemove(int l, vector<pair<int,int>>& stations){
    sort(stations.begin(),stations.end());

    int initRange = 0;
    int index = 0;
    int used = 0;
    while(initRange < l && index < stations.size()){
        int maxEndRange = -1;
        for(; stations[index].first <= initRange && index < stations.size(); index++){
            maxEndRange = max(maxEndRange, stations[index].second);
        }
        if(maxEndRange == -1)
            return -1;
        used++;
        initRange = maxEndRange;
    }
    if(initRange < l)
        return -1;
    return stations.size() - used;
}

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    while(true){
        int l, g;
        cin >> l >> g;
        if(l == 0 && g == 0)
            return 0;

        vector<pair<int,int>> stations(g);
        for(int i = 0; i < g; i++){
            int x, r;
            cin >> x >> r;
            stations[i].first = x - r;
            stations[i].second = x + r;
        }

        cout << howManyGasStationsToRemove(l, stations) << endl;
   }
    return 0;
}