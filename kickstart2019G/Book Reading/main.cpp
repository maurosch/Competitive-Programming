#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main()
{
    int T;
    cin >> T;
    forn(z,T)
    {
        int N,M,Q;
        cin >> N >> M >> Q;
        vector<bool>tornout(N+1, false);
        forn(i,M)
        {
            int aux;
            cin >> aux;
            tornout[aux] = true; 
        }
        
        vector<int>solutions(N+1);

        for(int i = 1; i <= N; i++)
        {
            for(int j = i; j <= N; j+=i)
            {
                if(!tornout[j])
                    solutions[i]++;
            }
        }
        /*forn(i,solutions.size())
            cout << solutions[i] << " ";
            cout << endl;*/
        long long sumaTotal = 0;
        forn(i,Q)
        {
            int r;
            cin >> r;
            sumaTotal += solutions[r];
        }
        cout << "Case #" << z+1 << ": " << sumaTotal << endl;
    }
}