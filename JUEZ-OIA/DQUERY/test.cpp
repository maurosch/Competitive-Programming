#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <fstream>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

int random(int a, int b)
{
    return (rand()%(b+1-a)+a);
}

int main()
{
    ofstream out("a2.in");
    out << "30000" << endl;
    forn(i,30000) out << rand()%1000000+1 << " ";
    out << endl;
    out << "200000" << endl;
    forn(i,200000)
    {
        int a = rand()%29000+1, b = rand()%(30000+1-a)+a;
        out << a << " " << b << endl;
    }

    return 0;
}