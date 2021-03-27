#include <iostream>
#include <math.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main(){
    pair<int,int> p;
    forn(i,5)
        forn(j,5){
            int c;
            cin >> c;
            if(c == 1)
                p = {j,i};
        }

    cout << abs(2-p.second)+abs(2-p.first) << endl;
    return 0;
}