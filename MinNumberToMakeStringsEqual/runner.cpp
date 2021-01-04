#include <iostream>
#include <queue>
#include <unordered_map>
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
        string i, f;
        cin >> i >> f;

        cout << minOperations(i, f) << endl;
    }
}