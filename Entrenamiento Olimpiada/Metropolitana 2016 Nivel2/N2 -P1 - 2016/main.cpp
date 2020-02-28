#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long x, y, numFinal;
    cin >> y;
    x = y+1;
    numFinal = x+y;

    long long maxDiv = sqrt(numFinal);
    for(long long div = 2; div <= maxDiv; div++)
    {
        if(numFinal%div == 0)
        {
            cout << "No hay chances" << endl;
            return 0;
        }
    }
    cout << x << endl;
    return 0;
}
