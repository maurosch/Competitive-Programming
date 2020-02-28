//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 10/03/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: https://www.codechef.com/problems/SEACO
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
//#define size(a) int((a).size())
using namespace std;

//Por el enunciado aplicamos modulo 10^9+7 al guardarlos.
//"As the numbers can be quite large, print them modulo 10^9 + 7"
const int NM = 1000000007;

//Estructura en vez de tuple por ser más fácil de usar
struct comando
{
    int operacion, indexI, indexF;
};

//----------------FENWICK TREE RANGE UPDATES SINGLE QUERIES----------------
void updateFT(int pos, long long value, vector<long long> &FT) {
   for (int x = pos+1; x < int(FT.size()); x += x & -x) FT[x] += value;
}
long long getFT(int b, vector<long long> &FT){
   long long v = 0;
   for (int x = b+1; x > 0; x -= x & -x) v += FT[x];
   return v;
}
long long get(int a, int b, vector<long long> &FT){
   return getFT(b, FT) - getFT(a-1, FT);
}
//----------FENWICK TREE MODIFICACION *RANGE UPDATES-POINT QUERIES*----------
void updateRangeFT(int pos1, int pos2, long long value, vector<long long> &FT)
{
    updateFT(pos1, value, FT);
    updateFT(pos2+1, -value, FT);
}
//---------------------------------------------------------------------------

int main()
{
    int numberTest;
    cin >> numberTest;
    forn(z, numberTest)
    {
        int n, m;
        cin >> n >> m;
        //Arreglo para guardar los la diferencia entre cada numero consecutivo, 
        //así al tenes que aumentar el valor en un rango, 
        //solo actualizamos el inicio del rango y el final en vez de todo el arreglo 
        //Aca guardamos los valores del arreglo con diferenciales ya que 
        //no los necesitamos hasta el final
        vector<long long>diffArray(n);

        vector<comando>comandos(m);
        forn(i, m)
        {
            cin >> comandos[i].operacion >> comandos[i].indexI >> comandos[i].indexF;
            comandos[i].indexI--;
            comandos[i].indexF--;
        }

        //Creamos una especie de "multiplicador" para cada comando, 
        //que nos dice cuantas veces tenemos que ejecutar dicho comando,
        //entonces recorremos los comandos del último al primero ya que los comandos de abajo llaman a los de arriba.
        //Al toparnos con un comando que llama a multiples comandos tendremos que sumar el multiplicador en un rango.
        //Ya que hay que sumar en un rango y después averiguar el valor en un punto (para ver cuanto es el multiplicador en tal comando)
        //utilizo el fenwick-tree modificado para RANGE UPDATES y POINT QUERIES lo cual es una modificación mínima (4 lineas <3).
        vector<long long> FT(m+1);
        updateRangeFT(0, m-1, 1, FT);

        rforn(i, m)    
        {
            if(comandos[i].operacion == 1)
            {
                //Suma en un rango
                long long cuantoSumar = getFT(i, FT);
                diffArray[comandos[i].indexI] += cuantoSumar;
                if(comandos[i].indexF+1 < int(diffArray.size())) 
                    diffArray[comandos[i].indexF+1] -= cuantoSumar;

            }
            else
            {
                //Sumar Multiplicador en un rango
                long long cuantoSumar = getFT(i, FT);
                if(cuantoSumar >= NM) cuantoSumar %= NM;
                updateRangeFT(comandos[i].indexI, comandos[i].indexF, cuantoSumar, FT);//%NM, FT);
            }
        }

        //------------MOSTRAR NUMEROS DEL ARREGLO DE DIFERENCIALES------------
        long long numeroAux = 0;
        forn(i,n)
        {
            numeroAux = numeroAux + diffArray[i];
            cout << numeroAux%NM<< " ";
        }
        cout << endl;
    }

    return 0;
}