#include <iostream>
#include <vector>
#include <set>
#define For(i, n) for(int i = 0; i < n; i++)
#define rFor(i, n) for(int i = n-1; i >= 0; i--)
#define DBG(x) cerr << #x << " = " << (x) << endl

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>window;
        vector<int>z;
        for(int i = 0; i < k; i++)
        {
            window.insert(nums[i]);
        }
        if (nums.size() > 0) z.push_back(*window.rbegin());
        for(int i = 0; i < nums.size()-k; i++)
        {
            auto it = window.find(nums[i]);
            window.erase(it);
            //window.erase(nums[i]);
            window.insert(nums[i+k]);
            z.push_back(*window.rbegin());
            for(auto i = window.begin(); i != window.end(); i++) cout << *i << " ";
            cout << endl;
        }
        return z;
    }
};


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>s(n);
    For(i, n) cin >> s[i];
    Solution a;
    vector<int>z = a.maxSlidingWindow(s, k);
    //For(i, z.size()) cout << z[i] << endl;
    return 0;
}

//
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        multiset<int>window;
//        vector<int>z;
//        for(int i = 0; i < k; i++)
//        {
//            window.insert(nums[i]);
//        }
//        if(nums.size() > 0) z.push_back(*window.rbegin());
//        for(int i = 0; i < nums.size()-k; i++)
//        {
//            auto it = window.find(nums[i]);
//            window.erase(it);
//            window.insert(nums[i+k]);
//            z.push_back(*window.rbegin());
//        }
//        return z;
//    }
//
//};
//
