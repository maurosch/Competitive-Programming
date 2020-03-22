#include <iostream>
#include <queue>
using namespace std;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    priority_queue<int, vector<int>, greater<int>> a;
    a.push(2);
    a.push(4);
    a.push(8);
    a.push(0);
    cout << a.top() << endl;
    a.pop();
    cout << a.top() << endl;

    return 0;
}