#include <iostream>
#include <vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;
const int MAX_NUMBER = 1000001; //10^6

long long posibilidades(long long z)
{
    for(int n = z-1; n > 0; n--) 
        z+=n;
    return z;
}

long long cant(int k, string personas)
{
    long long solucion = 0;
    //Caso especial K=0
    if(k == 0)
    {
        int cont = 0;
        for(int i = 0; i < personas.size(); i++)
        {
            if(personas[i] == '0')
                cont++; 
            else
            {
                if(cont > 0)
                {
                    solucion+=posibilidades(cont);
                    cont = 0;
                }
            }
        }
        solucion+=posibilidades(cont);
        return solucion;
    }

    vector<int>sumPrefix(personas.size());
    sumPrefix[0] = personas[0]=='1' ? 1 : 0; //Primera iteracion
    for(int i = 1; i < sumPrefix.size(); i++)
        sumPrefix[i] = personas[i]=='1' ? sumPrefix[i-1]+1 : sumPrefix[i-1];

    vector<int>counting(MAX_NUMBER,0);
    forn(i, sumPrefix.size())
        counting[sumPrefix[i]]++;

    solucion += counting[k];
    for(int i = 1; i < sumPrefix.size() and sumPrefix[i-1]+k < sumPrefix.size(); i++)
        solucion += counting[sumPrefix[i-1]+k];

    return solucion;
}
int main()
{
    int t;
    cin >> t;
    forn(z,t)
    {
        int cantPersonas, k;
        cin >> cantPersonas >> k;
        string personas;
        cin >> personas;
        cout << cant(k, personas) << endl;
    }
    return 0;
}