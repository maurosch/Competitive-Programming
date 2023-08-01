/*
    UVA 11790 - murcias skyline
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
using namespace std;

// Se puede cambiar por n*log n pero entraba igual que sea n^2
int longestIncreasingSubsequenceWithWeights(vector<pair<int,int>> &a){
    vector<int> length(a.size(),0);
    for (int k = 0; k < a.size(); k++) {
        length[k] = a[k].second;
        for (int i = 0; i < k; i++) {
            if (a[i].first < a[k].first) {
                length[k] = max(length[k],length[i]+a[k].second);
            }
        }
    }   

    return *max_element(length.begin(), length.end());
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        int n;
        cin >> n;
        vector<pair<int,int>> buildings((unsigned int)n);
        for(unsigned int i = 0; i < (unsigned int)n; i++)
            cin >> buildings[i].first;
        for(unsigned int i = 0; i < (unsigned int)n; i++)
            cin >> buildings[i].second;
        
        int increasing = longestIncreasingSubsequenceWithWeights(buildings);
        reverse(buildings.begin(), buildings.end());
        int decreasing = longestIncreasingSubsequenceWithWeights(buildings);

        if(increasing >= decreasing)
            cout << "Case " << z+1 << ". Increasing (" << increasing << "). Decreasing (" << decreasing << ")." << endl;
        else
            cout << "Case " << z+1 << ". Decreasing (" << decreasing << "). Increasing (" << increasing << ")." << endl;
    }
    return 0;
}