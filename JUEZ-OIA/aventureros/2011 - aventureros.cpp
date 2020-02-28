//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 12/03/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://juez.oia.unsam.edu.ar/#/task/aventureros/statement
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n); i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;

const int INF = 999999999;

//--------------------Fenwick-Tree----------------------
int getFT(int b, vector<int> &FT){
   int v = 0;
   for (int x = b+1; x > 0; x -= x & -x) v += FT[x];
   return v;
}
int get(int a, int b, vector<int> &FT){
   return getFT(b, FT) - getFT(a-1, FT);
}
void updateFT(int pos, int value, vector<int> &FT) {
   for (int x = pos+1; x < int(FT.size()); x += x & -x) FT[x] += value;
}
//------------------------------------------------------

int main()
{
    ifstream in("aventureros.in");
    ofstream out("aventureros.out");
    int n;
    in >> n;
    
    if(n == 1)
    {
        //Corner Case con solo 1 persona (tramposo también porque hay que dejar una linea vacía)
        out << endl << 1;
        return 0;
    }

    int indice = 0, cont = n;
    //Usamos un árbol para guardar en 1 las personas que están en la ronda y 0 a los que se van.
    //Mediante esto podemos buscar con busqueda lineal a la siguiente persona en la ronda.
    //Esta solución es mucho más rápida que usar erase en vectores y que usar listas.
    vector<int>FT(n+1);
    forn(i,n) updateFT(i, 1, FT);

    while(cont > 1)
    {
        int q;
        in >> q;
        q++;

        //Si q > cantidad de personas en la ronda
        //con solo usar el módulo podemos dejarlo menor a la cantidad de personas.
        int sobrantes = get(indice, n-1, FT);
        if(sobrantes < q)
        {
            q -= sobrantes;
            indice = 0;

            int aux = q;
            int cantEnArreglo = get(0, n-1, FT);

            q = q % cantEnArreglo;
            if(q == 0 and aux != 0) //Caso cuando q%(multiplo de cantArreglo)=0
                q = cantEnArreglo;
        }


        //Buscamos el segundo indice mediante busqueda binaria
        int lo = indice, hi = n-1; 
        while (lo<hi)
        {
            int medio = (hi+lo)/2; 
            if(get(indice, medio, FT) < q )
                lo = medio+1; 
            else
                hi = medio; 
        }
        // hi y lo: menor numero que cumple <- el que usamos

        //ACLARACION: No utilizo la receta dada de busqueda binaria ya que tenía un problema justo con este caso
        //donde lo podía ser el número que buscaba y entonces hi nunca llegaba al valor buscado por la condicion del while.

        cout << hi+1 << " "; //+1 porque los indices en el programa empiezan en 0.
        indice = hi; 
        updateFT(indice, -1, FT);
        
        cont--;
    }

    //Buscamos el último número (Talvez hubiera sido mejor utilizar de nuevo busqueda binaria pero ya con busqueda lineal llegaba a 100p)  
    forn(i,n)
    {
        if(get(i,i, FT)==1)
        {
            cout << endl << i+1;
            return 0;
        }
    }

    return 0;
}