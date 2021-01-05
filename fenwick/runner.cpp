#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#include "solution.h"
int main() {
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
        vector<tuple<int, int, int> > queries;
        while (q--) {
            int a, b, c;
            cin >> a >> b >> c;
            queries.push_back({a, b, c});
        }
    }
}