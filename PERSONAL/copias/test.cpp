#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <iomanip> 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;

int main()
{
    ofstream out("text1.txt");
    ofstream out2("text2.txt");
    forn(i,10)
    {
        out << 'a';
        out2 << 'b';
    }
    return 0;
}