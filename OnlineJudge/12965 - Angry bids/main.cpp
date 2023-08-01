/*
    UVA 12965 - Angry bids
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <unordered_map>
using namespace std;

pair<int,int> solve(vector<int>& producers, vector<int>& consumers){
    int bidPrice = 0, angryAmount = producers.size();
    int lowestAngryAmount = angryAmount;

    sort(producers.begin(), producers.end());
    sort(consumers.begin(), consumers.end());

    int pointerConsumer = 0, pointerProducer = 0;
    for(int i = 0; i < producers.size(); i++){
        angryAmount--;
        int bidPriceActual = producers[i];
        while(pointerConsumer < consumers.size() && consumers[pointerConsumer] < bidPriceActual){
            angryAmount++;
            pointerConsumer++;
        }
        if(angryAmount < lowestAngryAmount){
            lowestAngryAmount = angryAmount;
            bidPrice = bidPriceActual;
        }
    }
    return {bidPrice, lowestAngryAmount};
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(; t > 0; t--){
        int p, c;
        cin >> p >> c;

        vector<int> producers(p);
        vector<int> consumers(c);

        for(int i = 0; i < p; i++)
            cin >> producers[i];        
        for(int i = 0; i < c; i++)
            cin >> consumers[i];

        auto res = solve(producers, consumers);

        cout << res.first << " " << res.second << endl;

   }
    return 0;
}