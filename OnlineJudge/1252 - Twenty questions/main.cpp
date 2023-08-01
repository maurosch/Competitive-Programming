/*
    UVA 1252 - Twenty Questions
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

int backtracking(const vector<string>& objects, bitset<128> remainingObjects, bitset<12> questionsAsked, bitset<12> answers, unordered_map<bitset<12>, unordered_map<bitset<12>, int>> &dp){    
    if(remainingObjects.count() <= 1)
        return 0;
    
    if(dp.count(questionsAsked) > 0 && dp[questionsAsked].count(answers) > 0)
        return dp[questionsAsked][answers];

    dp[questionsAsked][answers] = 12;
    for(int i = 0; i < objects[0].size(); i++){
        if(!questionsAsked[i]){
            questionsAsked.set(i);

            //Caso devolvio False (no tenia la feature)
            bitset<128> remainingObjectsFalse;
            for(int j = 0; j < objects.size(); j++){
                if(remainingObjects[j] && objects[j][i] == '0')
                    remainingObjectsFalse.set(j);
            }
            int minQuestionsFalse = 1+backtracking(objects, remainingObjectsFalse, questionsAsked, answers, dp);

            //Caso devolvio True (tenia la feature)
            answers.set(i);
            bitset<128> remainingObjectsTrue;
            for(int j = 0; j < objects.size(); j++){
                if(remainingObjects[j] && objects[j][i] == '1')
                    remainingObjectsTrue.set(j);
            }
            int minQuestionsTrue = 1+backtracking(objects, remainingObjectsTrue, questionsAsked, answers, dp);

            answers.reset(i);
            questionsAsked.reset(i);
            dp[questionsAsked][answers] = min(dp[questionsAsked][answers], max(minQuestionsFalse, minQuestionsTrue));
        }
    }

    return dp[questionsAsked][answers];
}


int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    while(true){
        int n, m;
        cin >> m >> n;

        if(n == 0 && m == 0)
            return 0;

        vector<string> objects(n);
        for(int i = 0; i < n; i++)
            cin >> objects[i];

        bitset<128> remainingObjects;
        for(int i = 0; i < objects.size(); i++)
            remainingObjects.set(i);;

        bitset<12> questionsAsked;
        bitset<12> answers;

        unordered_map<bitset<12>, unordered_map<bitset<12>, int>> dp;
        cout << backtracking(objects, remainingObjects, questionsAsked, answers, dp) << endl;
   }
    return 0;
}