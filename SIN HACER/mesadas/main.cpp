#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
typedef pair<int,int> ii;

bool entra(ii a, ii b)
{
    if(a.first <= b.first and a.second <= b.second)
        return true;
    return false;
}


int main()
{
    ifstream in("mesadas.in");
    ofstream out("mesadas.out");
    int N;
    in >> N;
    vector<ii> m(N);
    vector<bool> usadas(N);
    forn(i,N)
    {
        int x, y;
        in >> x >> y;
        if(x > y)
        {
            m[i].first = x;
            m[i].second = y;
        }
        else
        {
            m[i].first = y;
            m[i].second = x;
        }
    }
    sort(m.begin(), m.end());

    int cantPilas = 0;
    vector<bool>usados(N,false);
    int noUsados = N;
    ///-------LIC-------
    while(noUsados > 0)
    {
        cantPilas++;
        vector<int>dp(N,1);
        vector<int>ant(N,-1);
        int mayorSecuencia = 0;
        int mayorSecuenciaIndex = 0;
        forn(i,N)
        {
            forn(j,i)
            {
                if(!usados[i] and entra(m[j], m[i]) and dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    ant[i] = j;
                    if(dp[i] > mayorSecuencia)
                    {
                        mayorSecuencia = dp[i];
                        mayorSecuenciaIndex = i;
                    }
                }
            }
        }
        while(mayorSecuenciaIndex != -1)
        {
            noUsados--;
            usados[mayorSecuenciaIndex] = true;
            mayorSecuenciaIndex = ant[mayorSecuenciaIndex];
        }
        /*forn(i,N)
        {
            cout << m[i].first << " " << m[i].second << " " << dp[i] << " " << ant[i] << endl;
        }
        cout << "---------------------" << endl;*/
    }
    out << cantPilas << endl;
    
    return 0;
}
