#include <iostream>
#include <vector>

using namespace std;

#include "solution.h"

int main() {
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

        cout << maxArea(v) << endl;
    }
}