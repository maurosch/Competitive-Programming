#include <iostream>
#include <vector>
#include <queue>
//#include <utility>
#include <fstream>
#define For(i, n) for(int i = 0; i < n; i++)
#define rFor(i, n) for(int i = n-1; i >= 0; i--)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cout << "=================" << endl;
using namespace std;

enum room
{
    pozo,
    monster,
    tesoro,
    vacio,
};
struct nodo
{
    room habitacion;
    pair<int,int>padre = {-1,-1};
    bool visitado = false;
};

vector<int> multiBFS(vector<nodo>&grafo, int largo, int alto, int flechas, bool &encontrado)
{
    vector<int>recorrido;
    queue<pair<int,int>> cola;
    vector<vector<nodo>>gm;
    For(i, flechas+1)
    {
        gm.push_back(grafo);
    }
    if(gm[0][0].habitacion == room::pozo) return recorrido;
    else
        if(gm[0][0].habitacion == room::monster)
        {
            if(flechas == 0) return recorrido;
            else flechas--;
        }
    cola.push(make_pair(0, 0));
    gm[0][0].visitado = true;
    encontrado = false;
    pair<int,int>tesoro = {-1, -1};
    while(!cola.empty() and !encontrado)
    {
        pair<int,int> nodoActual = cola.front();
        cola.pop();
        //cout << endl;
        //RAYA
        //cout << "Piso:"<< nodoActual.second << " Lugar:" << nodoActual.first << " --> ";
        ///-----------ARRIBA-----------
        int nodoAagregar = nodoActual.first-largo;
        if(nodoAagregar > 0 and !gm[nodoActual.second][nodoAagregar].visitado)
        {
            //cout << nodoActual.first - largo << " ";
            switch(grafo[nodoAagregar].habitacion)
            {
                case room::vacio:
                    cola.push(make_pair(nodoAagregar, nodoActual.second));
                    gm[nodoActual.second][nodoAagregar].visitado = true;
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
                case room::monster:
                    if(nodoActual.second < flechas and !gm[nodoActual.second+1][nodoAagregar].visitado)
                    {
                        cola.push(make_pair(nodoAagregar, nodoActual.second+1));
                        gm[nodoActual.second+1][nodoAagregar].visitado = true;
                        gm[nodoActual.second+1][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                    }
                break;
                case room::tesoro:
                    encontrado = true;
                    tesoro = {nodoActual.second, nodoAagregar};
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
            }

        }

        ///-----------ABAJO-------------
        nodoAagregar = nodoActual.first+largo;
        if(nodoAagregar < largo*alto and !gm[nodoActual.second][nodoAagregar].visitado)
        {
            //cout << nodoActual.first + largo << " ";
            switch(grafo[nodoActual.first + largo].habitacion)
            {
                case room::vacio:
                    cola.push(make_pair(nodoAagregar, nodoActual.second));
                    gm[nodoActual.second][nodoAagregar].visitado = true;
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
                case room::monster:
                    if(nodoActual.second < flechas and !gm[nodoActual.second+1][nodoAagregar].visitado)
                    {
                        cola.push(make_pair(nodoAagregar, nodoActual.second+1));
                        gm[nodoActual.second+1][nodoAagregar].visitado = true;
                        gm[nodoActual.second+1][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                    }
                break;
                case room::tesoro:
                    encontrado = true;
                    tesoro = {nodoActual.second, nodoAagregar};
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
            }
        }
        ///-----------IZQUIERDA-------------
        nodoAagregar = nodoActual.first-1;
        if(nodoActual.first % largo != 0 and !gm[nodoActual.second][nodoAagregar].visitado)
        {
            //cout << nodoActual.first - 1 << " ";
            switch(grafo[nodoAagregar].habitacion)
            {
                case room::vacio:
                    cola.push(make_pair(nodoAagregar, nodoActual.second));
                    gm[nodoActual.second][nodoAagregar].visitado = true;
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
                case room::monster:
                    if(nodoActual.second < flechas and !gm[nodoActual.second+1][nodoAagregar].visitado)
                    {
                        cola.push(make_pair(nodoAagregar, nodoActual.second+1));
                        gm[nodoActual.second+1][nodoAagregar].visitado = true;
                        gm[nodoActual.second+1][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                    }
                break;
                case room::tesoro:
                    encontrado = true;
                    tesoro = {nodoActual.second, nodoAagregar};
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
            }
        }
        /////-----------DERECHA-------------
        nodoAagregar = nodoActual.first+1;
        if( nodoAagregar % largo != 0 and !gm[nodoActual.second][nodoAagregar].visitado)
        {
            //cout << nodoActual.first + 1 << " ";
            switch(grafo[nodoAagregar].habitacion)
            {
                case room::vacio:
                    cola.push(make_pair(nodoAagregar, nodoActual.second));
                    gm[nodoActual.second][nodoAagregar].visitado = true;
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                break;
                case room::monster:
                    if(nodoActual.second < flechas and !gm[nodoActual.second+1][nodoAagregar].visitado)
                    {
                        cola.push(make_pair(nodoAagregar, nodoActual.second+1));
                        gm[nodoActual.second+1][nodoAagregar].visitado = true;
                        gm[nodoActual.second+1][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                    }
                break;
                case room::tesoro:
                    encontrado = true;
                    gm[nodoActual.second][nodoAagregar].padre = {nodoActual.second,nodoActual.first};
                    tesoro = {nodoActual.second, nodoAagregar};
                break;
            }
        }
    }
    if(tesoro.second != -1 and tesoro.first != -1){
        recorrido.push_back(tesoro.second);
        pair<int,int> aux = gm[tesoro.first][tesoro.second].padre;
        while(aux.second != -1)
        {
            recorrido.push_back(aux.second);
            aux = gm[aux.first][aux.second].padre;
        }
    }
    return recorrido;
}




int main()
{
    ifstream in("tesoro.in");
    ofstream out("tesoro.out");
    int largo, alto, flechas;
    in >> alto >> largo >> flechas;
    vector<nodo>grafo(largo*alto);
    For(i, alto)
    {
        For(j, largo)
        {
            char letra;
            in >> letra;
            if(letra == 'W') grafo[i*largo+j].habitacion = room::monster;
            if(letra == 'P') grafo[i*largo+j].habitacion = room::pozo;
            if(letra == 'T') grafo[i*largo+j].habitacion = room::tesoro;
            if(letra == 'V') grafo[i*largo+j].habitacion = room::vacio;
        }
    }

    /*For(i, alto)
    {
        For(j, largo)
        {
            if(i*largo+j < 10) cout << "0";
            cout << i*largo+j << " ";

        }
        cout << endl;
    }*/
    if(grafo[0].habitacion == room::tesoro)
    {
        out << 1 << endl;
        out << "(0,0)";
        return 0;
    }
    bool encontrado;
    vector<int>recorrido = multiBFS(grafo, largo, alto, flechas, encontrado);
    if(!encontrado)
    {
        out << "imposible";
        return 0;
    }
    out << recorrido.size() << endl;
    rFor(i, recorrido.size())
    {
        out << "(" << recorrido[i]/largo << "," << recorrido[i]%largo << ")" << endl;
    }
    return 0;
}
