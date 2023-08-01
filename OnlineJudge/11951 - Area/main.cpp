/*
    UVA 11951 - Area
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
using namespace std;

int sumLine(const vector<vector<int>> &sumMatrix, int row, int colLeft, int colRight){
    if(colLeft <= 0)
        return sumMatrix[row][colRight];
    else
        return sumMatrix[row][colRight] - sumMatrix[row][colLeft-1];
}

pair<int,int> f(const vector<vector<int>> &map, const int k){
    int maxArea = 0, costArea = 999999;

    vector<vector<int>> sumMatrix(map);
    for(int i = 0; i < map.size(); i++)
        for(int j = 1; j < map[0].size(); j++)
            sumMatrix[i][j] = sumMatrix[i][j-1] + map[i][j];

    for(int startCol = 0; startCol < map[0].size(); startCol++){
        for(int endCol = startCol; endCol < map[0].size(); endCol++){
            int startRow = 0;
            int endRow = -1;
            int sum = 0;
            while(startRow < map.size()){
                if(sum <= k && endRow < ((int)map.size())-1){
                    endRow++;
                    sum += sumLine(sumMatrix, endRow, startCol, endCol);
                } else {
                    sum -= sumLine(sumMatrix, startRow, startCol, endCol);
                    startRow++;
                } 

                const int area = (endRow-startRow+1)*(endCol-startCol+1);
                if(sum <= k && (area > maxArea || (area == maxArea && sum < costArea))){
                    maxArea = area;
                    costArea = sum;
                }
            }
        }
    }   

    return {maxArea, costArea};
}


int main(){
    #ifdef TEST
    freopen("sample4.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> map(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> map[i][j];

        if(n == 0 || m == 0){
            cout << "Case #" << z+1 << ": 0 0" << endl;
            continue;
        }

        auto res = f(map, k);
        cout << "Case #" << z+1 << ": " << res.first << " " << res.second << endl;
   }
    return 0;
}