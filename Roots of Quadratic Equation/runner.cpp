#include <algorithm>
#include <iomanip>
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
    freopen("testcases/large/out/output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)

    {
        int a, b, c;
        cin >> a >> b >> c;
        pair<int, int> ans = findRoots(a, b, c);
        if (ans.first > ans.second) {
            swap(ans.first, ans.second);
        }
        //cout << ans.first << " " << ans.second << endl;
        cout << ans.first << " " << ans.second << endl;
    }

    // #ifndef ONLINE_JUDGE
    //     cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
    // #endif
}