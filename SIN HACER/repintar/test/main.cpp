#include <iostream>
#include <vector>
//#include <stdlib.h>
#include <fstream>
#include <time.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
using namespace std;

int main()
{
    ofstream out("repintar.in");
    out << 2000 << endl;
    srand(time(NULL));
    forn(i,2000)
    {
        forn(j,2000)
        {
            switch(rand()%3)
            {
                case 0:
                    out << 'V';
                break;
                case 1:
                    out << 'R';
                break;
                case 2:
                    out << 'A';
                break;
            }
        }
        out << endl;
    }
    return 0;
}
