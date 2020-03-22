#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<bool>a(n);
    forn(i, n/2)
    {
        int z;
        cin >> z;
        a[z-1] = 1;
    }
    int index2=0, s=0;
    forn(i,n)
    {
        if(a[i] == 1)
        {
            //cout << i << " " << index2;
            int dif = i - index2;
            if(dif < 0) dif *= -1;
            s += dif;
            index2+=2;
        }
    }

    index2=1;
    int s2=0;
    forn(i,n)
    {
        if(a[i] == 1)
        {
            int dif = i - index2;
            if(dif < 0) dif *= -1;
            s2 += dif;
            index2+=2;
        }
    }
    //cout << s << endl << s2 << endl;
    cout << min(s, s2);
    return 0;
}