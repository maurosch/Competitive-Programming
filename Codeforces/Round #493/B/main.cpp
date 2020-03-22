#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> numeros(n);
    vector<int> cortes;

    forn(i, n) cin >> numeros[i];

    int cantParesTotales = 0, cantImpTotales = 0;
    forn(i,n)
    {
        if(numeros[i] % 2 == 0)
            cantParesTotales++;
        else
            cantImpTotales++;
    }

    int cantPares = 0, cantImp = 0;
    forn(i,n-1)
    {
        if(numeros[i] % 2 == 0)
            cantPares++;
        else
            cantImp++;
        if(cantPares == cantImp and cantParesTotales-cantPares == cantImpTotales-cantImp)
        {
            //cout << i << endl;
            cortes.push_back(abs(numeros[i]-numeros[i+1]));
        }
    }

    sort(cortes.begin(), cortes.end());
    int cont = 0;
    forn(i, cortes.size())
    {
        cont += cortes[i];
        if(cont > b)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << cortes.size() << endl;

    return 0;
}