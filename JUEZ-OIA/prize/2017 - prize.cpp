//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 25/03/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://ioinformatics.org/locations/ioi17/contest/day2/prize/prize-ARG.pdf
//------------------------------------------------------
//----------------------------------
//--------------------
//---------

//Puntaje: 97.2
//Por la restricción de que un premio t debía ser mayor a la cantidad de premios t-1,
//se llega a la conclusión de que casi la totalidad de los premios es solo 1 tipo de premio
//y es el de menor valor. Llegado a esto, podemos aplicar busqueda binaria pero en vez de 
//buscar un solo valor, buscamos todos los que son de mayor valor al peor de todos.

//Como sabemos que no estamos parados cuando llamamos a la función "ask" en uno de mayor
//valor que el peor? 
//Para esto podemos sacar una especie de id de premio que se forma de la suma de la derecha 
//más la izquierda. Precalculamos este id para el peor premio antes de la busqueda binaria.

#include "prize.h"
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

int encontrar(int indexI, int indexF, int cantIzq, int cantDer, int idMayor)
{
	//La busqueda se va haciendo recursivamente diviendo el arreglo en 2 en cada profundidad
	//y solo se divide y se continua si sobre ese rango hay mejores premios.

    if(indexI > indexF) return -1;

    int medio = (indexI + indexF)/2;
    int indexI2 = medio, indexF2 = medio;

	//Cuando nos paramos en el medio, tenemos que verificar que estemos en el peor premio
	//si llegasemos a no estarlo, entonces nos moveriamos para izquierda y derecha cada indice
    
    int solucion;
    auto sIzq = ask(medio);
    auto sDer = sIzq;
    if(sIzq[0]+sIzq[1] == 0) return indexF2;
    if(indexI == indexF) return -1;

    while(sIzq[0]+sIzq[1] != idMayor and indexI+1 < indexF2)
    {
        indexF2--;
        sIzq = ask(indexF2);
        if(sIzq[0]+sIzq[1] == 0) return indexF2;
    }
    indexF2--;

	//Podemos saber cuantos premios menores hay en un rango de i a j mediante ask(j)[0]-ask(i)[0]
	//solo si en los 2 indices está el peor premio
	//Nuestro ask(j)[0] para no recalcularlo lo pasamos en la funcion y si 
	//en el rango que vamos a calcular no hay premios menores entonces no seguimos por ahí.
    if(cantIzq != sIzq[0]) 
    {
        solucion = encontrar(indexI, indexF2, cantIzq, sIzq[1], idMayor);    
        if(solucion != -1) return solucion;
    }

    while(sDer[0]+sDer[1] != idMayor and indexI2+1 < indexF)
    {
        indexI2++;
        sDer = ask(indexI2);
        if(sDer[0]+sDer[1] == 0) return indexI2;
    }
    indexI2++;
    if(cantDer != sDer[1])
        return encontrar(indexI2, indexF, sDer[0], cantDer, idMayor);

    return -1;
}

int find_best(int n)
{
    int idMayor = 0;
    //450 = Aproximadamente máximo numero de menores premios comparados al peor premio
    forn(i,min(n,450)) 
    {
        auto s = ask(i);
        if(idMayor < s[0]+s[1]) idMayor = s[0]+s[1]; 
    }
    return encontrar(0, n-1, 0, 0, idMayor);
}
