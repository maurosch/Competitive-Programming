#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <queue>
#include <algorithm>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define rforn(i, n) for(int i = int(n)-1; i >= 0; i--)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef vector<vector<int>> matriz;
#define x first //x
#define y second //y
const int inf = 999999999;

//Transformamos las coordenadas del enunciado del mapa 
//a nuestro tipo de coordenadas convencional

//  5 x x                           2 x x
//  3 x x                           1 x x
//  1 x x  --> transformamos a -->  0 x x
//    2 4                             0 1

int transformX2normal(int z){return z/2-1;} //TRANSFORM X TO NORMAL
int transformY2normal(int z){return (z-1)/2;} //TRANSFORM Y TO NORMAL
 
int transformX2enun(int z){return (z+1)*2;} //TRANSFORM X TO ENUNCIADO
int transformY2enun(int z){return 1+z*2;} //TRANSFORM Y TO ENUNCIADO

int main()
{
    ifstream in("protesta.in");
    ofstream out("protesta.out");
    int cantCalles, cantEsquinasCortadas;
    ii inicio, final;

    in >> cantCalles >> inicio.x >> inicio.y >> final.x >> final.y;
    inicio = {transformX2normal(inicio.x),transformY2normal(inicio.y)};
    final = {transformX2normal(final.x),transformY2normal(final.y)};
    in >> cantEsquinasCortadas;

    queue<ii>cola;
    int dimensionX = cantCalles/2;
    int dimensionY = cantCalles/2;
    if(cantCalles % 2 != 0) dimensionY++;
    //cout << "DIMEN X:" << dimensionX << " DIMEN Y:" << dimensionY << endl;
    
    vector<vector<ii>> padres(dimensionY, vector<ii>(dimensionX,{-1,-1}));
    matriz cantCurvas(dimensionY, vector<int>(dimensionX,inf));
    vector<vector<bool>> estanEnCola(dimensionY, vector<bool>(dimensionX,false));


    forn(i, cantEsquinasCortadas)
    {
        int xEsq, yEsq;
        in >> xEsq >> yEsq;
        if(xEsq <= cantCalles and yEsq <= cantCalles)
        {
            xEsq = transformX2normal(xEsq);
            yEsq = transformY2normal(yEsq);
            padres[yEsq][xEsq] = mp(-inf,-inf);
        }
    }

    cola.push(inicio);
    estanEnCola[inicio.y][inicio.x] = true;
    cantCurvas[inicio.y][inicio.x] = 0;
    vector<int>dx = {-1, 1, 0, 0};
    vector<int>dy = {0, 0, -1, 1};

    int max = 0;
    while(!cola.empty())
    {
        if(cola.size() > max)
        {
            max = cola.size();
        }
        ii aux = cola.front();
        estanEnCola[inicio.y][inicio.x] = false;
        cola.pop();

        //Vemos para las 4 posibles direcciones (para evitar repetición usamos el vector dx y dy).
        for(int i = 0; i < 4; i++)
        {
            if(aux.x+dx[i] >= 0 and aux.x+dx[i] < dimensionX and aux.y+dy[i] >= 0 and aux.y+dy[i] < dimensionY)
            {
                //Nos fijamos que la dirección que estamos y la de la calle sea igual
                
                //Si la direc es vertical y el sentido hacia abajo entonces la calle
                //en nuestro sistema de coordenadas tiene que ser multiplo de 2.
                //El mismo pensamiento se aplica para el resto de las direcciones y sentidos.
                if((aux.x % 2 == 0 and dy[i] <= 0) or ((aux.x-1) % 2 == 0 and dy[i] >= 0)) //and aux.x != 0))
                {
                    if((aux.y % 2 == 0 and dx[i] <= 0) or ((aux.y-1) % 2 == 0 and dx[i] >= 0)) //and aux.y != 0))
                    {
                        ii auxFind = {aux.x+dx[i],aux.y+dy[i]};
                        if(padres[auxFind.y][auxFind.x] != mp(-inf,-inf))
                        {
                            int hayQueDoblar = 0;

                            if(aux != inicio)
                            {
                                if(dy[i] == 0)
                                {
                                    if(padres[aux.y][aux.x].y != aux.y) hayQueDoblar = 1;
                                }
                                else
                                {
                                    if(padres[aux.y][aux.x].x != aux.x) hayQueDoblar = 1;
                                }
                            }
                            else
                                hayQueDoblar = 1;
                            
                            if((cantCurvas[aux.y][aux.x]+hayQueDoblar <= cantCurvas[aux.y+dy[i]][aux.x+dx[i]] and hayQueDoblar > 0) or (cantCurvas[aux.y][aux.x] < cantCurvas[aux.y+dy[i]][aux.x+dx[i]] and hayQueDoblar == 0))
                            {
                                cantCurvas[aux.y+dy[i]][aux.x+dx[i]] = cantCurvas[aux.y][aux.x]+hayQueDoblar;
                                padres[aux.y+dy[i]][aux.x+dx[i]] = aux;
                                if(!estanEnCola[aux.y+dy[i]][aux.x+dx[i]])
                                {
                                    cola.push( mp(aux.x+dx[i],aux.y+dy[i]) );
                                    estanEnCola[aux.y+dy[i]][aux.x+dx[i]] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "MAX:" << max << endl;
    /*rforn(i, dimensionY)
    {
        forn(j, dimensionX)
        {
            if(cantCurvas[i][j] != inf)
                cout << cantCurvas[i][j] << " ";
            else cout << "X ";
        }
        cout << endl;
    }
    cout << endl << endl;
    rforn(i, dimensionY)
    {
        forn(j, dimensionX)
        {
            if(cantCurvas[i][j] != inf)
                cout << "{" << padres[i][j].y << "," << padres[i][j].x << "} ";
            else cout << "   X  ";
        }
        cout << endl;
    }*/

    if(cantCurvas[final.y][final.x] == inf) out << 0 << endl;
    else
    {
        out << 1 << endl;

        ii solucionAux = final;
        vector<int>recorrido;
        while(padres[solucionAux.y][solucionAux.x].x != -1)
        {
            if(solucionAux.x != padres[solucionAux.y][solucionAux.x].x)
            {
                recorrido.pb(transformY2enun(solucionAux.y));
            }
            else
            {
                recorrido.pb(transformX2enun(solucionAux.x));
            }
            solucionAux = padres[solucionAux.y][solucionAux.x];
        }
  
        forn(i,recorrido.size()-1)
        {
            while(i+1 < int(recorrido.size()) and recorrido[i] == recorrido[i+1])
            {
                recorrido.erase(recorrido.begin()+i+1);
            }
        }
    
        out << recorrido.size() << endl;
        rforn(i, recorrido.size()) out << recorrido[i] << endl;
    }
    return 0;
}