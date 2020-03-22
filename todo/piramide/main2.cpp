#include <iostream>
#include <vector>
#include <utility>
#define forn(i, n) for(int i = 0; i < n; i++)
#define f first
#define s second
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;

int sumaRect2(ii der, int altura, int ancho, vector< vector<int> > &mapaSuma)
{
    //first  = X
    //second = Y
    //D C
    //B A
    ii D = mp(der.f-ancho, der.s-altura);
    ii C = mp(der.f, der.s-altura);
    ii B = mp(der.f-ancho, der.s);
    ii A = der;
    int resultado = 0;
    resultado += mapaSuma[A.s][A.f];
    if(B.f >= 0) resultado -= mapaSuma[B.s][B.f];
    if(C.s >= 0) resultado -= mapaSuma[C.s][C.f];
    if(D.s >= 0 and D.f >= 0) resultado += mapaSuma[D.s][D.f];
    return resultado; 
}

int main()
{
    int m, n, anchoPiramide, altoPiramide, anchoChamber, altoChamber;
    cin >> m >> n >> anchoPiramide >> altoPiramide >> anchoChamber >> altoChamber;
    vector< vector<int> >mapa(n, vector<int>(m));
    vector< vector<int> >mapaSuma(n, vector<int>(m));
    forn(i, n)
        forn(j, m)
            cin >> mapa[i][j];

    mapaSuma[0][0] = mapa[0][0];
    for(int i = 1; i < m; i++)
        mapaSuma[0][i] = mapa[0][i] + mapaSuma[0][i-1];

    for(int i = 1; i < n; i++)
        mapaSuma[i][0] = mapa[i][0] + mapaSuma[i-1][0];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            mapaSuma[i][j] = mapaSuma[i-1][j] + mapaSuma[i][j-1] + mapa[i][j] - mapaSuma[i-1][j-1];

    /*forn(i, n)
    {
        forn(j, m)
        {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    forn(i, n)
    {
        forn(j, m)
        {
            cout << mapaSuma[i][j] << " ";
        }
        cout << endl;
    }*/
    int max = 0;
    ii upPiramide;
    ii upChamber;
    for(int i = altoPiramide-1; i < mapaSuma.size(); i++)
    {
        for(int j = anchoPiramide-1; j < mapaSuma[0].size(); j++)
        {   
            int aux = sumaRect2(mp(j,i), altoPiramide, anchoPiramide, mapaSuma);
            if(aux > max)
            {
                //Buscar chamber
                for(int h = i-(altoPiramide-1)+altoChamber; h < i; h++)
                {
                    for(int k = j-(anchoPiramide-1)+anchoChamber; k < j; k++)
                    {
                        int maxAux = aux - sumaRect2(mp(k,h), altoChamber, anchoChamber, mapaSuma);
                        if(maxAux > max)
                        {
                            max = maxAux;
                            upChamber.f = h;
                            upChamber.s = k;
                            upPiramide.f = i;
                            upPiramide.s = j;
                        }
                    }
                }
            }
        }
    }
    cout << upPiramide.s+2-anchoPiramide << " " << upPiramide.f+2-altoPiramide << endl << upChamber.s+2-anchoChamber << " " << upChamber.f+2-altoChamber;

    return 0;
}
