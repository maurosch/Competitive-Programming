#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main()
{
    freopen("a.in", "w", stdout);
    cout << "5000 100000" << endl;
    int cont = 0;
    forn(i,5000)
    {
        cout << cont << endl;
        cont+=5;
    }
    cont = 10;
    forn(i,100000)
    {
        cout << cont << endl;
        cont+=5;
    }

    return 0;
}