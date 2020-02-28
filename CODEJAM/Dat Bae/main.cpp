#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = s; i < int(n); i++)
#define sz(x) x.size()

int count1(string a)
{
    int c = 0;
    forn(i, a.size())
        if(a[i] == '1') c++;
    return c;
}

void buscar(int l, int r, const int n, vector<int>& indices, bool &exit)
{
    if(exit) return;
    //[ )
    string b;
    forn(i,l)
        b += '0';
    forsn(i,l,r)
        b += '1';
    forsn(i,r,n)
        b += '0';
    
    cout << b << endl;
    cin >> b;
    if(b == "-1") 
    {
        exit = true;
        return;
    }
    
    int c1 = count1(b);

    if(c1 < r-l)
    {
        if(c1 == 0)
            forsn(i,l,r)
                indices.push_back(i);
        else
        {
            int mid = (l+r)/2;
            buscar(l, mid, n, indices, exit);
            buscar(mid, r, n, indices, exit);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int veredicto = 1;
    for (int i = 0; i < t and veredicto == 1; i++)
    {
        int n, b, f;
        cin >> n >> b >> f;
        vector<int>indices;

        int mid = n/2;
        bool exit = false;
        buscar(0,mid,n, indices, exit);
        buscar(mid,n,n, indices, exit);
        if(exit) return 0;

        forn(i,sz(indices))
            cout << indices[i] << " ";
        cout << endl;

        int veredicto;
        cin >> veredicto;
    }
    
    return 0;
}