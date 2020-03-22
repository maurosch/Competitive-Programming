#include <iostream>
#include <vector>
using namespace std;

int fib(int pos, vector<int> &dp)
{
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= pos; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[pos];
}
int main()
{
   int n = 8;
   vector<int> dp(n+1, -1); //El vector dp tiene que ser tan grande como el tamaño máximo de entrada
   cout << fib(n, dp) << endl;
   return 0;
}