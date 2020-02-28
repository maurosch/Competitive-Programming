#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

struct nodo
{
    char letra;
    bool pintado = false;
};

string solucion;

void recursiva
{

}

int main()
{
    ifstream in("repintar.in");
    ofstream out("repintar.out");
    int N;
    in >> N;
    vector<vector<nodo>> mapa(N, vector<nodo>(N));
    forn(i,N) 
        forn(j,N) 
            in >> mapa[i][j];
        
    coud << solucion.size() << endl;
    coud << solucion << endl;

    return 0;
}
