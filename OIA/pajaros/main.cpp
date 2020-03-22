#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
const int INF = 999999999;

int main()
{
    ifstream in("pajaros.in");
    ofstream out("pajaros.out");

    int mediciones;
    in >> mediciones;
    mediciones++;
    vector<int>alturas(mediciones);
    alturas[0] = 0;
    forsn(i,1,mediciones)
        in >> alturas[i];

    vector<vector<int>> dp(302, vector<int>(60001, INF));

    //Completo Primera Columna
    dp[0][0] = 0;

    forsn(j, 1, dp[0].size())
    {
        forn(i, dp.size())
        {
            int minimo = INF;
            int dist = alturas[j]-i;
            if(dist < 0) dist *= -1;
            if(i > 0)
                minimo = min(minimo, dp[i-1][j-1]);
            if(i < dp.size()-1)
                minimo = min(minimo, dp[i+1][j-1]);

            if(minimo != INF)
                dp[i][j] = minimo + dist;
        }
    }

    forn(i,dp.size())
    {
        forn(j, dp[i].size())
        {
            if(dp[i][j] == INF) cout << "& ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int minimo = INF;
    forn(i, dp.size())
    {
        minimo = min(minimo, dp[i][dp[0].size()-1]);
    }
    out << minimo << endl;


    return 0;
}