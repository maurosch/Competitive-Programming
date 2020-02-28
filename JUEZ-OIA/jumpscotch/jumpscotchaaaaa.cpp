#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;

//Ventana con elementos dominantes
class ventanaDeslizante
{
public:
    ventanaDeslizante(){A=0; B=0;}
    void avanzarA()
    {
        auto it = find(indices.begin(),indices.end(),A);
        if(it != indices.end())
        {
            indices.erase(it);
        }
        A++;
    };
    void avanzarB(vector<int> &array)
    {
        if (indices.empty() or array[indices.back()] < array[B])
            indices.push_back(B);
        B++;
    };
private:
    vector<int>indices;
    int A, B;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int>mapa(n+1);
    vector<double>dp(n+1, -1);
    for(int i = 1; i <= n; i++)
        cin >> mapa[i];

    cout << fixed << setprecision(0);
    multiset<double> ventana;
    if(n == 1) 
    {
        cout << mapa[1];
        return 0;
    }
    if(d+1 >= n) cout << mapa[n]+mapa[1];
    else
    {
        dp[1] = mapa[1];
        for(int i = 2; i <= d+1; i++) dp[i] = mapa[i]+mapa[1];
        for(int i = 2; i <= d+1; i++) ventana.insert(dp[i]);
        for(int i = d+2; i <= n; i++)
        {
            dp[i] = (*ventana.begin())+mapa[i];
            ventana.erase(ventana.find(dp[i-d]));
            ventana.insert(dp[i]);
        }
        cout << dp[n] << endl;  
    }
    return 0;
}