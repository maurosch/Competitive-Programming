/*
    UVA 10092 - The Problem with the Problem Setter
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
#include "dinics.h"
using namespace dinics;

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int amountCategories, amountProblems;
    while(true) {
        cin >> amountCategories >> amountProblems;
        if(amountCategories == 0 && amountProblems == 0)
            return 0;

        
        int N = amountProblems+amountCategories;
        flowgraph<> H(N+2);
        int S = N;
        int T = N+1;
        int testAmountProblems = 0;

        for(int i = 0; i < amountCategories; i++){
            int amountProblemsThisCategory;
            cin >> amountProblemsThisCategory;
            testAmountProblems += amountProblemsThisCategory;
            H.add_edge(amountProblems+i, T, amountProblemsThisCategory);
        }

        for(int i = 0; i < amountProblems; i++)
            H.add_edge(S, i, 1);

        for(int i = 0; i < amountProblems; i++){
            int amount;
            cin >> amount;
            for(; amount > 0; amount--){
                int category;
                cin >> category;
                category--;
                H.add_edge(i, amountProblems+category, 1);
            }
        }
        if(H.maxflow(S, T) == testAmountProblems){
            cout << "1" << endl;
            auto edges = H.get_saturated_edges();
            vector<set<int>> problemsPerCategory(amountCategories);
            for(auto v : edges){
                if(v.to >= amountProblems && v.to < amountProblems+amountCategories){
                    problemsPerCategory[v.to-amountProblems].insert(v.from);
                }
            }
            for(int i = 0; i < problemsPerCategory.size(); i++){
                for(auto z : problemsPerCategory[i]){
                    cout << z+1 << " ";
                }
                cout << endl;
            }
        }
        else 
            cout << "0" << endl;

    }
    return 0;
}