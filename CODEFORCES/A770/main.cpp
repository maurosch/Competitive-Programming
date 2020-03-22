#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    vector<char>alfa(26);
    forn(i,26) alfa[i] = char(int('a')+i);
    int cont = 0;
    forn(i,n)
    {
        s += alfa[cont];
        cont++;
        if(cont == 26 or cont == k) cont = 0;
    }
    cout << s << endl;
    return 0;
}