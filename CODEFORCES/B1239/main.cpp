#include <iostream>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = s; i < int(n); i++)

string shiftearString(const string &s, int k)
{
    if(k < 0) 
        k = k+s.size();
    
    string sShifteada = s;
    forn(i,k)
        sShifteada[i] = s[s.size()-k+i];
    forsn(i,k,s.size())
        sShifteada[i] = s[i-k];

    return sShifteada;
}
int cantShifteosParaCorregir(const string &s)
{
    int c = 0, cAux = 0, indice = -1, contParentesis = 0;
    forn(i,s.size())
        if(s[i] == '(')
        {
            cAux++;
            contParentesis++;
        }
        else
        {
            cAux--;
            if(cAux < c)
            {
                c = cAux;
                indice = i;
            }
        }
    return -indice-1;
}

string shiftearCorreccion(const string &s)
{
    return shiftearString(s, cantShifteosParaCorregir(s));
}

int cantidadParentesis(const string &s)
{
    int cantParentesis = 0, suma = 0;
    forn(i,s.size())
    {
        if(s[i] == '(')
            suma++;
        else 
            suma--;
        if(suma == 0)
            cantParentesis++;
    }
    return cantParentesis;
}

int indexWithoutShift(int index, int length, int shift)
{
    return (length + ltotal - k) % length;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int c = 0, contParentesis = 0;

    forn(i,s.size())
        if(s[i] == '(')
            c++;
            
    if(s.size() % 2 != 0 or c != s.size()/2)
        cout << "0" << endl << "1 1" << endl;
    else
    {
        int k = cantShifteosParaCorregir(s);
        string sShifted = shiftearString(s,k);
        vector<int> prefixSumArray(s.size());
        int c = 0;
        forn(i,sShifted.size())
        {
            if(sShifted[i] == '(')
                c++;
            else 
                c--;
            prefixSumArray[i] = c;
        }

        //We look for subarrays with min=1
        forn(i,prefixSumArray.size())
        {
            if(prefixSumArray[i] == 1)
            {
                int count = 0;
                while(prefixSumArray[i] >= 1)
                {
                    if(prefixSumArray[i] == 1)
                        count++;
                    i++;
                }
            }
        }

        //We look for subarrays with min=2
        forn(i,prefixSumArray.size())
        {
            if(prefixSumArray[i] == 2)
            {
                int count = 0;
                while(prefixSumArray[i] >= 2)
                {
                    if(prefixSumArray[i] == 2)
                        count++;
                    i++;
                }
                
            }
        }
    }
    return 0;
}

//(())())(() --> (())()()()

//(()))()(() --> (())(())()

//(((((((())))))))()(()()) --> )((((((()))))))(()(()()) o (((((((())))))))())()()(

//))(())((

//()()()()()())()(

