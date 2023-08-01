/*
    UVA 10158 - War
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;
#define INF 99999999
#define ii pair<int,int>

struct UF {
    vector<int> p, s;
    
    UF(int n) : p(n+1), s(n+1, 1) {
        for(int i = 0; i <= n; ++i) p[i] = i;
    }
    
    void unite(int v, int w) {
        v = find(v), w = find(w);
        if(v == w) return;
        if(s[v] < s[w]) swap(v, w);
        p[w] = v;
        s[v] += s[w]; 
    }
    
    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }
        
};

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int n, c, x, y;
    cin >> n;
    UF friends(n);
    vector<int> enemyGroup(n,-1); // Cada persona puede tener de enemigo a un grupo de amigos.
    // Asimismo un grupo tiene solo 1 grupo de enemigo, guardamos el enemigo en el representante.

    auto areEnemies = [&friends, &enemyGroup](int x, int y){
        x = friends.find(x);
        y = friends.find(y);

        return (enemyGroup[y] != -1 && x == friends.find(enemyGroup[y]))
            || (enemyGroup[x] != -1 && friends.find(enemyGroup[x]) == y);
    };

    auto setFriends = [&friends, &enemyGroup, &areEnemies](int x, int y){
        // pre: X e Y no tienen que ser enemigos...
        x = friends.find(x);
        y = friends.find(y);

        if(enemyGroup[x] != -1 && enemyGroup[y] != -1)
            friends.unite(enemyGroup[x], enemyGroup[y]);

        friends.unite(x, y);
        auto represent = friends.find(x);
        if(enemyGroup[x] != -1)
            enemyGroup[represent] = enemyGroup[x];
        if(enemyGroup[y] != -1)
            enemyGroup[represent] = enemyGroup[y];
    };

    do {
        cin >> c >> x >> y;

        if(c == 1){ //setFriends
            if(areEnemies(x,y))
                cout << "-1" << endl;
            else
                setFriends(x,y);
        }
        if(c == 2){ //setEnemies
            if(friends.find(x) == friends.find(y))
                cout << "-1" << endl;
            else {
                x = friends.find(x);
                y = friends.find(y);
                if(enemyGroup[x] != -1) setFriends(enemyGroup[x],y);
                else enemyGroup[x] = y;
                if(enemyGroup[y] != -1) setFriends(enemyGroup[y],x);
                else enemyGroup[y] = x;
            }
        }
        if(c == 3){ //areFriends
            if(friends.find(x) == friends.find(y))
                cout << "1" << endl;
            else 
                cout << "0" << endl;
        }
        if(c == 4){ //areEnemies
            cout << (areEnemies(x,y) ? "1" : "0") << endl;
        }
    } while(not (c == 0 and x == 0 and y == 0));
    return 0;
}