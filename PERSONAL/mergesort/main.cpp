#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn2(i,s,n) for(int i = int(s); i <= int(n); i++)

void mergeSortAux(int pos1, int pos2, vector<int>&a)
{
    if(pos2 == pos1) return;                         // Si solo hay un número entonces no ordenamos nada
    int mitad = (pos1+pos2)/2;                       // También podriamos haber sacado la mitad como (pos2-pos1)/2 + pos1
    mergeSortAux(pos1,mitad,a);                      // Aplicamos recursivamente el algoritmo en izquierda y derecha (Divide and Conquer)
    mergeSortAux(mitad+1,pos2,a);                   
                                                     
    vector<int>auxiliar(pos2-pos1+1);                // Arreglo auxiliar para guardar los valores
    
    int index1 = pos1, index2 = mitad+1, cont = 0;

    while(index1 <= mitad or index2 <= pos2)
    {       
        if( index2 > pos2 or (index1 <= mitad and a[index1] < a[index2]) )
        {
            auxiliar[cont] = a[index1];
            index1++;
        }
        else
        {
            auxiliar[cont] = a[index2];
            index2++;
        }
        cont++; 
    }

    forn(i, auxiliar.size()) a[pos1+i] = auxiliar[i];
}

void mergeSort(vector<int>&a)
{
    mergeSortAux(0, int(a.size()-1), a);
}

int main()
{
    vector<int>a = {3, 18, 5, 6, 7, 0, 9, 10};
    mergeSort(a);
    forn(i,a.size()) cout << a[i] << " ";
    return 0;
}