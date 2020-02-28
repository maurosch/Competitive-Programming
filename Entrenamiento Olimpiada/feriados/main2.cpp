#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, D, F;
    cin >> N >> D >> F;
    vector<bool>dias(D, false);
    
    for(int i = 0; i < N; i++) 
    {
        int aux;
        cin >> aux;
        dias[aux-1] = true;
    }
    
    int indexA = 0, indexB = 0;
    int s = 0, cantDiasFaltados = 0;
    
    while(indexB <= D)
    {
        if(cantDiasFaltados <= F)
        { 
            if(indexB-indexA > s) 
                s = indexB-indexA;

            if(indexB < D and !dias[indexB]) 
                cantDiasFaltados++;

            indexB++;
        }
        else
        {
            if(!dias[indexA]) 
                cantDiasFaltados--;

            indexA++;
        }
    }

    cout << s << endl;
    return 0;
}