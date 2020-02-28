//The Fibonacci Segment 26/12/2018
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

    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    bool nuevo = false;
    int cont = 2, contAux;
    for(int i = 2; i < nums.size(); i++)
    {
        if(nums[i] == nums[i-1]+nums[i-2])
            if(nuevo)
            {
                contAux++;
                cont = max(cont,contAux);
            }
            else 
            {
                nuevo = true;
                contAux = 3;
                cont = max(cont,contAux);
            }
        else 
            nuevo = false;
    }
    cout << cont << endl;
    return 0;
}