#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "solution.h"
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        cout << numDistinct(s1, s2) << endl;
    }
}