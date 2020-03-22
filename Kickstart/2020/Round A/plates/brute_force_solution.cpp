#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int fb(int prof, vector<vector<int>> &plates, int k, int s)
{
    if(k < 0)
        return 0;
    if(prof == plates.size()) 
        return s;

    int sol = fb(prof+1, plates, k, s);
    for(int i = 0; i < plates[prof].size(); i++){
        sol = max(sol, fb(prof+1, plates, k-i-1, s+plates[prof][i]));
    }
    return sol;
}

int main(){
    int T;
    cin >> T;
    forn(t,T){
        int n, k, p, s = 0;
        cin >> n >> k >> p;
        vector<vector<int>> plates(n, vector<int>(k));
        forn(i,n){
            forn(j,k){
                cin >> plates[i][j];
                if(j != 0) 
                    plates[i][j] += plates[i][j-1];
            }
        }

        

    
        cout << "Case #" << t+1 << ": " << fb(0,plates,p,0) << endl;
    }
    return 0;
}