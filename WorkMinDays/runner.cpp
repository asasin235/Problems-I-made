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
    freopen("testcases/large/in/input10.txt", "r", stdin);
    freopen("testcases/large/out/output10.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;
        vector<int> D1(n), D2(n);
        for (auto &i : D1) {
            cin >> i;
        }
        for (auto &i : D2) {
            cin >> i;
        }

        cout << minDaysWork(D1, D2) << endl;
    }
}