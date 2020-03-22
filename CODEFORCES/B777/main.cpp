#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
int main()
{
    int n;
    cin >> n;
    vector<int>sher(n);
    vector<int>mori(n);
    string aux;
    cin >> aux;
    forn(i, n)
        sher[i] = '0' - aux[i];
    cin >> aux;
    forn(i, n)
        mori[i] = '0' - aux[i];

    sort(sher.begin(), sher.end());
    sort(mori.begin(), mori.end());
    return 0;
}