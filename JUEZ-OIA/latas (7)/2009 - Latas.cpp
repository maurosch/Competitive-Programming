//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 29/04/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://juez.oia.unsam.edu.ar/#/task/latas/statement
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0 ; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
typedef vector<vector<int>> matriz;

void mostrarMatriz(matriz &a)
{
    cout << "--------------------------------" << endl;
    forn(i,a.size())
    {
        forn(j,a.size())
        {
            if(a[i][j] < 10) cout << " ";
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

void mostrarAlRevesMatriz(matriz &a)
{
    cout << "--------------------------------" << endl;
    rforn(i,a.size())
    {
        forn(j,a.size())
        {
            if(a[i][j] < 10) cout << " ";
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

int main()
{
    /*
    Complejidad: n^2
    Realizamos una tabla aditiva en diagonal, guardando en cada
    celda el valor de la que tiene en diagonal abajo izquierda + el valor de la celda
    del enunciado. Generamos dos tablas aditivas más pero estas
    arriba de la tabla aditiva diagonal: 
    una la hacemos horizontal (c/celda guarda el valor de la izq + el valor) 
    y la otra vertical (c/celda guarda el valor de arriba + el valor)
    Cada tabla cuesta n^2 de complejidad.
    Luego para calcular el triángulo con un simple calculo:
    (sH[i][j+n-1] - sH[i][j-1]) - (sV[i+n][j-1] - sV[i][j-1])
    Entonces calcular el triangulo con mayor valor cuesta n^2.
    Entonces el programa termina haciendo al rededor de: 5*n^2
    Mucho mejor que la complejidad de calcular a mano de (1/2)*n^4
    */
    ifstream in("latas.in");
    ofstream out("latas.out");
    int n, tamanio;
    in >> n;
    tamanio = 2*n;
    vector<vector<int>>mapa(tamanio,vector<int>(tamanio));
    
    vector<vector<int>>sumaDiagonal(tamanio+2,vector<int>(tamanio+2));
    vector<vector<int>>sumaHorizontal(tamanio+2,vector<int>(tamanio+2));
    vector<vector<int>>sumaVertical(tamanio+2,vector<int>(tamanio+2));
    int sumaTotal = 0;
    forn(i,n)
    {
        forn(j,i+1)
        {
            in >> mapa[i][j];
            sumaTotal += mapa[i][j];
        }
    }

    rforsn(i,1,tamanio+1)
    {
        forsn(j,1,tamanio+1)
        {
            sumaDiagonal[i][j] = sumaDiagonal[i+1][j-1] + mapa[i-1][j-1];
        }
    }

    forsn(i,1,sumaVertical.size())
    {
        forsn(j,1,sumaVertical.size())
        {
            sumaVertical[i][j] = sumaVertical[i-1][j] + sumaDiagonal[i][j];
        }
    }

    forsn(i,1,sumaVertical.size())
    {
        forsn(j,1,sumaVertical.size())
        {
            sumaHorizontal[i][j] = sumaHorizontal[i][j-1] + sumaDiagonal[i][j];
        }
    }

    /*mostrarMatriz(mapa);
    cout << "SUMA DIAGONAL";
    mostrarMatriz(sumaDiagonal);
    cout << "SUMA VERTICAL";
    mostrarMatriz(sumaVertical);
    cout << "SUMA HORIZONTAL";
    mostrarMatriz(sumaHorizontal);*/

    int maximo = 0;
    forsn(i,1,tamanio-n+1)
    {
        forsn(j,1,tamanio-n+1)
        {
            //cout << "----------------------------------" << endl;
            //cout << "i:" << i << " j:" << j << " n:"<< n << endl;
            //cout << " sV:" << sumaVertical[i+n][j-1] << " y " << sumaVertical[i][j-1] << " - sH:" << sumaHorizontal[i][j+n-1] << " y " << sumaHorizontal[i][j-1];
            int aux = (sumaHorizontal[i][j+n-1] - sumaHorizontal[i][j-1]) - (sumaVertical[i+n][j-1] - sumaVertical[i][j-1]);
            //cout << " f:" << aux << endl;
            maximo = max(aux, maximo);
        }
    }

    //cout << sumaTotal << endl;
    //cout << maximo << endl;
    out << sumaTotal - maximo << endl;

    return 0;
}