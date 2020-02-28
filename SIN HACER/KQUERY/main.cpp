//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - /04/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://www.spoj.com/problems/KQUERY/
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

//--------------------Fenwick-Tree--------------------
void updateFT(vector<int> &FT, int pos, int v)
{
    for(int x = pos+1; x < int(FT.size()); x += x & -x) FT[x] += v;
}
int getFT(vector<int> &FT, int pos)
{
    int s = 0;
    for(int x = pos+1; x > 0; x -= x & -x) s += FT[x];
    return s;
}
int get(vector<int> &FT, int a, int b)
{
    return getFT(FT,b) - getFT(FT,a-1);
}
//----------------------------------------------------


struct query
{
    int first, second, num, k;
};

void add(vector<int> &FT, int z)
{
    updateFT(FT, z, 1);
}
void remove(vector<int> &FT, int z)
{
    updateFT(FT, z, -1);
}

/*int BLOCK_SIZE;

bool MOsort(query a, query b)
{
    int bloque_a = a.first / BLOCK_SIZE;
    int bloque_b = b.first / BLOCK_SIZE;
    if(bloque_a != bloque_b) 
        return a.first < b.first;
    return a.second < b.second;
}*/

int main()
{
    int n, q;
    scanf("%d",&n);
    //Utilizamos SCANF/PRINF por la ajustada limitación de tiempo

    vector<int>numeros(n);
    forn(i,n)
        scanf("%d",&numeros[i]);

    scanf("%d",&q);
    vector<query>queries(q);
    vector<int>soluciones(q);

    forn(i,q)
    {
        scanf("%d %d %d",&queries[i].first, &queries[i].second, &queries[i].k);
        queries[i].num = i;
        queries[i].first--; queries[i].second--;
    }

    
    //BLOCK_SIZE = int(sqrt(n));
    sort(queries.begin(), queries.end(), [](){  });

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

    vector<int>FT(1000000002);
    int mo_left = 0, mo_right = -1;
    forn(z,q)
    {
        cout << "a" << endl;
        int left = queries[z].first;
        int right = queries[z].second;
        //Avanzamos o retrocedemos con los indices
        while(mo_right < right) {
            mo_right++;
            add(FT, numeros[mo_right]);
        }
        while(mo_right > right) {
            remove(FT, numeros[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(FT, numeros[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(FT, numeros[mo_left]);
        }
        soluciones[queries[z].num] = get(FT,queries[z].k+1, int(FT.size())-2);
    }

    forn(i,soluciones.size())
        printf("%d\n",soluciones[i]);
    
    return 0;
}