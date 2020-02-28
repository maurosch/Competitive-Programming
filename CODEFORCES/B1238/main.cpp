#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
int main()
{
    int q;
    cin >> q;
    forn(z,q)
    {
        int n, r;
        cin >> n >> r;
        vector<int>dist(n);
        int maximo = 0;
        forn(i,n)
            cin >> dist[i];

        sort(dist.begin(), dist.end());
          
        int s = 0, push = 0;
        for(int i = dist.size()-1; i >= 0; i--)
        {
            if(push >= dist[i])
                break;
            s++;
            push += r;
            while(i > 0 and dist[i-1] == dist[i])
                i--;
        }
        cout << s << endl;
    }
    return 0;
}