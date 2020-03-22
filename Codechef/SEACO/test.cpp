#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define size(a) int((a).size())
using namespace std;

int main()
{
    ofstream out("a.in");
    out << 1 << endl;
    forn(i,1)
    {
        out << 1000 << " " << 1000 << endl;
        out << "1 1 1000" << endl;
        forsn(j,1, 1000)
        {
            out << "2 1 " << j << endl;
        }
    }
    return 0;
}