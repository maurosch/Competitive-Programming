#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;
typedef pair<int,int> ii;

int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<int> > grafo(n);
    vector<int> entrantes(n);
    vector<ii> edges(m);
    forn(i,m)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        grafo[x].push_back(y);
        entrantes[y]++;
    }
    // entrada del grafo, donde las aristas son dirigidas (importa el orden). Digamos que hay n nodos
    // entrantes[i] me dice cuántas aristas entran al nodo i
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> toposort;
    forn(i, n)
        if(entrantes[i]==0) //no tengo ninguna restricción, puede ir al principio
            q.push(i);

    while(!q.empty()){
        int nodoActual = q.top();
        cout << nodoActual << endl;
        q.pop();
        toposort.push_back(nodoActual); //si lo agregue es porque no tenia mas restricciones
        for(auto vecino : grafo[nodoActual]){
            entrantes[vecino]--;
            if(entrantes[vecino]==0)
                q.push(vecino);
        }
    }
    if(toposort.size()<n){ // si hay un ciclo, nunca voy a agregar a los nodos del ciclo porque ninguno va a ser el primero en quedarse sin aristas entrantes
        cout << "Sandro fails." << endl;
    }else{
        for(int i=0; i<n; i++){
            cout << toposort[i]+1 << " ";
        }
    }
}