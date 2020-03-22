//Little Pony and Sort by Shift 26/12/2018
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    int n;
    cin >> n;
    vector<int>nums(n);
    forn(i,n) cin >> nums[i];
    bool bajo = false;
    int indiceBajo = n-1;
    forn(i,n-1)
    {
        if(nums[i+1] < nums[i])
        {
            if(bajo)
            {
                cout << -1 << endl;
                return 0;
            }
            bajo = true;
            indiceBajo = i;
        }
    }
    if(bajo and nums[0] < nums[n-1])
    {
        cout << -1 << endl;
        return 0;
    }

    else cout << n-indiceBajo-1 << endl;
    return 0;
}