#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
#ifndef ONLINE_JUDGE
    freopen("testcases/large/in/input1.txt", "r", stdin);
    freopen("testcases/large/out/output1.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;

        vector<int> v(n);

        for (auto &i : v) {
            cin >> i;
        }

        vector<int> ans = totalBST(v);
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}