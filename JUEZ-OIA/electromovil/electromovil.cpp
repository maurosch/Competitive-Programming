#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
typedef vector<int> vi;
const int INF = 999999999;

int recursiva(int parada, vi &ubicacion, vi &autonomia, vi &padres, vi &dp)
{
    if(dp[parada] != -1) return dp[parada];

    dp[parada] = INF;
    forn(i, parada)
    {
        int dist = ubicacion[parada]-ubicacion[i];

        if( dist <= 500000 and dp[parada] == INF and autonomia[i] >= dist )
        {
            int aux = recursiva(i, ubicacion, autonomia, padres, dp);
            aux++;
            if(aux < dp[parada])
            {
                dp[parada] = aux;
                padres[parada] = i;
            }
        }
    }
    return dp[parada];
}

#define alcance(i) (ubicacion[i]+autonomia[i]) 

vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
    /*vi dp(E, -1);
    vi padres(E, -1);
    dp[0] = 1;*/
    //recursiva(E-1,ubicacion,autonomia,padres,dp);
    

    int actual = 0, proximo = 0;
    vi ret;

    while(actual != proximo)
    {
        int talvez = proximo;
        while(talvez < E)
        {
            if(alcance(actual) >= ubicacion[talvez] and  alcance(talvez) > alcance(proximo))
            {
                proximo = talvez;
            }
            talvez++;
        }
        
        actual = proximo;
        ret.push_back(actual);
    }
    
    /*int aux = E-1;
    //ret.push_back(ubicacion[E-1]);
    while(padres[aux] != -1)
    {
        ret.push_back(ubicacion[aux]);
        aux = padres[aux];
    }
    reverse(ret.begin(), ret.end());
    //forn(i,padres.size()) cout << padres[i] << " ";
    //cout << endl << endl;
    */
    return ret;
}
