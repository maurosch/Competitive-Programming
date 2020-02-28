#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
int main()
{
    int n;
    cin >> n;
    vector<int> segments(n);
    forn(i,n) cin >> segments[i];
    sort(segments.begin(), segments.end());
    long long suma = 0;
    forn(i,n-1) suma += segments[i];
    cout << 1+segments[n-1]-suma << endl;
    return 0;
}