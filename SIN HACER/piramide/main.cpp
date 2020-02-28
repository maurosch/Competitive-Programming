#include <iostream>
#include <vector>
#include <utility>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define rforn(i, n) for(int i = int(n); i >= 0; i--)
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef vector< vector<int> > matriz;

int main()
{
    int m, n, a, b, c, d;
    cin >> m >> n >> a >> b >> c >> d;

    matriz mapa(n, vector<int>(m));
    matriz mapaSuma(n+1, vector<int>(m+1));

    forn(i,n)
    {
        forn(j,m)
        {
            int aux;
            cin >> aux; 
            mapaSuma[i+1][j+1] = mapaSuma[i+1][j] + mapaSuma[i][j+1] - mapaSuma[i][j] + aux;
        }
    }

    forn(i,n+1)
    {
        forn(j,m+1)
        {
            cout << mapaSuma[i][j] << " ";
            if(mapaSuma[i][j] < 100) cout << " ";
            if(mapaSuma[i][j] < 10) cout << " ";
        }
        cout << endl;
    }

    ii maxPiramide;
    int maxPiramideAux;
    ii maxChamber;
    int maxChamberAux;

    forsn(i,b,n+1)
    {
        forsn(j,a,m+1)
        {
            if(mapaSuma[i][j] -  > maxPiramideAux)
            {

            }
        }
    }

    
    return 0;
}