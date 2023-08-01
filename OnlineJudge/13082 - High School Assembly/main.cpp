/*
    UVA 13082 - High School Assembly
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 99999999

int howManyMoves(const vector<int>& numbers){
    int moves = 0;
    // Guardo en la posicion i el menor numero 
    // que se encuentra luego de la posicion i en el vector de numeros.
    vector<int> minimumNumberToTheRight(numbers.size(), 0);
    minimumNumberToTheRight[minimumNumberToTheRight.size()-1] = INF;
    for(int i = numbers.size()-2; i >= 0; i--)
        minimumNumberToTheRight[i] = min(minimumNumberToTheRight[i+1], numbers[i+1]);

    // Vamos a marcar los elementos que tenemos que mover.
    // Vamos a marcar un elemento si a la derecha en algun lugar hay un elemento menor
    // o a la izquierda tiene un elemento marcado menor.
    vector<bool> marked(numbers.size(), false);
    int minimumNumberToLeftMarked = INF;
    for(int i = 0; i < numbers.size(); i++){
        marked[i] = numbers[i] > minimumNumberToTheRight[i] || minimumNumberToLeftMarked < numbers[i];
        if(marked[i])
            minimumNumberToLeftMarked = min(minimumNumberToLeftMarked, numbers[i]);
    }
    
    return count(marked.begin(), marked.end(), true);
}

int main(){
    #ifdef TEST
    freopen("sample2.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        int n;
        cin >> n;

        vector<int> numbers(n);
        for(int i = 0; i < n; i++)
            cin >> numbers[i];

        if(n == 1)
            cout << "Case " << z+1 << ": " << 0 << endl;
        if(n == 2)
            cout << "Case " << z+1 << ": " << (numbers[0] > numbers[1] ? 1 : 0) << endl;
        if(n > 2)
            cout << "Case " << z+1 << ": " << howManyMoves(numbers) << endl;
    }
    return 0;
}