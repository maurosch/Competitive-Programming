#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define pb push_back
typedef vector<vector<int>> listasDeListas;

struct materia
{
    bool ap = false, mostrada = false;
};

int update(int mat, listasDeListas &adjListSalientes, listasDeListas &adjListEntrantes, vector<materia> &aprobadas)
{
    int s = 0;
    aprobadas[mat].ap = true; 
    queue<int>cola;
    cola.push(mat);
    while(!cola.empty())
    {
        int aux = cola.front();
        cola.pop();
        if(aprobadas[aux].ap and !aprobadas[aux].mostrada)
        {
            bool noMostrar = false;
            forn(i,adjListEntrantes[aux].size())
            {
                if(!aprobadas[adjListEntrantes[aux][i]].mostrada)
                {
                    noMostrar = true;
                    break;
                }
            }
            if(!noMostrar)
            {
                aprobadas[aux].mostrada = true;
                s++;
                forn(i,adjListSalientes[aux].size())
                    cola.push(adjListSalientes[aux][i]);
            }
        }
    }
    return s;
}

int main()
{
    int N, M;
    while(!cin.eof())
    {
        cin >> N;
        if(cin.eof()) return 0;
        cin >> M;
        vector<materia>aprobadas(N);
        vector<vector<int>>adjListSalientes(N);
        vector<vector<int>>adjListEntrantes(N);
        forn(i,M)
        {
            int desde, hacia;
            cin >> desde >> hacia;
            desde--; hacia--;
            adjListSalientes[desde].pb(hacia);
            adjListEntrantes[hacia].pb(desde);
        }
        
        int s = 0;
        forn(i,N)
        {
            int materiaAprobada;
            cin >> materiaAprobada;
            materiaAprobada--;
            s += update(materiaAprobada,adjListSalientes,adjListEntrantes,aprobadas);
            cout << s << endl;
        }
    }
    return 0;
}