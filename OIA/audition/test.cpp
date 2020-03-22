#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream out("a.in");
    out << 10 << endl;
    forn(i, 10)
    {
        out << 1000000 << " " << 1000000 << endl;
        forn(j, 1000000) out << 1;
        out << endl;
    }
    return 0;
}