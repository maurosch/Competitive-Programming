#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
typedef pair<int,int> ii;
typedef vector<int> vi;

struct ruta
{
    int a, b, valor;
};

int padre(int a, vi &link)
{
    while(link[a] != a)
        a = link[a];
    return a;
}

void juntar(int a, int b, vi &link, vi &size)
{
    a = padre(a, link);
    b = padre(b, link);
    if(size[a] < size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;
}

bool mismoSet(int a, int b, vi &link)
{ return padre(a, link) == padre(b, link); }

bool ordPorRuta(ruta a, ruta b) { return a.valor < b.valor; }

int main()
{
    int p, r;
    cin >> p >> r;
    vector<ruta> rutas(r);
    forn(i,r)
    {
        cin >> rutas[i].a >> rutas[i].b;
        int t, d, m;
        cin >> t >> d >> m;
        rutas[i].valor = t*d-m;
    }
    
    sort(rutas.rbegin(), rutas.rend(), ordPorRuta);

    vector<int>link(r);
    vector<int>size(r, 1);
    forn(i,link.size()) link[i] = i;

    int ganancia = 0;
    vector<int>rutasUsadas;
    
    for(int i = 0; i < r; i++)
    {
        int a = rutas[i].a, b = rutas[i].b;
        if(mismoSet(a,b,link))
        {
            if(rutas[i].valor > 0)
            {
                juntar(a, b, link, size);
                ganancia += rutas[i].valor;
                rutasUsadas.push_back(i);
            }
        }
        else
        {
            juntar(a, b, link, size);
            ganancia += rutas[i].valor;
            rutasUsadas.push_back(i);
        }
    }
    cout << ganancia << endl;
    forn(i, rutasUsadas.size()) cout << rutasUsadas[i] << " ";
    return 0;
}