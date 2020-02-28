#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i > 0; i--)

int main()
{
    string a, b, solucion;
    cin >> a >> b;
    forn(i,a.size())
    {
        if(b[i] > a[i])
        {
            cout << "-1" << endl;
            return 0;
        }
        else
        {
            solucion += b[i];
        }
    }
    cout << solucion;

    return 0;
}
