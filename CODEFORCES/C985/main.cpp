#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define d(x) cout << x << endl;
const int INF = 2000000000;

int main()
{
    long long n, k, l;
    cin >> n >> k >> l;
    long long tamanio = (long long) n * k;
    vector<int>a(tamanio);

    for(long long i = 0; i < tamanio; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    long long minV = a[0];
    long long indexPasados;

    indexPasados = int( upper_bound(a.begin(), a.end(), minV+l) - a.begin() );
    
    if(indexPasados < n)
    {
        cout << "0" << endl;
        return 0;
    }
    long long cantPasados = tamanio-indexPasados;
    long long s = 0;
    //long long u = 0;

    /*int cont = 0;
    for(long long i = 0; i < n; i++)
    {
        s += a[cont];
        //
        for(long long j = 1; j < k; j++)
        {
            if(cantPasados > 0)
                cantPasados--;
            else
                cont++;
        }
        cont++;
    }*/


    int u = 0;
	for(int i = 0; i < n; i++) {
		s += a[u++];
		
		for(int j = 0; j < k - 1; j++) {
			if(indexPasados - u > n - i - 1)
				u++;
			else
				break;
		}
	}

    cout << s << endl;

    return 0;
}