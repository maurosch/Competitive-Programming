//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 25/02/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://juez.oia.unsam.edu.ar/#/task/sumo/statement
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define rforn(i, n) for(int i = int(n)-1; i >= 0; i--)
const int maxFT = 1000000;

//--------------------FENWICK TREE-----------------------
int getFT(int b, vector<int> &FT){
    int v = 0;
    for (int x = b+1; x > 0; x -= x & -x) v += FT[x];
    return v;
}
//DEVUELVE QUERY ENTRE A Y B
int get(int a, int b, vector<int> &FT){
    return getFT(b, FT) - getFT(a-1, FT);
}
//INCREMENTA EN 1 EL VALOR DEL ARREGLO EN POS
void updateFT(int pos, int value, vector<int> &FT) {
    for (int x = pos+1; x < int(FT.size()); x += x & -x) FT[x] += value;
}
//-------------------------------------------------------

struct luchador
{
    int altura, peso, id;
};

//Funcion para el sort de c++
bool ordenarLuchador(luchador a, luchador b)
{
    return (a.altura > b.altura or (a.altura == b.altura and a.peso > b.peso));
}

int main()
{
    ifstream in("sumo.in");
    ofstream out("sumo.out");
    int cant;
    in >> cant;
    vector<luchador>luchadores(cant);
    vector<int>solucion(cant);
    
    forn(i, cant)
    {
        in >> luchadores[i].peso >> luchadores[i].altura;
        luchadores[i].id = i;
    }

    //Ordenamos por altura así solo nos va a importar el peso
    sort(luchadores.begin(), luchadores.end(), ordenarLuchador);

    vector<int> ft(maxFT+2);

    //Vamos de atrás para adelante ya que los únicos que nos importan
    //son los que están debajo en el vector (los de menor altura).
    //Mediante una estructuca (árbol) vamos agregando los luchadores de menor a mayor altura
    //y en cada uno nos fijamos los que ya agregamos al árbol y tengan menor peso (range query), 
    //así teniendo el número de a quienes domina.
    rforn(i, cant)
    {
        solucion[luchadores[i].id] = get(0, luchadores[i].peso, ft);
        updateFT(luchadores[i].peso, 1, ft);
    }

    forn(i, cant)
        out << solucion[i] << endl;


    //Queda la duda si se podría realizar el problema con una matriz 
    //donde cada luchador es un punto y luego mediante 
    //una tabla aditiva sabriamos a cuantos domina cada luchador. 
    //El problema estaría en las cotas del input que son muy grandes,
    //aunque seguramente haya una forma de tratar esa limitación.

    return 0;
}