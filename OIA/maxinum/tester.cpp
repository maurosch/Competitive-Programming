#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;
typedef pair<int,int> ii;
#define f first
#define s second

int main()
{
    ofstream out("maxinum.in");
    srand(time(NULL));
    out << 2000000 << endl;
    forn(i, 2000000)
        out << rand()%45+1 << endl;
    return 0;
}