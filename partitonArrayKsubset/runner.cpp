#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "solution.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (auto &i : arr) {
            cin >> i;
        }

        if (splitArray(arr, k)) {
            cout << "TRUE\n";
        } else
            cout << "FALSE\n";
    }
    return 0;
}