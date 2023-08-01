/*
    UVA 563 - Crimewave
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
typedef pair<int,int> ii;

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int p;
    cin >> p;
    for(; p > 0; p--){
        int width, height, amountBanks;
        cin >> width >> height >> amountBanks;

        auto fromCoord = [&width, &height](int x, int y, int level){
            return y*width + x + level*width*height;
        };

        int N = (width*height)*2;
        flowgraph<> H(N+2);
        for(int i = 0; i < amountBanks; i++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            H.add_edge(N, fromCoord(x, y, 0), 1);
        }

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                H.add_edge(fromCoord(j, i, 0), fromCoord(j, i, 1), 1);
                vector<ii> directions = {{0,-1},{0,+1},{-1,0},{+1,0}};
                for(auto &d : directions){
                    auto y = i+d.first;
                    auto x = j+d.second;
                    if(x < width && x >= 0 && y < height && y >= 0){
                        H.add_edge(fromCoord(j, i, 1), fromCoord(x, y, 0), 1);
                    }
                }
            }
        }

        for(int i = 0; i < width; i++){
            H.add_edge(fromCoord(i, 0, 1), N+1, 1);
            H.add_edge(fromCoord(i, height-1, 1), N+1, 1);
        }

        for(int i = 1; i < height-1; i++){
            H.add_edge(fromCoord(0, i, 1), N+1, 1);
            H.add_edge(fromCoord(width-1, i, 1), N+1, 1);
        }
        
        if(H.maxflow(N, N+1) == amountBanks)
           cout << "possible" << endl;
        else
           cout << "not possible" << endl;
    }
    return 0;
}