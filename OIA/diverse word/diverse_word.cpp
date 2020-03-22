#include <iostream>
#include <vector>
#include <set>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define rforn(i,n) for(int i = int(n)-1; i > 0; i--)
using namespace std;
const int CANT_LETRAS = 26;

int main()
{
    string word;
    cin >> word;
    if(int(word.size()) < CANT_LETRAS)
    {
        int letras[CANT_LETRAS];
        forn(i,CANT_LETRAS) letras[i] = 0;
        forn(i,word.size()) letras[word[i]-'a'] = 1;
        int s = 0;
        for(;letras[s] != 0; s++);
        cout << word << char('a'+s) << endl;
        return 0;
    }

    int menores[CANT_LETRAS];
    forn(i,CANT_LETRAS) menores[i] = 0;

    //Se podría mejorar con un árbol la complejidad
    //pero el enunciado no pedía un tiempo tan corto
    for(int i = int(word.size()-1); i > 0; i--)
    {
        menores[word[i]-'a'] = 1;
        forsn(z,word[i-1]-'a',26)
        {
            if(menores[z] == 1)
            {
                cout << word.substr(0,i-1) << char('a'+z) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}