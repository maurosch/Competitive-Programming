//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 15/04/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://www.spoj.com/problems/DQUERY/
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

//Utilizamos el algoritmo de MO: los ordenamos de menor a mayor la queries
//mediante el primer indice y luego los que están en el mismo bloque (cada bloque tiene √n)
//los ordenamos por el segundo indice

//Luego para guardar los valores "distintos" utlizamos el mismo
//método que el counting sort: un arreglo donde la posición es
//el número y el valor la cantidad de veces que se repite y además tenemos
//en una variable la suma de la cantidad de números sin contar repeticiones. 

struct query
{
    int first, second, num;
};

void add(vector<int> &arreglo, int z, int &sumaCont)
{
    if(arreglo[z] == 0) sumaCont++;
    arreglo[z]++;
}

void remove(vector<int> &arreglo, int z, int &sumaCont)
{
    arreglo[z]--;
    if(arreglo[z] == 0) sumaCont--;
}

int BLOCK_SIZE;

bool MOsort(query a, query b)
{
    int bloque_a = a.first / BLOCK_SIZE;
    int bloque_b = b.first / BLOCK_SIZE;
    if(bloque_a != bloque_b) 
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int n, q;
    scanf("%d",&n);
    //Utilizamos SCANF/PRINF por la ajustada limitación de tiempo

    vector<int>numeros(n);
    forn(i,n)
        scanf("%d",&numeros[i]);

    cin >> q;
    vector<query>queries(q);
    vector<int>soluciones(q);

    forn(i,q)
    {
        scanf("%d %d",&queries[i].first, &queries[i].second);
        queries[i].num = i;
        queries[i].first--; queries[i].second--;
    }

    
    BLOCK_SIZE = int(sqrt(n));
    sort(queries.begin(), queries.end(), MOsort);

    //Versión Lambda
    /*int BLOCK_SIZE = int(sqrt(n));
    sort(queries.begin(), queries.end(),
    [BLOCK_SIZE](query a, query b) -> bool
    {
        int bloque_a = a.first / BLOCK_SIZE;
        int bloque_b = b.first / BLOCK_SIZE;
        if(bloque_a != bloque_b) 
            return a.first < b.first;
        return a.second < b.second;
    });*/

    vector<int>arreglo(1000002);
    int sumaCont = 0;
    int mo_left = 0, mo_right = -1;
    forn(z,q)
    {
        int left = queries[z].first;
        int right = queries[z].second;
        //Avanzamos o retrocedemos con los indices
        while(mo_right < right) {
            mo_right++;
            add(arreglo, numeros[mo_right], sumaCont);
        }
        while(mo_right > right) {
            remove(arreglo, numeros[mo_right], sumaCont);
            mo_right--;
        }

        while(mo_left < left) {
            remove(arreglo, numeros[mo_left], sumaCont);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(arreglo, numeros[mo_left], sumaCont);
        }
        soluciones[queries[z].num] = sumaCont;
    }

    forn(i,soluciones.size())
        printf("%d\n",soluciones[i]);
    
    return 0;
}