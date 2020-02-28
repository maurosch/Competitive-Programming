#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i++)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    forn(i, n) cin >> num[i];
    int cont = 0;
    int z = 0;
    for(; z < n; z++)
    {
        if(num[z] <= k)
        {
            cont++;
        }
        else break;
    }
    for(int i = n-1; i > z; i--)
    {
        if(num[i] <= k)
        {
            cont++;
        }
        else break;
    }

    cout << cont << endl;

    return 0;
}