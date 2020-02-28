#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back 
using namespace std;

int mejor(vector<int>&a, vector<int>&b)
{
    int suma = 0, sumaAux1 = 0, sumaAux2 = 0, indice1 = 0, indice2 = 0;
    while(indice1 < a.size() or indice2 < b.size())
    {
        if((a[indice1] < b[indice2] or indice2 >= b.size()) and indice1 < a.size())
        {
            sumaAux1 += a[indice1];
            indice1++;
        }
        else
        {
            if((b[indice2] < a[indice1] or indice1 >= a.size()) and indice2 < b.size())
            {
                sumaAux2 += b[indice2];
                indice2++;
            }
            else
            {
                suma += max(sumaAux1, sumaAux2) + a[indice1];
                sumaAux1 = 0;
                sumaAux2 = 0;
                indice1++;
                indice2++;
            }
        }
    }
    suma += max(sumaAux1, sumaAux2);
    return suma;
}

int main()
{
    while(true)
    {
        int auxN;
        cin >> auxN;
        if(auxN == 0) return 0;
        vector<int>primero(auxN), segundo(auxN);
        forn(i, auxN)
            cin >> primero[i];
        cin >> auxN;
        forn(i, auxN)
            cin >> segundo[i];
        cout << mejor(primero,segundo) << endl;
    }
    return 0;
}