#include <iostream>
#include <vector>
using namespace std;

///Función para realizar un movimiento (agarrar caramelos consecutivos iguales)
vector<int> sacar(vector<int> a, int pos)
{
    vector<int> s = a;

    ///Buscamos para atras y para adelante el primer y último
    ///caramelo igual que haya para removerlos
    int pos1 = pos;
    for(; pos1 > 0 and a[pos1] == a[pos]; pos1--);
    if(a[pos1] != a[pos]) pos1++;
    
    int pos2 = pos+1;
    for(; pos2 < int(a.size()) and a[pos2] == a[pos]; pos2++); 
    
    a.erase(a.begin()+pos1, a.begin()+pos2);
    return a;
}

///Función recursiva para probar todos los valores
///Guardamos el menor valor en minCambios (lo pasamos por referencia)
///y en cambios guardamos cuandos cambios va esta rama de posibilidad
///El vector "a" va cambiando a medida que se van sacando los caramelos y
///como no queremos que afecte los cambios de una rama de posibilidades
///a la otra, pasamos el vector como copia (más costoso).
///Llamamos a probar todas las posibilidades FUERZA BRUTA
void bojack(vector<int> a, int cambios, int &minCambios)
{
    if(a.size() == 0)
    {
        if(cambios < minCambios)
            minCambios = cambios;
    }
    
    for(int i = 0; i < int(a.size()); i++)
    {
        bojack(sacar(a, i), cambios+1, minCambios);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int>a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int minimo = 999999999;
    bojack(a, 0, minimo);

    cout << minimo << endl;
    return 0;
}
