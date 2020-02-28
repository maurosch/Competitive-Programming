#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <time.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n); i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main()
{
    srand(time(NULL));
    ofstream out("aventureros.in");
    out << 400000 << endl;
    forn(i, 400000-1)
    {
        out << rand()%100000001 << " ";
    }
    return 0;
}