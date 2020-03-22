#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)

int randomNum()
{
    return rand()%10;
}

char randomLetra()
{
    char aux = 'a';
    aux += rand()%24;
    return aux;
}

int main()
{
    ofstream out("rayuela.in");
    srand(time(NULL));
    out << "100 10000" << endl;
    forn(i, 100)
    {
        forn(j, 100)
            out << randomLetra() << " " << randomNum() << " ";
        
        out << endl;
    }

    forn(i, 10000)
        out << "abcedfgtoimdifoditlf" << endl;

    return 0;
}