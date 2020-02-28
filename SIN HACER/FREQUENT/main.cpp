#include <iostream>
#include <vector>

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
typedef pair<int,int> ii;

const int INF = 999999999;

int nextPow2(int v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

//----------------SEGMENTED TREE MAX MODIFICADO----------------



int queryMAX(int a, int b, int initialSize, vector<ii> &tree)
{
    a += initialSize; b += initialSize;
    int s = 0;
    while(a <= b)
    {
        if(a%2 == 1) s = max(tree[a++].first,s);
        if(b%2 == 0) s = max(tree[b--].first,s);
        a /= 2; b /= 2;
    }
    return s;
}




class STMax 
{
public:
    STMax(int m_size, int numerosSize) : initialSize(m_size), tree(m_size*2,-INF){};
    void set(int value, int pos)
    {
        pos += initialSize;
        tree[pos] = value;
        for(pos /= 2; pos > 0; pos /= 2)
            tree[pos] = max(tree[2*pos],tree[2*pos+1]);
    }
    
private:
    int initialSize;
    vector<int>tree;
    vector<int>numeros;
};







int main()
{
    int n, q;
    cin >> n >> q;
    vector<int>numeros(n);
    vector<ii>tree(2*nextPow2(n));
    forn(i,n)
        cin >> numeros[i];
    forn(i,q)
    {
        int a, b;
        cin >> a >> b;
        cout << tree.query(a-1,b-1) << endl;
    }
    
     

    return 0;
}