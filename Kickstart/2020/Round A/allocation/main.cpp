#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main(){
    int T;
    cin >> T;
    forn(t,T){
        int n, b, s = 0;
        cin >> n >> b;
        vector<int>num(n);
        forn(i,n)
            cin >> num[i];
            
        sort(num.begin(),num.end());
        forn(i,n){
            b -= num[i];
            if(b >= 0) s++;
        }
        cout << "Case #" << t+1 << ": " << s << endl;
    }
    return 0;
}