#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
int s;

bool check(int n1, int n2)
{
    while(n1 > 0 and n2 > 0)
    {
        if(n1 % 10 + n2 % 10 > 9) return false;
        n1 /= 10;
        n2 /= 10;
    }
    return true;
}

void recursiva(int numero, int cantNumeros, int pos, vector<int>&vacas)
{
    forsn(i, pos, vacas.size())
    {
        if(check(vacas[i], numero))
            recursiva(numero+vacas[i], cantNumeros+1, i+1, vacas);
    }

    if(cantNumeros > s)
        s = cantNumeros;
}

int main()
{
    int n;
    cin >> n;
    vector<int>vacas(n);
    forn(i,n) cin >> vacas[i];
    recursiva(0, 0, 0, vacas);
    cout << s << endl;
    return 0;
}