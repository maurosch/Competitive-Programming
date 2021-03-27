#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

vector<int> cost(int n, int c){
    vector<int> s(n);
    vector<int> offset(n);
    if(c < n-1 or c > n*(n+1)/2-1)
        return vector<int>();
    
    c -= n-1;
    int num = 1;
    int inicio = 0, fin = n-1;
    while(inicio != fin){
        if(c > fin-inicio){
           s[fin] = num;
           c -= fin-inicio;
           num++;
           fin--;
           
        } else {
            s[inicio+c] = num;
            for(int i = inicio+c; i >= inicio; i--){
                s[i] = num;
                num++;
            }
            for(int i = inicio+c+1; i <= fin; i++){
                s[i] = num;
                num++;
            }
            break;
        }

        if(inicio == fin) break;

        if(c > fin-inicio){
           s[inicio] = num;
           c -= fin-inicio;
           num++;
           inicio++;
        } else {
            s[fin-c] = num;
            for(int i = fin-c; i <= fin; i++){
                s[i] = num;
                num++;
            }
            for(int i = fin-c-1; i >= inicio; i--){
                s[i] = num;
                num++;
            }
            break;
        }
    }
    if(inicio == fin){
        s[inicio] = num;
    }

    return s;
}
int main(){
    int T;
    cin >> T;
    forn(t,T){
        int n, c;
        cin >> n >> c;
        cout << "Case #" << t+1 << ":";

        auto v = cost(n,c);

        if(v.size() == 0){
            cout << " IMPOSSIBLE";
        } else {
            forn(i, v.size())
                cout << " " << v[i];
        }
        cout << endl;
    }
}