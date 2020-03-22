#include <vector>
#include <iostream>
#include <algorithm>

//dp solution
//not working right now

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int func(int prof, int p, int cantPlates, vector<vector<int>> &plates, vector<vector<vector<int>>> &dp)
{
    if(prof < 0) return 0;
    if(p <= 0) return 0;
    if(p-cantPlates < 0) return 0;

    if(dp[prof][cantPlates][p] != -1)
        dp[prof][cantPlates][p];
       
    int sol = 0;
    for(int i = 0; i < plates[prof].size(); i++){
        sol = max(sol, func(prof-1, p-cantPlates, i, plates, dp));
    }

    dp[prof][cantPlates][p] = sol+plates[prof][cantPlates];
    return dp[prof][cantPlates][p];
}

int main(){
    int T;
    cin >> T;
    forn(t,T){
        int n, k, p;
        cin >> n >> k >> p;

        vector<vector<int>> plates(n, vector<int>(k+1, 0));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(p+1,-1)));

        forn(i,n){
            for(int j = 1; j < k+1; j++){
                cin >> plates[i][j];
                if(j != 0) 
                    plates[i][j] += plates[i][j-1];
            }
        }
    
        int sol = 0;
        for(int i = 0; i < plates[n-1].size(); i++){
            sol = max(sol, func(n-1, p, i, plates, dp));
        }
        
        cout << "Case #" << t+1 << ": " << sol << endl;
    }
    return 0;
}


