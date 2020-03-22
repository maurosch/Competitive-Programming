#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i++)
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;


    vector<bool> van(s.size(), true);
    forn(i, 26)
    {
        forn(j, s.size())
        {
            if(s[j]-'a' == i)
            {  
                van[j] = false;
                k--;
                if(k == 0)
                {
                    goto terminar;
                }
            }
        }
    }

    terminar:

    string solu;
    forn(i, van.size())
    {
        if(van[i]) 
            solu += s[i]; 
    }

    cout << solu << endl;

    return 0;
}