//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 31/03/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://juez.oia.unsam.edu.ar/#/task/casas/statement
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;
typedef vector<vector<int>> matriz;

void recursiva(vector<vector<int>> &dp, vector<int> &conec, int numCasa, vector<int> &superficie)
{
    if(numCasa == -1) return;
    
    vector<int> superficieNueva(superficie.size());

    //Paso por todos los valores que puede tomar el frente
    forsn(i,1,superficie.size())
    {
        //Calculo cuanto espacio le dejo a la siguiente casa
        //y mediante ese valor más la superficie que tendría al tomar el largo
        //del frente "i" saco cual es el más conveniente si tuviera c-numCasa
        //siendo c:numero de casas y numCasa:la casa que estoy viendo en la función.
        int dejoAlSiguiente = conec[numCasa+1] - (conec[numCasa]+i);
        if(dejoAlSiguiente >= 1)
        {
            if(dejoAlSiguiente > int(superficie.size())-1) dejoAlSiguiente = int(superficie.size())-1;
            forn(j,dejoAlSiguiente+1)
            {
                if(superficieNueva[i] < superficie[j] + i*2 * i*2)
                {
                    superficieNueva[i] = superficie[j] + i*2 * i*2;
                    dp[i][numCasa] = j;
                }  
            }
        }
        
    }
    superficie = superficieNueva;
    recursiva(dp, conec, numCasa-1, superficie);
}

int main()
{
    ifstream in("casas.in");
    ofstream out("casas.out");
    int x, y, c;
    in >> y >> x >> c;
    vector<int>conec(c);
    forn(i,c)
        in >> conec[i];
    
    //Matriz para guardar los padres, basicamente utilizamos la altura de la matriz (el primer corchete) 
    //para el radio de la casa, el ancho de la matriz para identificar la casa y el valor para el padre
    //con el cual se saca la mayor superficie.
    matriz dp(y/2+1, vector<int>(c,-1));
    //No necesitamos una matriz de superficies ya que para sacar el óptimo hasta cada casa solo se necesita
    //saber la suma de los anteriores, entonces con solo crear un arreglo e ir modificandolo nos alcanza.
    //Nota: Sin utilizar este truquito nos tiro memory limit.
    vector<int> superficie(y/2+1);

    //Calculo para la primer casa los valores de superficie total. 
    //Este vector se inicializa para la función recursiva.
    forsn(i,1,y/2+1)
    {
        superficie[i] = min(i*2 * i*2, (x-conec[c-1])*2 * (x-conec[c-1])*2);
    }

    recursiva(dp, conec, c-2, superficie);


    //A partir de acá mediante la matriz calculamos que radio usamos para 
    //cada paso de la mejor suma de superficie. Este lo duplicamos y obtenemos el frente que necesitamos.
    //La forma para recorrer los padres es igual como para obtener el recorrido después de un BFS/Dijkstra.
    vector<int>solucion(c);
    int max = 0, padre;
    forn(i,y/2+1)
    {
        if(superficie[i] > max and conec[0]-i >= 0)
        { 
            max = superficie[i];
            padre = i;
        }
    }

    int sumaSuperficie = 0;
    forn(i,c-1)
    {
        solucion[i] = padre*2;
        sumaSuperficie += padre*2*padre*2;
        padre = dp[padre][i];
    }
    solucion[c-1] = padre*2;
    sumaSuperficie += padre*2*padre*2;

    out << sumaSuperficie << endl;
    forn(i, c)
    {
        out << solucion[i] << endl;
    }

    return 0;
}