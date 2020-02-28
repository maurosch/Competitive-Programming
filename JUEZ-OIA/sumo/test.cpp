#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define rforn(i, n) for(int i = int(n); i >= 0; i--)

int main()
{
    ofstream out("sumo.in");
    srand(time(NULL));
    out << 100000 << endl;
    forn(i, 100000)
    {
        out << rand()%1000000 << " " << rand()%1000000 << endl;
    }
    return 0;
}