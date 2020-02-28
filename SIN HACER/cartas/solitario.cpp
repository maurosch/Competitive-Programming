#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

class FT
{
public:
    FT(int n) : ft(n) {}
    int get(int a, int b)
    {
        return getFT(a-1) - getFT(b);
    }
    void update(int pos, int v)
    {
        for(int i = pos+1; i; i += i&-i) ft[i] += v;
    }
private:
    int getFT(int pos)
    {
        int s = 0;
        for(int i = pos+1; i; i -= i&-i) s += ft[i];
        return s;
    }
    vector<int> ft;
};

int solitario(vector<int> c, long long N, int K)
{
    vector<int>mazo(N);
    int cont = 0;
    forn(i,N)
    {
        mazo[i] = c[cont];
        cont++;
    }
    reverse(mazo.begin(), mazo.end());

    int index = N-1;

    FT fenwick(N+1);
    forn(i,N-1) fenwick.update(i,1);
    //fenwick.update(N-1,-1);
    int cantCartas = N-1;
    int mover = K+1;
    while(cantCartas > 1)
    {
        int sobrantes = fenwick.get(index, N-1);
        if(mover > sobrantes)
        {
            mover -= sobrantes;
            index = 0;
            while(mover > cantCartas) mover -= cantCartas;
        }

        int lo = mover, hi = N-1;
        while(hi-lo > 1)
        {
            int medio = (hi+lo)/2;
            if(fenwick.get(index,medio) < mover)
                lo = medio+1;
            else 
                hi = medio;
        }
        index+=lo;
        fenwick.update(index,-1);
        cantCartas--;
    }

    return 0;
}
