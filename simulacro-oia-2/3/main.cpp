#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
const long long inf = 999999999999;
const int inf2 = 999999999;
long long s = inf;

int recursiva(int pos, vector<int>&p, vector<int> &coord, vector<int> &dp)
{
    if(pos >= int(coord.size()))
        return 0;

    if(dp[pos] != inf2) return dp[pos];

    forsn(i, pos, coord.size())
        dp[pos] = min(dp[pos],recursiva(i+1, p, coord, dp)+p[coord[i]-coord[pos]]);
    
    return dp[pos];
}

int main()
{
    freopen("a3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int>coord(n);
    vector<int>p(m);

    forn(i,n)
        cin >> coord[i];
    forn(i,m)
        cin >> p[i];

    sort(coord.begin(), coord.end());

    rforn(i, m-1)
        if(p[i] > p[i+1])
            p[i] = p[i+1];

    //vector<int>dp(m+1, inf2);
    vector<int>dp(n, inf2);
    recursiva(0, p, coord, dp);

    //forn(i, n) cout << dp[i] << " ";
    cout << dp[0] << endl;

    return 0;
}