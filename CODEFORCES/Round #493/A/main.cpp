#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    int n;
    cin >> n;
    vector<int>globos(n);
    forn(i,n) cin >> globos[i];
    if(n == 1)
    { 
        cout << -1 << endl;
        return 0;
    }
    if(n == 2)
    {
        if(globos[0] == globos[1])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << 1 << endl;
    int minimo = globos[0];
    int iMinimo = 0;
    forn(i, n)
    {
        if(globos[i] < minimo)
        {
            minimo = globos[i];
            iMinimo = i;
        }
    }
    cout << iMinimo+1 << endl;

    return 0;
}