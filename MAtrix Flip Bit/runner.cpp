#include <iostream>
#include <set>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("testcases/large/in/input11.txt", "r", stdin);
    freopen("testcases/large/out/output11.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;

        vector<vector<int> > v(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        cout << countFlip(v) << endl;
    }
}