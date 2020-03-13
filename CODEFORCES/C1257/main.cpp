#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++)
    {
        int n;
        cin >> n;
        vector<int>counts(n+1,-1);
        int minDist = 1e8;
        for(int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            if(counts[aux] != -1)
                minDist = min(minDist, i-counts[aux]);
            counts[aux] = i;
        }
        if(minDist == 1e8)
            cout << "-1" << endl;
        else 
            cout << minDist+1 << endl;
    }
    return 0;
}