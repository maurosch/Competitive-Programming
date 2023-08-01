/*
    UVA 11240 - Antimonotonicity
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 99999999

int longestSubsequenceMaryOrFred(const vector<int>& numbers){
    int changes = 0;
    bool isGoingUp = true;
    for(int i = 0; i < numbers.size()-1; i++){
        if(isGoingUp && numbers[i] > numbers[i+1]){
            changes++;
            isGoingUp = false;
        } else {
            if(!isGoingUp && numbers[i] < numbers[i+1]){
                changes++;
                isGoingUp = true;
            }
        }
    }
    return changes + 1;
}

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(; t > 0; t--){
        int n;
        cin >> n;

        vector<int> numbers(n);
        for(int i = 0; i < n; i++)
            cin >> numbers[i];

        if(n == 1)
            cout << 1 << endl;
        else
            cout << longestSubsequenceMaryOrFred(numbers) << endl;
    }
    return 0;
}