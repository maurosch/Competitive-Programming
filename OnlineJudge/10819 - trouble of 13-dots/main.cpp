/*
    UVA 10819 - trouble of 13dots
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXIMO 99999999
#define UNDEFINED -1

int knapsack(int index, int spent, const int initialMoney, bool canUseExtra, vector<int> &prices, vector<int> &benefits, vector<vector<int>> &pd){

    if(initialMoney+200 < spent)
        return -MAXIMO;
    
    if(index < 0 && spent <= 2000 && initialMoney < spent)
        return -MAXIMO;

    if(index < 0)
        return 0;

    if(pd[index][spent] == UNDEFINED)
        pd[index][spent] = max(
            knapsack(index-1, spent, initialMoney, canUseExtra, prices, benefits, pd), 
            knapsack(index-1, spent+prices[index], initialMoney, canUseExtra, prices, benefits, pd)+benefits[index]
        );
    
    return pd[index][spent];
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int m;
    while(cin >> m){
        int n;
        cin >> n;

        vector<int> prices(n);
        vector<int> benefits(n);
        for(int i = 0; i < n; i++)
            cin >> prices[i] >> benefits[i];

        if(m == 0 || n == 0){
            cout << 0 << endl;
            continue;
        }
        
        vector<vector<int>> pd(n, vector<int>(m+201, UNDEFINED));
        knapsack(n-1, 0, m, true, prices, benefits, pd);
        cout << pd[n-1][0] << endl;
   }
    return 0;
}