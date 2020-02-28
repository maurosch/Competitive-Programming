#include <iostream>
#include <vector>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define rforn(i, n) for(int i = int(n)-1; i >= 0; i--)
#define pb push_back
using namespace std;
/*
double cantFormas(vector<char>&array, int k)
{
    int iterador1 = 0, iterador2 = 0, cant = 0, solucion = 0;
    if(array[0] == '1') cant++;
    while(iterador2 < array.size()-1 or iterador1 < array.size()-1)
    {
        cout << iterador1 << " " << iterador2 << " ";
        if(cant == k)
        {
            solucion++;
            cout << " ++" << endl; 
        }
        else cout << endl;

        if(((cant <= k and (cant == k and array[iterador2+1] != '1')) or iterador1 == iterador2) and iterador2 < array.size()-1)
        {
            iterador2++;
            if(array[iterador2] == '1') cant++;
        }
        else
        {
            if(array[iterador1] == '1') cant--;
            iterador1++;
        }
   
    }
    return solucion;
}
*/

double cantFormas(vector<char>&array, int k)
{
    vector<int>prefixSum(array.size(),0);

    prefixSum[0] = (array[0] == '1') ? 1 : 0;
    for(int i = 1; i < prefixSum.size(); i++)
    {
        if(array[i] == '1')
            prefixSum[i] = prefixSum[i-1]+1;
        else 
            prefixSum[i] = prefixSum[i-1];
    }
    forn(i, prefixSum.size())
        cout << prefixSum[i] << " ";
    cout << endl;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++)
    {
        int cantPersonas, k;
        cin >> cantPersonas >> k;
        vector<char>array(cantPersonas);
        forn(i, cantPersonas) cin >> array[i];
        cout << cantFormas(array, k) << endl;
    }
    return 0;
}