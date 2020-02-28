#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <set>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
#define inf 999999

/*
VERSION 1 (Programación dinámica TOP-DOWN)
double menorScore(int z, int d, vector<double>&dp, const vector<int>&mapa)
{
    cout << z << endl;
    if(z == 1) return mapa[1];
    if(dp[z] != -1) return dp[z];
    double minimo = numeric_limits<double>::max();
    for(int i = 1; i <= d and z-i > 0; i++)
    {
        minimo = min(menorScore(z-i, d, dp, mapa), minimo);
    }
    dp[z] = minimo+mapa[z];
    return dp[z];
}
*/

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int>mapa(n+1);
    vector<double>dp(n+1, -1);
    for(int i = 1; i <= n; i++)
        cin >> mapa[i];

    //dp[0] = 0;
    cout << fixed << setprecision(0);
    

    
    //VERSION 2 (Programación dinámica BOTTOM-TOP)
    /*for(int i = 2; i <= n; i++)
    {
        dp[i] = numeric_limits<double>::max();
        for(int j = 1; j <= d and i-j > 0; j++)
            dp[i] = min(dp[i], dp[i-j]);
        dp[i] += mapa[i];
    }
    cout << dp[n] << endl;*/
    

    /*VERSION 3 (VENTANA DESLIZANTE)*/
    
    multiset<double> ventana;
    if(n == 1) 
    {
        cout << mapa[1];
        return 0;
    }
    if(d+1 >= n) cout << mapa[n]+mapa[1];
    else
    {
        dp[1] = mapa[1];
        for(int i = 2; i <= d+1; i++) dp[i] = mapa[i]+mapa[1];
        for(int i = 2; i <= d+1; i++) ventana.insert(dp[i]);
        for(int i = d+2; i <= n; i++)
        {
            dp[i] = (*ventana.begin())+mapa[i];
            ventana.erase(ventana.find(dp[i-d]));
            ventana.insert(dp[i]);
        }
        cout << dp[n] << endl;  
    }

    /*forn(i, n+1)
            cout << mapa[i] << " ";

        cout << endl;
        forn(i, n+1)
            cout << dp[i] << " ";*/
    return 0;
}