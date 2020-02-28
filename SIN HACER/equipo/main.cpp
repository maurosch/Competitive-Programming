#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
typedef pair<int,int> ii;
typedef vector<vector<int>> matriz;

void agregar_trie(string &a, matriz &trie, int &proximo_libre)
{
    int actual = 0;
    forn(i, a.size())
    {
        int letra = a[i] - 'a';
        if(trie[actual][letra] == -1)
            trie[actual][letra] = proximo_libre++;
        actual = trie[actual][letra];
    }
}

int main()
{
    ifstream in("equipo.in");
    ofstream out("equipo.out");
    matriz trie(500*5000, vector<ii>(26,-1));
    int proximo_libre = 0;



    return 0;
}