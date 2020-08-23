#include <iostream>
#include <vector>
using namespace std;

vector<int> kinderGarten(vector<int> a){
    vector<int> s;
    for(const auto x : a)
        if(!((x*x+10)%10 == 5 or (x*x+10)%10 == 6))
            s.push_back(x);

    return s;
}

int main()  {
    vector<int> c = {1,2,3,4,5,6,7,8,9,10};
    vector<int> s = kinderGarten(c);
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    return 0;

}