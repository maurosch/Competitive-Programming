#include <iostream>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main(){
    int z, sumX = 0, sumY = 0, sumZ = 0;
    cin >> z;
    forn(i,z){
        int aux, aux2, aux3;
        cin >> aux >> aux2 >> aux3;
        sumX += aux; sumY += aux2; sumZ += aux3;
    }

    if(sumX == 0 && sumY == 0 && sumZ == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}