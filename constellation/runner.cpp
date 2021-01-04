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
        int n;
        cin >> n;
        vector<vector<char> > v(3, vector<char>(n));
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        cout << constellations(v, n) << endl;
    }
}