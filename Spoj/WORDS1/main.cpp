/*
https://www.spoj.com/problems/WORDS1/

*/
#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

int main()
{
    int t;
    cin >> t;
    forn(zz, t)
    {
        int n;
        cin >> n;
        vector<int> grafo(26);
        forn(i, n)
        {
            string plate;
            cin >> plate;
            grafo['a'-plate[0]]
        }

    }
    return 0;
}