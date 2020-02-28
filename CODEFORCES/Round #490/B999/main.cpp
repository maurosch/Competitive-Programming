#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i++)
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(int i = 2; i <= n; i++)
    {
        //cout << n << " " << i << " "<< n%i << endl;
        if(n % i == 0)
        {
            reverse(s.begin(), s.begin()+i);
        }
    }

    cout << s << endl;

    return 0;
}