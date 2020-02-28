#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
typedef vector<vector<int>> listasDeListas;
const int MAX = 50000;

int main()
{
    ofstream out("a2.in");
    forn(i,3)
    {
        out << MAX << " " << MAX-1 << endl;
        forsn(j,1,MAX)
        {
            out << j << " " << j+1 << endl;
        }
        forn(j,MAX-1)
        {
            out << j+1 << " ";
        }
        out << MAX << endl;
    }
    return 0;
}