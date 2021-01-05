#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#include "solution.h"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("testcases/large/in/input10.txt", "r", stdin);
    freopen("testcases/large/out/output10.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v) {
            cin >> i;
        }
        int q;
        cin >> q;
        int cpy=q;
        vector<tuple<int, int, int> > queries;
        while (cpy--) {
            int a, b, c;
            cin >> a >> b >> c;
            queries.push_back({a, b, c});
        }
        fenwickTree(n, v, q, queries);
    }
}