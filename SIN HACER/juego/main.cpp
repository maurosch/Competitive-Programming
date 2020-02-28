#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//
#define forn(i, n) for(int i = 0; i < int(n); i++)

#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
typedef vector<int> vi;
typedef vector<bool> vb;
const int INF = 999999999;

void calc(int pos, vb &cambio, vi &numeros, int &maximo)
{
    if(pos == numeros.size()/2)
    {
        /*int maxAux = 0;
        forn(i, numeros.size())
            maxAux += numeros[i];
        if(maxAux > maximo) maximo = maxAux;*/

        return;
    }

    ///Dejamos como esta
    calc(pos+1, cambio, numeros, maximo);
    ///Cambiamos signo
    cambio[pos] = true;
    calc(pos+1, cambio, numeros, maximo);
}

int main()
{
    int n;
    cin >> n;
    n *=2;
    vector<int>a(n);

    forn(i, n) cin >> a[i];
    int maximo = -INF;
    vb cambio(n, false);
    calc(0, cambio, a, maximo);
    cout << maximo << endl;
    return 0;
}
