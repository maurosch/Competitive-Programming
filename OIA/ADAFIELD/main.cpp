#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm> 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;
#define all(c) (c).begin(),(c).end()
#define pb push_back

int main()
{
    int cantTests;
    cin >> cantTests;
    for(int z = 0; z < cantTests; z++)
    {    
        vector<int>ver;
        vector<int>hor;
        multiset<int, greater<int>>verticalesDist;
        multiset<int, greater<int>>horizontalesDist;
        int Q, auxVer, auxHor;
        cin >>  auxVer >> auxHor >> Q;

        ver.pb(0); ver.pb(auxVer);
        verticalesDist.insert(auxVer);
        hor.pb(0); hor.pb(auxHor);
        horizontalesDist.insert(auxHor);

        for(int h = 0; h < Q; h++)
        {
            int auxVX, numero;
            cin >> auxVX >> numero;
            if(auxVX == 0) 
            {
                //Es Vertical
                auto it = lower_bound(all(ver), numero);
                if(*it != numero)
                {
                    int distAnterior = *it - *prev(it);
                    it = ver.insert(it, numero);
                    verticalesDist.erase(verticalesDist.find(distAnterior));
                    verticalesDist.insert(*it - *prev(it));
                    verticalesDist.insert(*next(it) - *it);
                }
            }
            else
            {
                //Es horizontal
                auto it = lower_bound(all(hor), numero);
                if(*it != numero)
                {
                    int distAnterior = *it - *prev(it);
                    it = hor.insert(it, numero);
                    horizontalesDist.erase(horizontalesDist.find(distAnterior));
                    horizontalesDist.insert(*it - *prev(it));
                    horizontalesDist.insert(*next(it) - *it);
                }    
            }
            cout << (long long)*verticalesDist.begin() * *horizontalesDist.begin() << endl;
        }
    }
    return 0;
}
