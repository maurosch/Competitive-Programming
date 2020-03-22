#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;
//
#define forn(i, n) for(int i = 0; i < int(n); i++)

#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
typedef vector<int> vi;
typedef vector<bool> vb;
const int INF = 999999999;

int main()
{
    ofstream out("a.in");
    out << 100000 << endl;
    forn(i, 100000)
    {
        out << rand()%200 - 100 << " ";
    }
    return 0;
}
