/*
    UVA 1231 - Acorn
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
using namespace std;

#define UNDEFINED -1

int maximoCantBellotas(int, int, const int, const int, const vector<unordered_map<int,int>> &, vector<vector<int>> &, vector<int> &);

int arbolQueMaximiza(int altura, const int f, const int h, const vector<unordered_map<int,int>> &acorns, vector<vector<int>> &dp, vector<int> &dpArbolMaximiza){
    if(dpArbolMaximiza[altura] == UNDEFINED){
        int maximo = 0;
        for(int i = 0; i < acorns.size(); i++){
            int aux = maximoCantBellotas(altura, i, f, h, acorns, dp, dpArbolMaximiza);
            if(aux > maximo){
                maximo = aux;
                dpArbolMaximiza[altura] = i;
            }
        }
    }
    return dpArbolMaximiza[altura];
}

int maximoCantBellotas(int altura, int arbol, const int f, const int h, const vector<unordered_map<int,int>> &acorns, vector<vector<int>> &dp, vector<int> &dpArbolMaximiza){
    if(altura <= 0)
        return 0;
    
    if(dp[arbol][altura] == UNDEFINED){
        auto p = acorns[arbol].find(altura);
        int amountAcornsCurrentPlace = (p == acorns[arbol].end() ? 0 : p->second);
        
        dp[arbol][altura] = maximoCantBellotas(altura-1, arbol, f, h, acorns, dp, dpArbolMaximiza);
        if(altura-f >= 0){
            dp[arbol][altura] = max(
                dp[arbol][altura], 
                maximoCantBellotas(altura-f, arbolQueMaximiza(altura-f, f, h, acorns, dp, dpArbolMaximiza), f, h, acorns, dp, dpArbolMaximiza)
            );
        }
        dp[arbol][altura] += amountAcornsCurrentPlace;
    }
    return dp[arbol][altura];
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int z;
    cin >> z;
    for(; z > 0; z--){
        int t, h, f;
        cin >> t >> h >> f;

        vector<vector<int>> acornsMatrix(t);
        for(int i = 0; i < t; i++){
            int amountAcorns;
            cin >> amountAcorns;
            acornsMatrix[i] = vector<int>(amountAcorns);
            for(int j = 0; j < amountAcorns; j++)
                cin >> acornsMatrix[i][j];
        }

        vector<unordered_map<int,int>> acorns(acornsMatrix.size());
        for(int i = 0; i < acornsMatrix.size(); i++){
            for(int j = 0; j < acornsMatrix[i].size(); j++){
                if(acorns[i].count(acornsMatrix[i][j]) == 0)
                    acorns[i][acornsMatrix[i][j]] = 1;
                else 
                    acorns[i][acornsMatrix[i][j]]++;
            }
        }
        vector<vector<int>> dp(t, vector<int>(h+1, UNDEFINED));
        vector<int> dpArbolMaximiza(h+1, UNDEFINED);
        int sol = 0;
        for(int i = 0; i < acorns.size(); i++){
            sol = max(sol, maximoCantBellotas(h, i, f, h, acorns, dp, dpArbolMaximiza));
        }
        cout << sol << endl;
   }
    return 0;
}