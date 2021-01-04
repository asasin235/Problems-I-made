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
    int t;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;

        vector<string> res = generateString(n);
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }

    // #ifndef ONLINE_JUDGE
    //     cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
    // #endif
}