#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
const int maxSizeHashTable = 1e6;

//HASH TABLE CON POLYNOMIAL HASHING

class hashtable
{
public:
    hashtable();
    int get(string key);
    void insert(int value, string key);
    bool exists(string key){ return internalArray[hashKey(key)] != NULL; }
    //int viewHash(string key){ return hashKey(key); }
private:
    int hashKey(string key);
    vector<int*>internalArray;
};

hashtable::hashtable()
{
    internalArray.resize(maxSizeHashTable,NULL);
}

int hashtable::get(string key)
{
    if(internalArray[hashKey(key)] != NULL)
        return *(internalArray[hashKey(key)]);
    return -1;
}

void hashtable::insert(int value, string key)
{
    internalArray[hashKey(key)] = new int;
    *internalArray[hashKey(key)] = value;
}

int hashtable::hashKey(string key)
{
    //POLYNOMIAL HASHING
    int c = 0;
    forn(i,key.size())
    {
        c += int(key[i])*pow(41,key.size()-1-i);
        c %= maxSizeHashTable;
    }
    return c;
}


int main()
{
    hashtable a;
    a.insert(3,"hola");
    cout << a.get("hola") << endl;
    cout << a.get("HOLA") << endl;
    while (true)
    {
        string z;
        cin >> z;
        cout << a.exists(z) << endl;
    }
    
    return 0;
}