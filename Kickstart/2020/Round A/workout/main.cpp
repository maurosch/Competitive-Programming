#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main(){
    int T;
    cin >> T;
    forn(t,T){
        int n, k, s = 0;;
        cin >> n >> k;

        vector<int> nums(n);
        vector<int> differences(n-1);
        forn(i, n)
            cin >> nums[i];
        
        priority_queue<pair<int, pair<int,int>>> cola;

        for(int i = 0; i < n-1; i++){
            cola.push({nums[i+1]-nums[i],{1,nums[i+1]-nums[i]}});
            //cout << nums[i+1]-nums[i] << " ";
        }
        //cout << endl;

        for(int i = 0; i < k; i++){
            // numero dividido - cant div - numero original
            pair<int,pair<int,int>> aux = cola.top();
            //cout << aux.first << " " << aux.second << endl;
            bool addOne = false;
            cola.pop();
            if(aux.second.second % (aux.second.first+1) != 0) 
                addOne = true;
                
            aux.first = aux.second.second/(aux.second.first+1);

            if(addOne)
                aux.first++;

            aux.second.first++;
            cola.push(aux);
        }

    
        cout << "Case #" << t+1 << ": " << cola.top().first << endl;
    }
    return 0;
}