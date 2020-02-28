#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    int n, x, pos;
    cin >> n >> x;

    vector<int>sec = {2, 2, 1, 0, 0, 1};
    if(n % 2 == 0)
    {
        if(x == 0)
            pos = 3;
        if(x == 1)
            pos = 5;
        if(x == 2)
            pos = 1;
    }
    else
    {
        if(x == 0)
            pos = 4;
        if(x == 1)
            pos = 2;
        if(x == 2)
            pos = 0;
    }

    if(n < 6-pos)
    {
        pos += n;
    }
    else
    {
        n -= (6-pos);
        pos = n % 6;
    }
    cout << sec[pos] << endl;
    return 0;
}