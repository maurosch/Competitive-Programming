#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) return 0;

        vector<int> padres(n, -1);
        vector<int> dist(n,-1);

        forn(i,n-1)
        {
            cin >> padres[i+1];
            cin >> dist[i+1];
        }

        forn(i,n)
        {
            cout << padres[i] << " " << dist[i] << endl;
        }

        int q;
        cin >> q;
        forn(i, q)
        {
            int a, b;
            cin >> a >> b;
        }
    
    }
    return 0;
}