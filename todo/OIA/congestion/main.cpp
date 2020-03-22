#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
typedef pair<int,int> ii;
typedef vector<vector<int>> matriz;
#define f first
#define s second
#define pb push_back
const int INF = 999999999;

int main()
{
    int cantCiudades, cantRutas;
    ifstream in("congestion.in");
    ofstream out("congestion.out");
    in >> cantCiudades >> cantRutas;
    

    if(cantCiudades == 1)
    {
        //Caso extremo
    }

    matriz numTramo(cantCiudades, vector<int>(cantCiudades, INF));
    matriz rutas(cantCiudades, vector<int>(cantCiudades, INF));
    matriz padres(cantCiudades, vector<int>(cantCiudades, INF));
    matriz cant(cantCiudades, vector<int>(cantCiudades, 0));

    //cout<<"1"<<endl;

    forn(i,cantRutas)
    {
        int ciudadSalida, ciudadLlegada, peso;
        in >> ciudadSalida >> ciudadLlegada >> peso;
       
        if(peso < rutas[ciudadSalida-1][ciudadLlegada-1])
        {
            numTramo[ciudadSalida-1][ciudadLlegada-1] = i+1;
            rutas[ciudadSalida-1][ciudadLlegada-1] = peso;
            padres[ciudadSalida-1][ciudadLlegada-1] = ciudadLlegada-1;
        }
    }

    //cout<<"2"<<endl;

    /*forn(i, cantCiudades)
        forn(j,cantCiudades)
            if(i == j) rutas[i][j] = 0;*/

    //cout<<"3"<<endl;
    
    forn(i,cantCiudades)
    {
        forn(j,cantCiudades)
        {
            forn(k,cantCiudades)
            {
                if(i != j and rutas[i][j] > rutas[i][k] + rutas[k][j])
                {
                    rutas[i][j] = rutas[i][k] + rutas[k][j];
                    padres[i][j] = padres[i][k];
                }
            }
        }
    }

    //cout<<"4"<<endl;

    forn(i,cantCiudades)
    {
        forn(j,cantCiudades)
        {
            if(i != j)
            {
                vector<int>path;
                path.push_back(i);
                int desde = i;
                while(desde != j)
                {
                    desde = padres[desde][j];
                    path.push_back(desde);
                }
                forn(z,path.size()-1)
                    cant[path[z]][path[z+1]]++;
            }
        }
    }

    //cout<<"5"<<endl;
    
    /*cout << "================DIST===============" << endl;
    forn(i,cantCiudades)
    {
        forn(j,cantCiudades)
        {
            cout << rutas[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===================================" << endl;
    cout << "==============PADRES===============" << endl;
    forn(i,cantCiudades)
    {
        forn(j,cantCiudades)
        {
            cout << padres[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===================================" << endl;
    cout << "================CANT===============" << endl;
    forn(i,cantCiudades)
    {
        forn(j,cantCiudades)
        {
            cout << cant[i][j] << " ";
        }
        cout << endl;
    }
    cout << "==============N.TRAMO=============" << endl;
    forn(i,cantCiudades)
    {
        forn(j,cantCiudades)
        {
            cout << numTramo[i][j] << " ";
        }
        cout << endl;
    }*/

    int max = 0;
    forn(i,cantCiudades)
        forn(j,cantCiudades)
            if(cant[i][j] > max) max = cant[i][j];

    vector<int>tramosEmpatados;
    forn(i,cantCiudades)
        forn(j,cantCiudades)
            if(cant[i][j] == max) tramosEmpatados.push_back(numTramo[i][j]);

    cout << tramosEmpatados.size() << " " << max << endl;
    forn(i,tramosEmpatados.size()) cout << tramosEmpatados[i] << " ";

    return 0;
}