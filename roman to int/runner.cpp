#include <iostream>
#include <map>
#include <string>
using namespace std;
#include "solution.h"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        cout << romanToInt(n) << endl;
    }
}