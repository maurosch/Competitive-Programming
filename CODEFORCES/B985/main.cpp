#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    forn(i, n)
    {
        string aux;
        cin >> aux;
        forn(j, m)
            a[i][j] = aux[j] - '0';
    }


    vector<int>suma(m);
    forn(i, n)
    {
        forn(j, m)
        {
            suma[j] += a[i][j];
        }
    }

    /*forn(j, m)
    {
        cout << suma[j] << " ";
    }
    cout << endl;*/
    
    forn(i, n)
    {
        vector<int>aux = suma;
        bool rep = true;
        forn(j, m)
        {
            if(a[i][j] == 1 and suma[j] == 1)
            {
                rep = false;
                break;
            }
        }
        if(rep)
        {
            cout << "YES" << endl;
            return 0;
        }
    }


    /*forn(i, n)
    {
        bool rep = true;
        forn(j, m)
        {
            int aux = 0;
            if(a[i][j] == 1)
            {
                forn(h, n)
                {
                    aux += a[j][h];
                }
                if(aux == 1) 
                {
                    rep = false;
                    break;
                }
            }
        }
        if(rep)
        {
            cout << "YES" << endl;
            return 0;
        }
    }*/

    cout << "NO" << endl;


    return 0;
}