#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0 ; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
typedef vector<vector<int>> matriz;

int main()
{
    ofstream out("latas2.in");
    out << 1000 << endl;
    forsn(i,1,1001)
    {
        forn(j,i)
        {
            out << 1 << " ";
        }
        out << endl;
    }
    return 0;
}