#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n); i >= 0; i--)
using namespace std;



int main()
{
    ofstream out("casas.in");
    out << "40 5000000" << endl << "200000" << endl;
    
    int cont = 2;
    forn(i, 200000)
    {
        out << cont << endl;
        cont+=5;
    }
    return 0;
}