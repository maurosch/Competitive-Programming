#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define pb push_back
#define all(c) c.begin(), c.end()
using namespace std;
typedef vector<vector<int>> matriz;
const int INF = 999999999;

int mejor(int espacioSobrante, int numeroAgricultor, matriz &siguiente, matriz &sumas, matriz &agricultores, matriz &dp)
{
    if(dp[numeroAgricultor][espacioSobrante] != -INF) return dp[numeroAgricultor][espacioSobrante];
    siguiente[numeroAgricultor][espacioSobrante] = 0;  
    for(int i = 0; i < agricultores[numeroAgricultor+1].size() and espacioSobrante-i >= 0; i++)
    {
        if(sumas[numeroAgricultor+1][i] >= 0)
        {
            int z = mejor(espacioSobrante-i, numeroAgricultor+1, siguiente, sumas, agricultores, dp)+sumas[numeroAgricultor+1][i];
            if(z > dp[numeroAgricultor][espacioSobrante])
            {
                dp[numeroAgricultor][espacioSobrante] = z;
                siguiente[numeroAgricultor][espacioSobrante] = i;  
            }
        }
    }
    return dp[numeroAgricultor][espacioSobrante];
}

int main()
{
    ifstream in("zapallos.in");
    ofstream out("zapallos.out");
    matriz agricultores;
    int cantAgricultores, cantCajas, solucion = -INF;
    in >> cantAgricultores >> cantCajas;

    agricultores.pb(vector<int>(1,0)); //Agregar agricultor ficticio
    forn(i, cantAgricultores)
    {
        int cantAux;
        in >> cantAux;
        vector<int>agricultor(cantAux+1);
        agricultor[0] = 0;
        for(int j = 1; j < cantAux+1; j++)
        {
            int aux;
            in >> aux;
            agricultor[j] = 10-aux;
        }
        agricultores.pb(agricultor);
    }
    agricultores.pb(vector<int>(1,0)); //Agregar agricultor ficticio

    matriz sumas = agricultores;
    forn(i,sumas.size())
        for(int j = 1; j < sumas[i].size(); j++) sumas[i][j] += sumas[i][j-1];


    matriz dp(agricultores.size(),vector<int>(cantCajas+1,-INF));
    matriz dp2(agricultores.size(),vector<int>(cantCajas+1,-INF));
    matriz siguiente(agricultores.size(),vector<int>(cantCajas+1,-INF));
    matriz siguiente2(agricultores.size(),vector<int>(cantCajas+1,-INF));

    forn(i, dp[0].size())
        dp[dp.size()-1][i] = 0;
    forn(i, dp[0].size())
        dp2[dp.size()-1][i] = 0;
    
    int cantCajasInicial = cantCajas;
    solucion = mejor(cantCajas, 0, siguiente, sumas, agricultores, dp); cantCajas--;
    for(;cantCajas > 0 and solucion == mejor(cantCajas, 0, siguiente2, sumas, agricultores, dp2); cantCajas--);
    cantCajas++;

    vector<int>solucionCamino(agricultores.size());
    if(cantCajas != cantCajasInicial)
    {
        for(int cont = 0; cont < agricultores.size()-1; cont++)
        {
            solucionCamino[cont] = siguiente2[cont][cantCajas];
            cantCajas -= siguiente2[cont][cantCajas];
        }
        out << solucion << " " << accumulate(all(solucionCamino),0) << endl;
        forn(i, solucionCamino.size()) out << solucionCamino[i] << " "; 
       return 0; 
    }    
    for(int cont = 0; cont < agricultores.size()-1; cont++)
    {
        solucionCamino[cont] = siguiente[cont][cantCajas];
        cantCajas -= siguiente[cont][cantCajas];
    }
    out << solucion << " " << accumulate(all(solucionCamino),0) << endl;
    forn(i, solucionCamino.size()) out << solucionCamino[i] << " "; 
    return 0;
}