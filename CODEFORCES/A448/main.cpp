#include <iostream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;
int main()
{
    int cantCopas = 0, cantMedallas = 0;
    forn(i,3)
    {
        int x;
        cin >> x;
        cantCopas += x;
    }
    forn(i,3)
    {
        int x;
        cin >> x;
        cantMedallas += x;
    }
    int n;
    cin >> n;
    n -= cantCopas/5;
    if(cantCopas%5 != 0) n--;

    n -= cantMedallas/10;
    if(cantMedallas%10 != 0) n--;

    if(n >= 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
