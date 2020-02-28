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
        vector<long long>nums(N);
        forn(i,N) cin >> nums[i];
        long long solution = 0;
        sort(nums.begin(), nums.end());
        forn(i,N)
        {
            forsn(j,i+1,N)
            {
                long long numeroAbuscar = nums[i]*nums[j];
                auto it1 = lower_bound(nums.begin()+j+1, nums.end(), numeroAbuscar);
                auto it2 = upper_bound(nums.begin()+j+1, nums.end(), numeroAbuscar);
                solution += distance(it1, it2);

                /*forsn(k,j+1,N)
                {
                    if(nums[i]*nums[j] == nums[k] or nums[k]*nums[j] == nums[i] or nums[i]*nums[k] == nums[j])
                    {
                        solution++;
                    }
                }*/
            }
        }
        cout << "Case #" << zzz+1 << ": " << solution << endl;
    }
    return 0;
}