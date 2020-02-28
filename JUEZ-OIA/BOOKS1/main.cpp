#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
typedef pair<int,int> ii;

vector<ii> armarEscritores(int cantEscribas, vector<int> &libros, long long limite)
{
    
    vector<ii>escribas;
    long long contPaginas = 0, aux1 = libros.size()-1, aux2 = libros.size()-1;
    //Reverse asi se prioriza la menor cant de hojas al primer escritor, dsp al segundo, al tercero etc.
    rforn(i,libros.size())
    {
        if(i+1 == cantEscribas-escribas.size()-1)
        {
            //Cantidad de escribas que quedaron despues del que está ahora = cantidad de libros sobrantes
            //Entonces terminar con el escritor actual y repartir lo que quedan de libros 1 a c/escritor
            if(aux1 != aux2)
            {
                escribas.pb(mp(aux1, aux2));
                aux2 = aux1;
            }
            while(aux1 >= 0)
            {
                aux1--;
                escribas.pb(mp(aux1, aux2));
                aux2 = aux1;
            }
            break;
        }
        else
        {
            if(contPaginas + libros[i] > limite)
            {
                i++;
                contPaginas = 0;
                escribas.pb(mp(aux1, aux2));
                aux2 = aux1;
            }
            else
            {
                contPaginas += libros[i];
                aux1--;
            }
        }
    }
    if(aux1 != aux2) escribas.pb(mp(aux1, aux2));
    return escribas;
}

bool sePuedeBS(int cantEscribas, vector<int> &libros, long long limite)
{
    long long contPaginas = 0;
    for(int i = 0; i < libros.size(); i++)
    {
        if(contPaginas + libros[i] > limite)
        {
            i--;
            cantEscribas--;
            contPaginas = 0;
            if(cantEscribas == 0) return false;
        }
        else
            contPaginas += libros[i];
    }
    return true;
}

vector<ii> bsFuncion(int cantEscribas, vector<int> &libros)
{
    long long hi;
    forn(i,libros.size()) hi+= libros[i];
    long long lo = *max_element(all(libros));
    while(lo < hi)
    {
        long long x = lo + (hi-lo)/2;
        if(sePuedeBS(cantEscribas, libros, x))
            hi = x;
        else
            lo = x+1;
    }
    return armarEscritores(cantEscribas, libros, lo);
}

int main()
{
    int N;
    cin >> N;
    forn(p,N)
    {
        int cantLibros, cantEscribas;
        cin >> cantLibros >> cantEscribas;
        vector<int>libros(cantLibros);
        forn(i, cantLibros)
            cin >> libros[i];
        vector<ii>escritores = bsFuncion(cantEscribas, libros);
        reverse(all(escritores));

        forn(i,escritores.size())
        {
            for(int j = escritores[i].first+1; j <= escritores[i].second; j++)
            {
                cout << libros[j] << " ";
            }
            if(i != escritores.size()-1) cout << "/ ";
        }
        cout << endl;
    }
    return 0;
}