/*
    UVA 11212 - Editing a book
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
#include <unordered_set>
using namespace std;

const long long power10[11] = {1,(long long)10e0,(long long)10e1,(long long)10e2,(long long)10e3,(long long)10e4,(long long)10e5,(long long)10e6,(long long)10e7,(long long)10e8,(long long)10e9};

// Obtener secciones de un numero
long long intervalNumber(long long num, int n, int from, int to){
    return num / power10[n - to] % power10[to - from];
}

// No usado pero es el backtrack sin meeting in the middle
int backtrack(int n, long long p, int c){
    if(p == 123456789 / power10[9-n]){
        return c;
    }
    if(c > 4){
        return 10;
    }
    int d = 10;
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int z = j+1; z <= n; z++){
                long long newP = 
                    intervalNumber(p, n, 0, i) * power10[n-i]
                    + intervalNumber(p, n, i, j) * power10[n-z]
                    + intervalNumber(p, n, j, z) * power10[n-z+(j-i)] 
                    + intervalNumber(p, n, z, n);
                d = min(d, backtrack(n, newP, c+1));
            }
        } 
    }
    return d;
}

void backtrackStep(int n, unordered_set<long long>& options){
    unordered_set<long long> newOptions;
    for(auto p : options){
        for(int i = 0; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int z = j+1; z <= n; z++){ 
                    newOptions.insert( 
                        intervalNumber(p, n, 0, i) * power10[n-i] 
                        + intervalNumber(p, n, i, j) * power10[n-z] 
                        + intervalNumber(p, n, j, z) * power10[n-z+(j-i)] 
                        + intervalNumber(p, n, z, n) );
                }
            } 
        }
    }
    options = newOptions;
}

int solver(int n, long long p){
    int c = 0;
    if(p == 123456789 / power10[9-n]) 
        return 0;
    unordered_set<long long> options1;
    options1.insert(p);
    unordered_set<long long> options2;
    options2.insert(123456789 / power10[9-n]);
    while(true){
        backtrackStep(n, options1);
        c++;

        for(auto v : options1)
            if(options2.find(v) != options2.end())
                return c;

        backtrackStep(n, options2);
        c++;

        for(auto v : options1)
            if(options2.find(v) != options2.end())
                return c;
    }
}

int main(){
    int n;
    cin >> n;
    for(int t = 0; n != 0; t++){
        long long p = 0;
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            p += power10[n-i-1] * aux;
        }
        cout << "Case " << t+1 << ": " << solver(n, p) << endl;
        cin >> n;
    }
    return 0;
}