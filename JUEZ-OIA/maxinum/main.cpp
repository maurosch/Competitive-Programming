#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;
typedef pair<int,int> ii;
#define f first
#define s second

ii recursiva(vector<int>&numeros, int indice, vector<ii>&dp)
{
    if(dp[indice].f != -1) return dp[indice];

    if(numeros.size()-indice == 1)
        return {0,numeros[indice]};

    if(numeros.size()-indice == 2)
    {
        dp[indice] = {numeros[indice]*numeros[indice+1],0};
        return dp[indice];
    }

    ii sinSaltar = recursiva(numeros, indice+2, dp);
    sinSaltar.f += numeros[indice]*numeros[indice+1];

    ii saltandoNumero = recursiva(numeros, indice+1, dp);

    if(sinSaltar >= saltandoNumero)
        dp[indice] = sinSaltar;
    else
    {
        saltandoNumero.s += numeros[indice];
        dp[indice] = saltandoNumero;
    }
    return dp[indice];
}

int main()
{
    ifstream in("maxinum.in");
    ofstream out("maxinum.out");

    int N;
    in >> N;
    vector<int>numerosPares(N/2);
    vector<int>numerosImpares;
    if( N % 2 != 0 )
        numerosImpares.resize(N/2+1);
    else 
        numerosImpares.resize(N/2);

    forn(i,N/2)
        in >> numerosImpares[i] >> numerosPares[i];

    if( N % 2 != 0 ) 
        in >> numerosImpares[numerosImpares.size()-1];


    vector<ii>dpImparesPairs(numerosImpares.size(),{-1,-1});
    vector<ii>dpParesPairs(numerosPares.size(),{-1,-1});

    //CORNER CASE
    if(N == 1)
    {
        out << "0" << endl << numerosImpares[0];
        return 0;
    }

    //BOTTOM-UP ya que TOP-DOWN son muchas llamadas (máxima cantidad de llamadas ~ 150000)
    rforn(i,numerosImpares.size())
        recursiva(numerosImpares, i, dpImparesPairs);

    rforn(i,numerosPares.size())
        recursiva(numerosPares, i, dpParesPairs);


    ii solucion1 = recursiva(numerosImpares, 0, dpImparesPairs);
    ii solucion2 = recursiva(numerosPares, 0, dpParesPairs);

    out <<  solucion1.f + solucion2.f << endl << solucion1.s + solucion2.s;

    return 0;
}