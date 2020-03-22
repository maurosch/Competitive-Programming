#include <iostream>
#include <vector>
#include <algorithm>
#define For(i,n) for(int i = 0; i < n; i++)
using namespace std;

int mejorCamino(int a, int k, vector<int> &mapa, int peso)
{
    int minimo = a;
    if(mapa.size()-1 <= a+k) return peso+mapa[mapa.size()-1];
    for(int i = 1; i < k+1; i++)
    {
        //if(mapa[a+i] <= mapa[minimo]) minimo = a+i;
    }
    int maxN = 0;
    for(int i = minimo; i < a+k; i++)
    {
        maxN = max(maxN, mejorCamino(i, k, mapa, peso+mapa[i]));
    }
    return maxN;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>mapa(n);
    For(i, n) cin >> mapa[i];
    cout << mejorCamino(0, k, mapa, mapa[0]);
    return 0;
}
