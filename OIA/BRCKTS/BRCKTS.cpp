//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - Escuela Philips - 14/03/2018
//C++14 - Visual Studio Code - ArchLinux 
//Problema: http://www.spoj.com/problems/BRCKTS/
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = s; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

//--------SEGMENT TREE MODIFICADO PARA PROBLEMA-------- 
//-------------------*1-BASED-INDEX*-------------------
struct nodo
{
    //pa:Parentesis abiertos que no encontraron pareja --> (  
    //pc:Parentesis cerrados que no encontraron pareja --> )
    int pa = 0, pc = 0;
};
int siguientePotencia2(int n)
{
    int s = 2;
    for(;s < n; s <<= 1);
    return s; 
}
void startST(vector<nodo>&ST)
{
    //Función para empezar el ST y que los padres tomen valores:
    //Todo el árbol está en 0 menos la parte del arreglo original.
    int indexStartOriginalArray = int(ST.size())/2;
    for(int i = indexStartOriginalArray-1; i >= 1; i--)
    {
        int aux = ST[i*2].pa-ST[i*2+1].pc;
        if (aux < 0) aux = 0;
        ST[i].pa = ST[i*2+1].pa + aux;

        aux = ST[i*2+1].pc-ST[i*2].pa;
        if (aux < 0) aux = 0;
        ST[i].pc = ST[i*2].pc + aux;
    }

}
void changeBracket(int pos, vector<nodo>&ST)
{  
    int indexStartOriginalArray = int(ST.size())/2;
    pos += indexStartOriginalArray;

    //Actualizamos el nodo básico/primario
    if(ST[pos].pa == 0)
    {
        ST[pos].pa = 1;
        ST[pos].pc = 0;
    }
    else
    {
        ST[pos].pa = 0;
        ST[pos].pc = 1;
    }

    //Actualizamos los padres
    pos/=2;
    for(;pos >= 1;pos/=2)
    {
        //El nodo padre tiene que tener los parentesis abiertos del nodo de la derecha
        //más los parentesis abiertos del nodo de la izquiera que NO encuentran pareja 
        //con los de la derecha.
        int aux = ST[pos*2].pa-ST[pos*2+1].pc;
        if (aux < 0) aux = 0;
        ST[pos].pa = ST[pos*2+1].pa + aux;

        //Y tiene que tener los parentesis cerrados del lado izquierdo
        //más los parentesis cerrados del lado de la derecha que NO encuentran pareja
        //con los de la izquierda.
        aux = ST[pos*2+1].pc-ST[pos*2].pa;
        if (aux < 0) aux = 0;
        ST[pos].pc = ST[pos*2].pc + aux;
    }
}
//-----------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    forn(z, 10)
    {
        int n;
        cin >> n;
        
        vector<nodo>ST(siguientePotencia2(n)*2+1);
        //A pesar de 'n' no ser potencia de 2, siempre generamos un árbol perfecto 
        //llenado de 0 los valores sin usar.

        int indexStartOriginalArray = int(ST.size())/2;
        forn(i,n)
        {
            char aux;
            cin >> aux;
            if(aux == '(')  ST[indexStartOriginalArray+i].pa = 1;
            else ST[indexStartOriginalArray+i].pc = 1;
        }

        startST(ST);
        cout << "Test " << z+1 << ":\n";

        int q;
        cin >> q;
        forn(i,q)
        {
            int operacion;
            cin >> operacion;
            if(operacion == 0)
            {
                if(ST[1].pa == 0 and ST[1].pc == 0) cout << "YES\n";
                else cout << "NO\n";
            }
            else
            {
                operacion--;
                changeBracket(operacion, ST);
            }
        }
    }
    return 0;
}