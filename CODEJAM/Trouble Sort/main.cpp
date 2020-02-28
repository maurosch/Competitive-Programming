#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0 ; i--)
const int inf = 1000000001;

int main()
{
    int t;
    cin >> t;
    forn(z,t)
    {
        cout << "Case #" << z+1 << ": ";
        int n;
        cin >> n;
        int tamanio = n/2;
        if(n%2 != 0) tamanio++;
        vector<int>vec1(tamanio);
        vector<int>vec2(tamanio);

        forn(i,n/2)
            cin >> vec1[i] >> vec2[i];

        if(n%2 != 0)
        { 
            n++;
            cin >> vec1[tamanio-1];
            vec2[tamanio-1] = inf;
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        vector<int>completo(n);
        
        int h = 0;
        for(int i = 0; i < int(vec1.size()); i++, h+=2)
        {
            completo[h] = vec1[i];
        }
        h = 1;
        for(int i = 0; i < int(vec2.size()); i++, h+=2)
        {
            completo[h] = vec2[i];
        }

        bool pasar = true;
        forn(i,completo.size()-1)
        {
            if(completo[i] > completo[i+1]) 
            {
                cout << i << endl;
                pasar = false;
                break;
            }
        }
        if(pasar) cout << "OK" << endl;
        
        /*int indexS = -1;
        forn(i,tamanio-1)
        {
            if(vec1[i] > vec2[i])
            {
                indexS = i*2;
                cout << indexS << endl;
                break;
            }
            if(vec2[i] > vec1[i+1])
            {
                indexS = i*2+1;
                cout << indexS << endl;
                break;
            }
        }*/

        /*forn(i,vec1.size()) cout << vec1[i] << " ";
        cout << endl;
        forn(i,vec2.size()) cout << vec2[i] << " ";
        cout << endl;

        if(indexS == -1)
            cout << "OK" << endl;*/
    }
    return 0;
}