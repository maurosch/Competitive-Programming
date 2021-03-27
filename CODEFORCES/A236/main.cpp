#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main(){
    string c;
    cin >> c;
    vector<int>l(26);
    forn(i, c.size())
        l[c[i]-'a']++;

    int s = 0;
    forn(i, l.size())
        if(l[i] > 0)
            s++;

    if(s % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}