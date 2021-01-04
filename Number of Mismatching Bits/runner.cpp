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
    while (t--)

    {
        int a, b;
        cin >> a >> b;
        cout << numberOfMismatchingBits(a, b) << endl;
    }
}