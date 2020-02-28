#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

#define forn(i, n) for(int i = 0; i < n; i++)
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int main()
{
    srand(time(NULL));
    ofstream out("a.in");
    out << "1000 1000 10 10 3 3" << endl;
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            out << rand()%100+1 << " ";
        }
        out << endl;
    }
    return 0;
}