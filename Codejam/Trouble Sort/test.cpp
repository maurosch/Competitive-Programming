#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0 ; i--)
const int inf = 1000000001;

int main()
{
    srand(time(NULL));
    ofstream out("a.in");
    out << 100 << endl;
    forn(i,100)
    {
        //out << 100 << endl;
        out << 3 << endl;
        forn(j,3)
            out << rand()%101 << " ";
        out << endl;
    }
    return 0;
}