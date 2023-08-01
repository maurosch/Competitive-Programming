#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    if(not freopen("in", "w", stdout)) return 1;

    int T = 200;
    int MAX_N = 100;

    for(int k = 0; k < T; ++k) {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<> dist_n(6, MAX_N);
        int N = dist_n(mt);

        uniform_int_distribution<> dist_m(N-1, 3*N*(N-1)/8);
        int M = dist_m(mt);

        cout << M << endl;

        vector<unordered_set<int>> is_edge(N+1);
        for(int i = 2; i <= N; ++i) {
            uniform_int_distribution<> dist_c(1, i-1);
            cout << dist_c(mt) << " " << i << endl;
        }

        uniform_int_distribution<> dist_e(1, N);
        for(int i = 0; i < M - N + 1; ++i) {
            int v = 0, w = 0;
            while(v == w or is_edge[v].count(w)) {
                v = dist_e(mt);
                w = dist_e(mt);
            }
            is_edge[v].insert(w);
            is_edge[w].insert(v);
            cout << v << " " << w << endl;
        }
        cout << endl;
    }
    cout << 0 << endl;
    return 0;
}
