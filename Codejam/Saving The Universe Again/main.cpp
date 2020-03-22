#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0 ; i--)

int calcularDanio(string &comandos)
{
    int ataque = 1;
    int danio = 0;
    forn(i,comandos.size())
    {
        if(comandos[i]=='C') ataque*=2;
        if(comandos[i]=='S') danio += ataque;
    }
    return danio;
}

int main()
{
    int t;
    cin >> t;
    forn(z,t)
    {
        cout << "Case #" << z+1 << ": ";
        int d;
        string comandos;
        cin >> d >> comandos;
        int cont = 0;
        forn(i,comandos.size())
            if(comandos[i]=='S') cont++;

        if(cont > d)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int s = 0;
        while (calcularDanio(comandos) > d)
        {
            s++;
            int indexFinal = comandos.size()-1;       
            while(!(comandos[indexFinal] == 'S' and comandos[indexFinal-1] == 'C')) indexFinal--;
            comandos[indexFinal] = 'C';
            comandos[indexFinal-1] = 'S';
        }
        cout << s << endl;
    }
    return 0;
}