#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0 ; i--)
const int inf = 1000000001;
typedef vector<vector<int>> matriz;

bool check(vector<vector<bool>> &mapa, int centroY, int centroX)
{
    forsn(i,centroY-1,centroY+2)
    {
        forsn(j,centroX-1,centroX+2)
        {
            if(!mapa[i][j]) return false;
        }
    }
    return true;
} 

int main()
{
    int t;
    cin >> t;
    forn(z,t)
    {
        int A;
        cin >> A;
        A = 200;
        vector<vector<bool>> mapa(300,vector<bool>(300,false));
        //Comienzo = 2x 2y
        int preparadoX, preparadoY;

        for(int i = 3; i <= 2 + A - 2; i+=3)
        {
            for(int j = 3; j < 2 + A - 2; j+=3)
            {
                while(!check(mapa, i, j))
                {
                    cout << i << " " << j << endl;
                    cin >> preparadoY >> preparadoX;
                    if(preparadoY == 0)
                    {
                        goto finish;
                    }
                    mapa[preparadoY][preparadoX] = true;
                }
            }
        }
        finish:;
    }
    return 0;
}