#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream out("a.in");
    out << 1000000 << " " << 10 << endl;
    for(int i = 0; i < 1000000; i++)
    {
        out << rand()%1000+1 << endl;
    }
    return 0;
}