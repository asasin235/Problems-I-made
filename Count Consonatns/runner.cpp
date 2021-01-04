#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
#ifndef ONLINE_JUDGE
    freopen("TestCases/large/in/input6.txt", "r", stdin);
    freopen("TestCases/large/out/output6.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)

    {
        string s;
        getline(std::cin >> std::ws, s);
        //cout << s << endl;
        cout << countConsonants(s) << endl;
    }
}