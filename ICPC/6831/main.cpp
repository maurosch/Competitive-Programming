#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
int main()
{
    int k, d;
    while(cin >> k >> d)
    {
        vector<bool>asientos(k,false);
        vector<bool>seQuierenSentar(k,true);
        forn(i,d)
        {
            int asientoAsignado, asientoOcupado;
            cin >> asientoAsignado >> asientoOcupado;
            asientos[asientoOcupado-1] = true;
            seQuierenSentar[asientoAsignado-1] = false;
        }

        vector<int>combinaciones(k); 
        int cont = 0, minimo = 1e7;
        forn(i, k)
        {
            if(seQuierenSentar[i]) 
                cont++; 
            
            if(!asientos[i]) 
                cont--;
            
            combinaciones[i] = cont;
            
            if(cont < minimo) 
                minimo = min(cont, minimo);  
        }
        
        int levantar = minimo-1;

        /*forn(i,k)
            cout << combinaciones[i] << " ";
        cout << endl;*/
        /*forn(i,k)
            cout << combinaciones[i]-levantar << " ";
        cout << endl;
        */
        long long cantComb = 1;
        const long long resto = 1e9+7;
        forn(i,k)
            if(!asientos[i])
            {
                cantComb *= (long long)(combinaciones[i]-levantar); 
                cantComb %= resto;
            }
        cout << cantComb << endl;
    }
    return 0;
}