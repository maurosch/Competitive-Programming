#include <iostream>
using namespace std;
int main()
{
    int k;
    string s;
    cin >> s >> k;
    if(s.size() % k != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    int tamanio = s.size()/k;
    for(int i = 0; i < s.size(); i+=tamanio)
    {
        for(int j = 0; j < tamanio/2; j++)
        {
            if(s[i+j] != s[i+tamanio-1-j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
