/*
    UVA 10385 - Duathlon
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;

inline double calcTime(pair<double, double> speed, double r, double k){
    return r / speed.first + k / speed.second;
}

double timeDiff(const double p, const double km, const vector<pair<double,double>>& comp) {
    double timeCheater = calcTime(comp[comp.size()-1], p, km - p);
    double lowestTimeCompetitor = 99999999;
    for(int i = 0; i < comp.size()-1; ++i){
        double timeCompetitor = calcTime(comp[i], p, km - p);
        lowestTimeCompetitor = min(lowestTimeCompetitor, timeCompetitor);
    }
    return lowestTimeCompetitor - timeCheater;
};

int solve(double km, const vector<pair<double,double>>& comp, double &r){
    //busqueda ternaria
    double left = 0;
    double right = km;

    while(right - left >= 1e-10) {
        auto mid_left = right/3 + 2*left/3;
        auto mid_right = 2*right/3 + left/3;

        if(timeDiff(mid_left, km, comp) > timeDiff(mid_right, km, comp))
            right = mid_right;
        else
            left = mid_left;
    }
    r = left;
    return int(round(timeDiff(left, km, comp)*60*60));
}

int main(){
    #ifdef TEST
    freopen("sample.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);     
    cin.tie(0);

    cout << fixed << setprecision(2);

    double km;
    while(cin >> km){
        int n;
        cin >> n;
        vector<pair<double,double>> comp(n);
        for(int i = 0; i < n; i++)
            cin >> comp[i].first >> comp[i].second;

        double r;
        int difference = solve(km, comp, r); 

        if(difference >= 0)
            cout << "The cheater can win by " << difference << " seconds with r = " << r << "km and k = " << (km - r) << "km." << endl;
        else
            cout << "The cheater cannot win." << endl;
   }
    return 0;
}