#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)

struct punto
{
    int x, y;
};

int main()
{
    
    int n;
    cin >> n;
    vector<punto>puntos(n);
    //
    forn(i,n) cin >> puntos[i].x >> puntos[i].y;

    //Busco Primera Linea
    int pteArriba, pteAbajo;
    forn(i, puntos.size()-1)
    {
        forsn(j, i+1, puntos.size())
        {
            ///y2-y1 / x2-x1
            pteArriba = (puntos[j].y - puntos[i].y);
            pteAbajo = (puntos[j].x - puntos[i].x);
        }
    }

    return 0;
}
