// 15/03/2020
// https://cses.fi/problemset/task/1163/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define all(v) v.begin(),v.end()
#define left first //Just for code clarification
#define right second //Just for code clarification

int findPos(int v, vector<int> &a){
    return lower_bound(all(a),v)-a.begin();
}

int main(){
    int x, n;
    cin >> x >> n; 
    vector<int> lightsRemoval(n);
    vector<int> solution(n);
    forn(i,n)
        cin >> lightsRemoval[i];

    //Gonna remove from back to begin
    reverse(lightsRemoval.begin(), lightsRemoval.end());
    auto lightsOrdered = lightsRemoval;
    lightsOrdered.push_back(0); //For first light (doesn't matter that there is a light there)
    lightsOrdered.push_back(x); //For last light
    sort(lightsOrdered.begin(), lightsOrdered.end());
    
    vector<pair<int,int>> lightsLeftAndRight(n+2); 
    //Save left light and right light which are not removed from each light
    forn(i,n+2){
        lightsLeftAndRight[i].left = i-1; 
        lightsLeftAndRight[i].right = i+1; 
    }

    int maxDis = 0;
    for(int i = 1; i < n+2; i++) //Max distance with all lights
        maxDis = max(maxDis, lightsOrdered[i]-lightsOrdered[i-1]);
    solution[0] = maxDis;

    forn(i,n-1){
        int pos = findPos(lightsRemoval[i],lightsOrdered);

        int posLeftLight = lightsLeftAndRight[pos].left;
        int posRightLight = lightsLeftAndRight[pos].right;
        
        lightsLeftAndRight[posRightLight].left = posLeftLight;
        lightsLeftAndRight[posLeftLight].right = posRightLight;

        maxDis = max(maxDis, lightsOrdered[posRightLight]-lightsOrdered[posLeftLight]);
        solution[i+1] = maxDis; //Max distance of each iteration (each removal)
    } 
    
    reverse(all(solution)); //Solution is backwards
    forn(i, solution.size())
        cout << solution[i] << " ";
    return 0;
}