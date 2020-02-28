#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    int n;
    long long reverse, change;
    cin >> n >> reverse >> change;
    char anterior;
    int cantCeros = 0;
    string auxString;
    cin >> auxString;

    if(auxString[0] == '0') cantCeros++; 
    anterior = auxString[0];
    
    forsn(i, 1, n)
    {
        if(auxString[i] != anterior)
        {
            anterior = auxString[i];
            if(auxString[i] == '0') cantCeros++;
        }
    }

    if(cantCeros == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    if(reverse < change)
    {
        cout << ((long long)cantCeros-1) * reverse + change << endl;
    }
    else
    {
        cout << (long long)cantCeros *change << endl;
    }

    return 0;
}