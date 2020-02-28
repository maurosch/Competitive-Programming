#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
using namespace std;
int main()
{
    int T;
    cin >> T;
    forn(zzz,T)
    {
        int N;
        cin >> N;
        vector<int>nums(N);
        forn(i,N) cin >> nums[i];
        sort(nums.begin(), nums.end());
        int solution = 0;
        forn(i,N)
        {
            forsn(j,i+1,N)
            {
                forsn(k,j+1,N)
                {
                    if(nums[i]*nums[j] == nums[k])
                    {
                        solution++;
                    }
                }
            }
        }
        cout << "Case #" << zzz+1 << ": " << solution << endl;
    }
    return 0;
}