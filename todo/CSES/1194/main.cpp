// https://cses.fi/problemset/task/1194
// 16/03/2020

#include <iostream>
#include <vector>
#include <queue>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define x second
#define y first
using namespace std;

enum state{
    monster,
    human,
    wall,
    nothing
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> map(h, vector<int>(w));

    queue<pair<int,int>> human;
    queue<pair<int,int>> monster;

    forn(i,h) {
        string aux;
        cin >> aux;
        forn(j,aux.size()){
            if(aux[i] == '#')
                map[i][j] = state::wall;
            if(aux[i] == 'A') {
                map[i][j] = state::human;
                human.push({i,j});
            }
            if(aux[i] == 'M') {
                monster.push({i,j});
                map[i][j] = state::monster;
            }
            if(aux[i] == '.')
                map[i][j] = state::nothing;
        }
    }
    vector<pair<int,int>> dir(4);
    dir[0] = {1,0}; dir[1] = {0,1}; dir[2] = {-1,0}; dir[3] = {0,-1}; 
    
    while(!human.empty() || !monster.empty()){
        auto p = human.front();
        human.pop();
        forn(i,4){
            pair<int,int> pAux = {p.y+dir[i].y,p.x+dir[i].x};
            if( insideMap(pAux, h, w) && map[pAux.y][pAux.x] != state::monster && map[pAux.y][pAux.x] != state::wall ){
                map[pAux.y][pAux.x] = state::human;
                human.push(pAux);
            }
        }

        auto p = human.front();
        human.pop();
        forn(i,4){
            pair<int,int> pAux = {p.y+dir[i].y,p.x+dir[i].x};
            if( insideMap(pAux, h, w) && map[pAux.y][pAux.x] != state::monster && map[pAux.y][pAux.x] != state::wall ){
                map[pAux.y][pAux.x] = state::human;
                human.push(pAux);
            }
        }
             
    }

    return 0;
}