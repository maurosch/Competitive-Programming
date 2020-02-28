#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
const int INF = 999999999;
int dp[20000001];

int pasos(int numero)
{
    if(dp[numero] != INF) return dp[numero];
    dp[numero] = pasos(numero-1)+1;
    if(numero % 3 == 0) dp[numero] = min(pasos(numero/3)+1,dp[numero]);
    if(numero % 2 == 0) dp[numero] = min(pasos(numero/2)+1,dp[numero]);
    return dp[numero];
}

int main()
{
    forn(i, 20000001) dp[i] = INF;
    //dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i < 20000001; i++) dp[i] = pasos(i);
    int t;
    cin >> t;
    forn(z,t)
    {
        long long aux;
        cin >> aux;
        cout << "Case " << z+1 << ": " << pasos(aux) << endl;
    }
    return 0;
}