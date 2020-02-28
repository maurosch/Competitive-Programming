#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define For(i, n) for(int i = 0; i < (int)n; i++)
#define RAYA cout << "================" << endl;
using namespace std;

struct Fecha
{
    int dia, mes,anno;
    friend bool operator<(const Fecha &a, const Fecha &b)
    {
        //SI EL PRIMERO ES MAS VIEJO ENTONCES TRUE
        if(a.anno < b.anno) return true;
        else
        {
            if(a.anno > b.anno) return false;
            else
            {
                if(a.mes < b.mes) return true;
                else
                {
                    if(a.mes > b.mes) return false;
                    else
                    {
                        if(a.dia < b.dia) return true;
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
};

class compararPair
{
public:
    bool operator() (const pair<int,int> &x, const pair<int,int> &y)
    {
        return x.first < y.first or (x.first == y.first and x.second > y.second);
    }
};

class ventana
{
public:
    ventana()
    {
        B = 0;
    }
    void avanzarB(vector<Fecha>& array, priority_queue<pair<int,int>,vector<pair<int,int>>, compararPair> &enojadosP, int &maxEnojado)
    {
        //BUSQUEDA BINARIA (LOWER BOUND)
        int a = 0, b = indices.size()-1, k;
        while(a <= b)
        {
            k = (a+b)/2;
            if (array[B] < array[indices[k]]) b = k-1;
            else a = k+1;
        }
        while(k < indices.size() and !(array[B] < array[indices[k]])) k++;
        //===============================

        if(indices.size() > 0 and k < indices.size() and array[B] < array[indices[k]])
        {
            enojadosP.push(make_pair(B - indices[k], B+1));
            maxEnojado = max(B - indices[k], maxEnojado);
        }

        if(indices.size() == 0) indices.push_back(B);
        else
        {
            if(array[indices.back()] < array[B])
            {
                indices.push_back(B);
            }
        }
        B++;
    }
private:
    deque<int>indices;
    int B;
};

int fila(vector<Fecha> orden, vector<int> &enojados)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, compararPair> enojadosP;
    int maxEnojo = 0;
    ventana window;
    For(i, orden.size()) window.avanzarB(orden, enojadosP, maxEnojo);
    while(!enojadosP.empty())
    {
        enojados.push_back(enojadosP.top().second);
        enojadosP.pop();
    }
    return maxEnojo;
}
