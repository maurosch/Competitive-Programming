/*
    UVA 10306 - e-coins
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
using namespace std;

#define MAXIMO 999999999
#define UNDEFINED -1

int realValue(int convValue, int techValue){
    return convValue*convValue+techValue*techValue;
}

int solver(const int s, int convValue, int techValue, const vector<pair<int,int>> &ecoins, vector<vector<int>> &pd){
    
    auto emodulus = realValue(convValue,techValue);
    if(emodulus > s*s)
        return MAXIMO;
    else if(emodulus == s*s)
        return 0;

    if(pd[convValue][techValue] == UNDEFINED){
        pd[convValue][techValue] = solver(s, convValue+ecoins[0].first, techValue+ecoins[0].second, ecoins, pd) + 1;
        for(int i = 1; i < ecoins.size(); i++){
            pd[convValue][techValue] = min(pd[convValue][techValue], solver(s, convValue+ecoins[i].first, techValue+ecoins[i].second, ecoins, pd) + 1);
        }        
    }
    
    return pd[convValue][techValue];
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);
    int t;
    cin >> t;
    for(;t > 0; t--){
        int m, s;
        cin >> m >> s;
        vector<pair<int,int>> ecoins((unsigned int)m);
        for(unsigned int i = 0; i < (unsigned int)m; i++)
            cin >> ecoins[i].first >> ecoins[i].second;
        
        vector<vector<int>> pd((unsigned int)s, vector<int>((unsigned int)s, UNDEFINED));

        solver(s, 0, 0, ecoins, pd);

        if(pd[0][0] < MAXIMO)
            cout << pd[0][0] << endl;
        else
            cout << "not possible" << endl;
    }
    return 0;
}