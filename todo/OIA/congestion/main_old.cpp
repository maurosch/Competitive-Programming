#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<vector<int>> matriz;
#define f first
#define s second
#define pb push_back
const int INF = 999999999;

void djs(vector<vector<ii>> &adjList, int inicio, int fin, matriz &contador)
{
    vector<int>distancias(adjList.size(),INF);
    vector<bool>visitados(adjList.size(),false);
    vector<int>padres(adjList.size(),-1);
    distancias[inicio] = 0;
    queue<int>cola;
    cola.push(inicio);
    while(!cola.empty())
    {
        int actual = cola.front();
        cola.pop();
        visitados[actual] = true;
        forn(i,adjList[actual].size())
        {
            int vecino = adjList[actual][i].f;
            if(distancias[vecino] > distancias[actual] + adjList[actual][i].s)
            {
                distancias[vecino] = distancias[actual] + adjList[actual][i].s;
                padres[vecino] = actual;
            }
            if( !visitados[vecino] )
                cola.push(vecino);
            else
            {
                if(vecino == fin)
                    goto terminado;
            }
        }
    }
terminado:
    //Recorrer camino
    int padreAux = fin;
    while(padres[padreAux] != -1)
    {
        contador[padres[padreAux]][padreAux]++;
        padreAux = padres[padreAux];
    }
   
}

int main()
{
    int cantCiudades, cantRutas;
    ifstream in("congestion.in");
    ofstream out("congestion.out");
    in >> cantCiudades >> cantRutas;
    vector<vector<ii>>adjList(cantCiudades);
    matriz rutas(cantRutas, vector<int>(cantRutas,-1));

    if(cantCiudades == 1)
    {
        //Caso extremo
    }

    forn(i,cantRutas)
    {
        
        ii aux;
        int auxCiudad;
        in >> auxCiudad; //Ciudad salida
        in >> aux.f; //Ciudad llegada
        in >> aux.s; //Peso de camino
        aux.f--; auxCiudad--;
        adjList[auxCiudad].pb(aux);
        rutas[auxCiudad][aux.f] = i+1;
    }
    matriz contador(5001, vector<int>(5001,0));

    forn(i, cantCiudades)
        forn(j, cantCiudades)
            if(i != j) djs(adjList, i, j, contador);

    /*forn(i, cantCiudades)
    {
        forn(j, cantCiudades)
                cout << contador[i][j] << " ";
        cout << endl;        
    }*/

    int max = -1;
    forn(i, cantCiudades)
        forn(j, cantCiudades)
            if(contador[i][j] > max)
                max = contador[i][j];

    vector<int>solucion;
    forn(i, cantCiudades)
        forn(j, cantCiudades)
            if(contador[i][j] == max)
                solucion.pb(rutas[i][j]);
    
    out << solucion.size() << " " << max << endl;
    forn(i, solucion.size()) out << solucion[i] << " ";
 

    return 0;
}