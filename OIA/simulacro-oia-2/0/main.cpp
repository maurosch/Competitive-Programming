#include <iostream>
#include <vector>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>fardos(n);
    int suma = 0;
    forn(i,n)
    { 
        cin >> fardos[i];
        suma += fardos[i];
    }
    int cantF = suma/n;
    int s = 0;
    forn(i,n)
        if(fardos[i] > cantF) 
            s += fardos[i]-cantF;
    
    cout << s << endl;
    return 0;
}