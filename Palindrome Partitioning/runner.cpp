#include <limits.h>

#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        cout << palindromePartitioning(str) << endl;
    }
}