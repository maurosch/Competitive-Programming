#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i++)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int>num(n);
    forn(i,n) cin >> num[i];

    int cantR = n/m;
    vector<int> restos(m);
    int cont = 0;

    forn(i,n)
    {
        int re = num[i]%m;
        if(restos[re] < cantR)
        {
            restos[re]++;
        } 
        else
        {
            cont++;
            num[i]++;
            i--;
        }
    }

    cout << cont << endl;
    forn(i,n)
    {
        cout << num[i] << " ";
    }
    

    return 0;
}