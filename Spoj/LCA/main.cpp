#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
int main()
{
    int t;
    cin >> t;
    forn(z, t)
    {
        cout << "Case " << z+1 << ":" << endl;
        int n;
        cin >> n;
        vector<int>grafo(n, -1);
        forn(i, n)
        {
            int m;
            cin >> m;
            forn(j, m)
            {
                int hijo;
                cin >> hijo;
                grafo[hijo-1] = i;
            } 
        }
        /*forn(i, grafo.size())
        {
            cout << i << ":";
            forn(j, grafo[i].size())
            {
                cout << grafo[i][j] << " ";
            }
            cout << endl;    
        }*/

        int q;
        cin >> q;
        forn(i, q)
        {
            int v, w;
            cin >> v >> w;
            v--; w--;

            //Camino V
            vector<int>caminoV;
            int ultimaAgregada = v;
            while(ultimaAgregada != -1)
            {
                caminoV.push_back(ultimaAgregada);
                ultimaAgregada = grafo[ultimaAgregada];
            }

            //Camino W
            vector<int>caminoW;
            ultimaAgregada = w;
            while(ultimaAgregada != -1)
            {
                caminoW.push_back(ultimaAgregada);
                ultimaAgregada = grafo[ultimaAgregada];
            }

            //Buscamos el menor descendiente recorriendolo de atras para adelante
            int index1 = int(caminoV.size()-1), index2 = int(caminoW.size()-1);
            while(index1-1 >= 0 and index2-1 >= 0 and caminoV[index1-1] == caminoW[index2-1])
            {
                index1--;
                index2--;
            }

            cout << caminoV[index1]+1 << endl;
        }
        

    }
    return 0;
}