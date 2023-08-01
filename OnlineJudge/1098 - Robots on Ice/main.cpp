/*
    UVA 1098 - Robots on Ice
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

inline unsigned int toCoords(int posX, int posY, int n){
    return (unsigned)(posX+posY*n);
}

inline bool isInside(int posX, int posY, int n, int m){
    return posX >= 0 && posX < n && posY >= 0 && posY < m;
}

inline bool allVisited(vector<bool> &visitedMap){
    for(unsigned int i = 0; i < visitedMap.size(); i++){
        if(visitedMap[i] == false)
            return false;
    }
    return true;
    
}

int solver(vector<bool> &visitedMap, int t, int posX, int posY, int n, int m, int r1, int c1, int r2, int c2, int r3, int c3, int t1, int t2, int t3){
    int cant = 0;

    // Queda tiempo para llegar a los puntos en los tiempos propuestos
    if((t <= t1 && t1 - t < abs(r1 - posY) + abs(c1 - posX)) 
        || (t <= t2 && t2 - t < abs(r2 - posY) + abs(c2 - posX))
        || (t <= t3 && t3 - t < abs(r3 - posY) + abs(c3 - posX)))
        return 0;

    // Termine
    if(posX == 1 && posY == 0 && allVisited(visitedMap))
        return 1;
    
    // Poda flashera
    if((
        (!isInside(posX-1,posY,n,m) || visitedMap[toCoords(posX-1,posY,n)]) 
        && (!isInside(posX+1,posY,n,m) || visitedMap[toCoords(posX+1,posY,n)]) 
        && (isInside(posX,posY-1,n,m) && !visitedMap[toCoords(posX,posY-1,n)])
        && (isInside(posX,posY+1,n,m) && !visitedMap[toCoords(posX,posY+1,n)]))
        || ((!isInside(posX,posY-1,n,m) || visitedMap[toCoords(posX,posY-1,n)]) 
        && (!isInside(posX,posY+1,n,m) || visitedMap[toCoords(posX,posY+1,n)]) 
        && (isInside(posX-1,posY,n,m) && !visitedMap[toCoords(posX-1,posY,n)]) 
        && (isInside(posX+1,posY,n,m) && !visitedMap[toCoords(posX+1,posY,n)])))
        return 0;
    

    int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    for(int i = 0; i < 4; i++){
        int newPosX = posX+directions[i][0], newPosY = posY+directions[i][1];
        if (isInside(newPosX, newPosY, n, m) && !visitedMap[toCoords(newPosX,newPosY,n)]){
            visitedMap[toCoords(newPosX,newPosY,n)] = true;
            cant += solver(visitedMap, t+1, newPosX, newPosY, n, m, r1, c1, r2, c2, r3, c3, t1, t2, t3); 
            visitedMap[toCoords(newPosX,newPosY,n)] = false;
        }
    } 
    
    return cant;
}

int main(){
    int m, n;
    cin >> m >> n;
    for(int t = 0; n != 0; t++){
        int r1, c1, r2, c2, r3, c3;
        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
        vector<bool> visitedMap((unsigned)(m*n), false);
        visitedMap[0] = true;
        cout << "Case " << t+1 << ": " << solver(visitedMap, 1, 0, 0, n, m, r1, c1, r2, c2, r3, c3, m*n/4, 2*m*n/4, 3*m*n/4) << endl;
        cin >> m >> n;
    }
    return 0;
}