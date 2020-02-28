#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main()
{
    int cantStrings;
    cin >> cantStrings;
    vector<string>a(cantStrings);
    forn(i,cantStrings) cin >> a[i];
    sort(a.begin(), a.end(), 
    [](string &z, string &b) -> bool
    {
        int cantS = 0, cantH = 0, cantS2 = 0, cantH2 = 0;
        forn(i,z.size())
        {
            if(z[i] == 's') cantS++;
            else cantH++;
        }
        forn(i,b.size())
        {
            if(b[i] == 's') cantS2++;
            else cantH2++;
        }

        //if(cantS2 == 0 or cantH == 0) return true; 
        //if(cantH2 == 0 or cantS == 0) return false;
        if(cantS*cantH2 > cantS2*cantH) return true; 
        return false;
    }
    );

    int cantHTotales = 0;
    forn(i,cantStrings)
        forn(j,a[i].size()) 
            if(a[i][j] == 'h') cantHTotales++;

    long long s = 0;
    forn(i,cantStrings)
    {
        forn(j,a[i].size()) 
        {
            if(a[i][j] == 's') s += cantHTotales;
            else cantHTotales--;
            //cout << s << endl;
        }
    }

    cout << s << endl;

    //forn(i,cantStrings) cout << a[i] << endl;
    
    return 0;
}