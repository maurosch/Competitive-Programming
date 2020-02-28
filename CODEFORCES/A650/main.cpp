/*
http://juez.oia.unsam.edu.ar/#/task/frutales/statement
Schiavinato Mauro
24/02/2018
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define forsn(i,s,n) for(int i = (int)(s); i < int(n); i++)
#define rforn(i,n) for(int i = (int)(n)-1; i >= 0; i--)
typedef pair<int,int> ii;

// Explicación:
// La distancia Manhattan y la distancia normal solo es igual cuando 
// las personas están en linea recta. Guardamos para cada linea la 
// cantidad de personas en esta. A partir de ese dato mediante 
// combinatoria n!/(k!*(n-k)!) podemos calcular la cantidad de pares 
// en la línea. Usamos un mapa en la implementación en vez de un arreglo
// por ser muchas líneas. La fórmula del factorial la simplificamos también
// para no tener que calcular factoriales muy grandes.
// Luego debemos restar las personas que están en el mismo punto de 
// nuevo con combinatoria.

int main()
{
    int n;
    long long s = 0;
    cin >> n;
    map<int, int>lineasX;
    map<int, int>lineasY;
    map<ii, int>personas;
    forn(i,n)
    {
        int x, y;
        cin >> x >> y;
        lineasX[x]++;
        lineasY[y]++;
        personas[{x,y}]++;
    }

    for(auto i : lineasX)
        if(i.second > 1)
            s += (long long)i.second*(i.second-1)/2;
    
    for(auto i : lineasY)
        if(i.second > 1)
            s += (long long)i.second*(i.second-1)/2;
    
    for(auto i : personas)
        if(i.second > 1)
            s -= (long long)i.second*(i.second-1)/2;
       
    cout << s << endl;
    return 0;
}