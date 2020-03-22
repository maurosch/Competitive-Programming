#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
const int INF = 999999999;

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
    vector<vector<int>> padres(302, vector<int>(mediciones, -1));

    //Completo Primera Columna
    dp[0][0] = 0;

    forsn(j, 1, dp[0].size())
    {
        forn(i, dp.size())
        {
            int minimo = INF;
            int dist = alturas[j]-i;
            if(dist < 0) dist *= -1;
            if(i > 0 and minimo > dp[i-1][j-1])
            {
                minimo = dp[i-1][j-1];
                padres[i][j] = i-1; 
            }
            if(i < int(dp.size())-1 and minimo > dp[i+1][j-1])
            {
                minimo = dp[i+1][j-1];
                padres[i][j] = i+1; 
            }

            if(minimo != INF)
                dp[i][j] = minimo + dist;
        }
    }

    /*forn(i,30)
    {
        forn(j, dp[i].size())
        {
            if(dp[i][j] == INF) cout << "& ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
    forn(i,30)
    {
        forn(j, dp[i].size())
        {
            cout << padres[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    int minimo = INF;
    int indiceMinimo = -1;
    forn(i, dp.size())
    {
        if(minimo > dp[i][dp[0].size()-1])
        {
            minimo = dp[i][dp[0].size()-1];
            indiceMinimo = i;
        }
    }
    
    out << minimo << endl;

    int auxIndice = indiceMinimo;
    vector<int> s;
    s.push_back(auxIndice);
    for(int i = int(dp[0].size())-1; i > 1; i--)
    {
        s.push_back(padres[auxIndice][i]);
        auxIndice = padres[auxIndice][i];
    }

    rforn(i,s.size()) 
        out << s[i] << endl;


    return 0;
}