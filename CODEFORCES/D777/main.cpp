#define forn(i,n) for(int i = 0; i < int(n); i++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void menorIgualLex(string &a, string &b)
{
    int menorTam = min(a.size(), b.size());
    forn(i, menorTam)
    {
        if(a[i] < b[i])
            return;
        else 
            if(a[i] > b[i])
            {
                a = a.substr(0, i);
                return;
            }
    }
    if(b.size() < a.size())
        a = a.substr(0, b.size());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string>palabras(n);
    forn(i,n) 
        cin >> palabras[i];
    
    for(int i = n-2; i >= 0; i--)
        menorIgualLex(palabras[i],palabras[i+1]);

    forn(i,n)
        cout << palabras[i] << "\n";

    return 0;
}