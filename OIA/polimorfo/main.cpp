#include <iostream>
#include <vector>
//#include <stdlib.h>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

int main()
{
    //freopen("polimorfo.in","r",stdin);
    //freopen("polimorfo.out","w",stdout);
    ifstream in("polimorfo.in");
    ofstream out("polimorfo.out");
    int N, M;
    in >> N >> M;
    vector<int> numeros(N);
    forn(i,N) in >> numeros[i];
    vector<int>contador(M+1, 0);
    vector<int>solucion;
    int cantMalos = 0;
    ///Por ventanas
    forn(i,M)
    {
        if(numeros[i] < 1 or numeros[i] > M)
            cantMalos++;
        else 
        {
            if(contador[numeros[i]] > 0)
            {
                cantMalos++;
            }
            contador[numeros[i]]++;
        }
    }
    if(cantMalos == 0)
        solucion.push_back(1);
    forn(i, N-M)
    {
        int numeroAgrega = numeros[i+M];
        int numeroSale = numeros[i];
        if( numeroAgrega < 1 or numeroAgrega > M)
            cantMalos++;
        else 
        {
            if(contador[numeroAgrega] > 0)
            {
                cantMalos++;
            }
            contador[numeroAgrega]++;
        }

        if( numeroSale < 1 or numeroSale > M)
            cantMalos--;
        else 
        {
            if(contador[numeroSale] > 1)
            {
                cantMalos--;
            }
            contador[numeroSale]--;
        }

        if(cantMalos == 0)
            solucion.push_back(i+2);
    }

    out << solucion.size() << endl;
    if(solucion.size() > 10)
    {
        forn(i,5)
            out << solucion[i] << " ";
        forsn(i, solucion.size()-5,solucion.size())
            out << solucion[i] << " ";
    }
    else
    {
        forn(i,solucion.size())
            out << solucion[i] << " ";
    }
    return 0;
}
