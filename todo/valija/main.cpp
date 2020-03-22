#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
typedef pair<int,int> ii;
#define f first
#define s second
const int INF = 999999999;

bool ordenarMenor(ii &a, ii &b)
{
    return a.f+a.s < b.f+b.s;
}

int main()
{
    int S, N;
    cin >> S >> N;
    vector<ii>obras(N);
    forn(i,N)
    {
        int x, z;
        cin >> x >> z;
        obras[i].f = max(x,z); 
        obras[i].s = min(x,z);
    }
    //sort(obras.begin(), obras.end(),ordenarMenor);
    /*forn(i,N) cout << obras[i].f << " " << obras[i].s << endl;
    forn(i,N)
    {
        int alto = obras[i].f, ancho = obras[i].s, espesor = 1;
        vector<ii> pesosObras(N);
        forn(j, N)
        {
            pesosObras[j].f = 
            pesosObras[j].s
        }
    }*/

    vector<int>mejorOpcion(N, -1);
    forn(i, N)
    {
        int maximo = 0;
        forn(j, N)
        {
            if(i != j)
            {
                int aux = 0;
                aux = obras[j].f + obras[j].s - (obras[i].f + obras[i].s);
                if(aux < maximo and aux > 0) //NO TOMAMOS LAS QUE SON IGUALES
                {
                    maximo = aux;
                    mejorOpcion[i] = j;
                }
            }
        }
    }

    int solucion = 0;
    forn(i, N)
    {
        int solucionAux = 0;
        int index = i;
        ii tamanio = {0,0};
        while(mejorOpcion[index] != -1)
        {
            ii tamanioAux = {max(tamanio.f,obras[mejorOpcion[index]].f), max(tamanio.s,obras[mejorOpcion[index]].s)};
            if(tamanioAux.f+tamanioAux.s+solucionAux+1 < S)
            {
                tamanio = tamanioAux;
                solucionAux++;
            }
            else
            {
                solucion = max(solucion, solucionAux);
                break;
            }
        }
    }
    cout << solucion;


    return 0;
}