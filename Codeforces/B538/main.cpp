//Quasi Binary 26/12/2018
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)

int main()
{
    int n;
    cin >> n;
    
    int aux = n;
    vector<int> nums;
    while(n > 0)
    {
        aux = n;
        int numeroArestar = 0;
        for(int i = 0; aux > 0; i++)
        {
            int ultDigito = aux % 10;
            if(ultDigito > 0) numeroArestar += pow(10,i);
            aux /= 10;
        }
        n -= numeroArestar;
        //cout << numeroArestar << endl;
        nums.push_back(numeroArestar);
    }
    cout << nums.size() << endl;
    forn(i,nums.size()) 
        cout << nums[i] << " ";

    return 0;
}