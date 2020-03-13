#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++)
    {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int>show(n);
        for(int i = 0; i < n; i++)
            cin >> show[i]; 
        unordered_map<int,int> mapa;
        int cantDif = 0;
        for(int i = 0; i < d; i++)
        {
            mapa[show[i]]++;
            if(mapa[show[i]] == 1)
                cantDif++;
        }
        int minCantDif = cantDif;
        for(int i = d; i < show.size(); i++)
        {
            int rm = i-d;
            int add = i;
            mapa[show[add]]++;
            mapa[show[rm]]--;
            if(mapa[show[rm]] == 0)
                cantDif--;
            if(mapa[show[add]] == 1)
                cantDif++;
            minCantDif = min(minCantDif, cantDif);   
        }
        cout << minCantDif << endl;
    }
    return 0;
}