#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
const int INF = 999999999;
typedef pair<int,int> ii;





int main()
{
    ifstream in("vuelo.in");
    ofstream out("vuelo.out");

    int mediciones;
    in >> mediciones;
    mediciones++;
    vector<int>alturas(mediciones);
    alturas[0] = 0;
    forsn(i,1,mediciones)
        in >> alturas[i];

    vector<vector<int>> dp(302, vector<int>(mediciones, INF));
    vector<vector<pair<int,int>>> padres(302, vector<pair<int,int>>(mediciones, make_pair(-1,-1)));

    //Completo Primera Columna
    dp[0][0] = 0;

    forsn(j, 1, dp[0].size())
    {
        forn(i, dp.size())
        {
            int minimo = INF;
            int dist = alturas[j]-i;
            if(dist < 0) dist *= -1;
            if(i > 0 and dp[i-1][j-1] < minimo)
            {
                minimo = dp[i-1][j-1];
                padres[i][j].first = i-1;
                padres[i][j].second = j-1;
            }
            if(i < int(dp.size())-1 and dp[i+1][j-1] < minimo)
            {
                minimo = dp[i+1][j-1];
                padres[i][j].first = i+1;
                padres[i][j].second = j-1;
            }

            if(minimo != INF)
                dp[i][j] = minimo + dist;
        }
    }

    /*forn(i,dp.size())
    {
        forn(j, dp[i].size())
        {
            if(dp[i][j] == INF) cout << "& ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    int minimo = INF;
    int indiceMin = -1;
    forn(i, dp.size())
    {
        minimo = min(minimo, dp[i][dp[0].size()-1]);
        indiceMin = i;
    }
    cout << indiceMin << endl;
    cout << minimo << endl;

    vector<int>camino;
    ii aux = {indiceMin,dp[0].size()-1};
    while(aux.first != -1)
    {
        cout << aux.second << endl;
        aux = padres[aux.first][aux.second];
    }

    forn(i, dp.size())
    {
        forn(j, dp[0].size())
        {
            cout << padres[i][j].first << "y" << padres[i][j].second << " ";
        }
        cout << endl;
    }

    return 0;
}