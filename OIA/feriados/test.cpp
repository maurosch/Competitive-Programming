#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)

int main()
{
    srand(time(NULL));
    ofstream out("a.in");
    out << "200000 1000000 1000000" << endl;
    forn(i, 200000)
    {
        out << rand()%1000000+1 << " ";
    }
    return 0;
}