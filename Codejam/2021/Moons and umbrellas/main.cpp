#include <iostream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int cost(int cost1, int cost2, string mural){
    string newMural;
    for(int i = 0; i < mural.size(); i++){
        if(mural[i] != '?'){
            newMural += mural[i];
        }
    }
    if(newMural.size() < 2){
        return 0;
    }
    int sol = 0;
    for(int i = 0; i < newMural.size()-1; i++){
        if(newMural[i] != newMural[i+1])
            sol += newMural[i] == 'C' ? cost1 : cost2;
    }
    return sol;
}
int main(){
    int T;
    cin >> T;
    forn(t,T){
        int cost1, cost2;
        string mural;
        cin >> cost1 >> cost2 >> mural;
        cout << "Case #" << t+1 << ": " << cost(cost1, cost2, mural) << endl;
    }
}