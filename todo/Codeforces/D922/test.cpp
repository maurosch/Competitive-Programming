#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
const int CANT = 100000;
const int CANT2 = 10000;

static unsigned int g_seed;

// Used to seed the generator.           
inline void fast_srand(int seed) {
    g_seed = seed;
}

// Compute a pseudorandom integer.
// Output value in range [0, 32767]
inline int fast_rand(void) {
    g_seed = (214013*g_seed+2531011);
    return (g_seed>>16)&0x7FFF;
}

int main()
{
    ofstream out("a2.in");
    out << CANT << endl;
    fast_srand(time(NULL));
    //srand(time(NULL));
    forn(i, CANT)
    {
        forn(j,1)
        {
            //int random = rand()%2;
            int random = fast_rand()%2;
            if(random == 0) out << 's';
            else out << 'h';
        }
        out << endl;
    }

    return 0;
}