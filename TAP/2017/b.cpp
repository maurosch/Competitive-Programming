#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int>want(n);
    vector<int>chests(n);
    forn(i,n)
        cin >> want[i];

    forn(i,n)
        cin >> chests[i];

    sort(want.begin(), want.end());
    sort(chests.begin(), chests.end());
    
    const long long resto = 1e9+7;
    long long s = 1;
    for(int i = n-1; i >= 0; i--)
    {
        long long c = distance(lower_bound(chests.begin(), chests.end(), want[i]), chests.end());
        c -= (n-1 - i);
        s *= c;
        s %= resto; 
    }
    cout << s << endl;


    return 0;
}