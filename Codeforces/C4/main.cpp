//---------
//--------------------
//----------------------------------
//------------------------------------------------------
//Mauro Schiavinato - UBA Cs. de la Computación (299/19) - 01/11/2019
//C++14 - Visual Studio Code - ArchLinux 
//------------------------------------------------------
//----------------------------------
//--------------------
//---------
#include <iostream>
#include <unordered_map>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
int main()
{
    int z;
    cin >> z;
    unordered_map<string,int> mapa;
    forn(i,z)
    {
        string aux;
        cin >> aux;
        if(mapa.find(aux) != mapa.end())
        {
            cout << aux << mapa[aux] << endl; 
            mapa[aux]++;
        }
        else
        {
            cout << "OK" << endl;
            mapa[aux] = 1;
        }
    }
    return 0;
}