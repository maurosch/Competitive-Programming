#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
struct registro
{
    int min, max, id;
    vector<int>cant;
    int hostilidad = 0, noComparable = 0;
};
int main()
{
    ifstream in("clima.in");
    ofstream out("clima.out");
    int P;
    in >> P;
    vector<registro>registros;
    forn(i, P)
    {
        int cantR;
        in >> cantR;
        int minimo = 100, maximo = -100;
        forn(j, cantR)
        {
            int aux;
            in >> aux;
            if(aux < minimo) minimo = aux;
            in >> aux;
            if(aux > maximo) maximo = aux;
        }
        //cout << minimo << " " << maximo << endl;
        bool repetido = false;
        forn(j, registros.size())
        {
            if (minimo == registros[j].min and maximo == registros[j].max)
            {
                registros[j].cant.pb(i);
                repetido = true;
                break;
            }
        }
        if(!repetido)
        {
            registro aux;
            aux.min = minimo;
            aux.max = maximo;
            aux.id = i;
            registros.pb(aux);
        }
    }
    forn(i, registros.size())
    {
        for(int j = i+1; j < registros.size(); j++)
        {
            if(j == i) continue;
            if(registros[i].max == registros[j].max)
            {
                if(registros[i].min > registros[j].min)
                {
                    registros[j].hostilidad += registros[i].cant.size()+1;
                }
                else
                {
                    if(registros[i].min < registros[j].min)
                    {
                        registros[i].hostilidad += registros[j].cant.size()+1;
                    }
                }
            }
            else
            {
                if(registros[i].min == registros[j].min)
                {
                    if(registros[i].max > registros[j].max)
                    {
                        registros[i].hostilidad += registros[j].cant.size()+1;
                    }
                    else
                    {
                        if(registros[i].max < registros[j].max)
                        {
                            registros[j].hostilidad += registros[i].cant.size()+1;
                        }
                    }
                }
                else
                {
                    if(registros[i].max > registros[j].max)
                    {
                        if(registros[i].min < registros[j].min)
                        {
                            registros[i].hostilidad += registros[j].cant.size()+1;
                        }
                        else
                        {
                            registros[j].noComparable += registros[i].cant.size()+1;
                            registros[i].noComparable += registros[j].cant.size()+1;
                        }
                    }
                    else
                    {
                        if(registros[j].min < registros[i].min)
                        {
                            registros[j].hostilidad += registros[i].cant.size()+1;
                        }
                        else
                        {
                            registros[j].noComparable += registros[i].cant.size()+1;
                            registros[i].noComparable += registros[j].cant.size()+1;
                        }
                    }
                }
            }
        }
    }
    int maxHostilidad = registros[0].hostilidad;
    forn(i, registros.size())
    {
        if(registros[i].hostilidad > maxHostilidad) maxHostilidad = registros[i].hostilidad;
    }
    vector<pair<int,int>>solucion;
    forn(i, registros.size())
    {
        if(registros[i].hostilidad == maxHostilidad)
        {
            solucion.pb(make_pair(registros[i].id, registros[i].noComparable));
            forn(j, registros[i].cant.size())
            {
                solucion.pb(make_pair(registros[i].cant[j], registros[i].noComparable));
            }
        }
    }
    sort(solucion.begin(), solucion.end());
    forn(i, solucion.size())
    {
        out << solucion[i].first+1 << " " << solucion[i].second << endl;
    }
    return 0;
}
