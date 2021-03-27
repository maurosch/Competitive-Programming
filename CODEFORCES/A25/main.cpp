#include <iostream>
#include <vector>
using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)

int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    forn(i,n)
        cin >> nums[i];

    int par = 0, impar = 0;
    for(int i = 0; i < 3; i++)
        if(nums[i] % 2 == 0) par++;

    if(par >= 2){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1) {
                cout << i+1 << endl;
                return 0;
            }
        }
    } else {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0) {
                cout << i+1 << endl;
                return 0;
            }
        }
    }

    return 0;
}