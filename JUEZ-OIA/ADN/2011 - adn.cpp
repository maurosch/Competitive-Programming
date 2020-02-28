//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 18/02/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://juez.oia.unsam.edu.ar/#/task/adn/statement
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;
const int INF = 999999999;

//Resuelto mediante programación dinámica pero sin guardar los valores ya que eran demasiados.
//Tenemos un indice en cada 'adn' que nos va diciendo en que parte estamos,
//la cuestión es que resolvemos achicando el problema, si son iguales las primeras letras
//entonces las sacamos (en otras palabras: movemos los 2 indices).
//Si no es el caso, entonces probamos o sacar, reemplazar o meter una base(mover un indice o el otro o los 2 juntos).

int recursiva(vector<int> &dp, string &adn, string &adnFinal, int indice, int indiceFinal, int K, int cantMutaciones)
{
    if (indice < adn.size() and dp[indice] != INF) return dp[indice];
    if(cantMutaciones > K) return cantMutaciones;

    if(indice == indiceFinal and indice >= adn.size())
        return cantMutaciones;


    if(indiceFinal >= adnFinal.size())
    {
        //Caso en que llegamos al final del adn al cual tenemos que llegar entonces quiere decir que solo se pueden meter bases.
        dp[indice] = min(recursiva(dp, adn, adnFinal, indice+1, indiceFinal, K, cantMutaciones+1),dp[indice]);
        return dp[indice];
    }
    if(indice >= adn.size())
    {
        //Caso en que llegamos al final del adn que modificamos entonces borramos bases.
        dp[indice] = min(recursiva(dp, adn, adnFinal, indice, indiceFinal+1, K, cantMutaciones+1),dp[indice]);
        return dp[indice];
    }

    if(adn[indice] == adnFinal[indiceFinal])
        dp[indice] = recursiva(dp, adn, adnFinal, indice+1, indiceFinal+1, K, cantMutaciones);
    else
    {
        //Si quitamos la base:
        dp[indice] = min(recursiva(dp, adn, adnFinal, indice+1, indiceFinal, K, cantMutaciones+1),dp[indice]);

        //Si reemplazamos la base:
        dp[indice] = min(recursiva(dp, adn, adnFinal, indice+1, indiceFinal+1, K, cantMutaciones+1),dp[indice]);
    
        //Si agregamos una base:
        dp[indice] = min(recursiva(dp, adn, adnFinal, indice, indiceFinal+1, K, cantMutaciones+1),dp[indice]);
    }
    return dp[indice];
}

int main()
{
    ifstream in("adn.in");
    ofstream out("adn.out");
    int N, M, K;
    in >> N >> M >> K;
    string palabra1, palabra2;
    in >> palabra1 >> palabra2;
    vector<int> dp(palabra1.size()+1,INF);
    int solucion = recursiva(dp, palabra1, palabra2, 0, 0, K, 0);
    if(solucion > K) cout << "Muy distintas";
    else cout << solucion;
    return 0;
}
