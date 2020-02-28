#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    ofstream out("secuenciando3.in");
    //string alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string alphabet = "GT";
    out << alphabet << endl;
    srand(time(NULL));
    forn(i, 1000)
        out << alphabet[rand()%alphabet.size()];

    /*forn(i, 300)
        out << 'A';
    forn(i, 700)
        out << 'C';*/
    out << endl;
    return 0;
}