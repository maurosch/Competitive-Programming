#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)

/*
HACER MEDIANTE VENTANAS DESLIZANTES

HACER MEDIANTE BUSQUEDA BINARIA
*/


int main()
{
    int N, D, F;
    cin >> N >> D >> F;
    int s = 0;
    vector<bool>dias(D, false);
    forn(i, N) 
    {
        int aux;
        cin >> aux;
        dias[aux] = true;
    }
    forn(i,D)
    {
        int cantF = 0;
        int cantDias = 0;
        forsn(j,i+1,D)
        {
            if(!dias[j]) 
            { 
                cantF++;
                if(cantF > F) break;
            }
            cantDias++;
        }
        cout << i << endl; //<< " " << cantDias << endl;
        if(cantDias > s) s = cantDias;
    }
    cout << s << endl;
    return 0;
}