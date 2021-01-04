#include <iostream>
#include <vector>

using namespace std;

#include "solution.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

        cout << minJumps(v) << endl;
    }
}