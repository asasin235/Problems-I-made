#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

// use this to get a random number from range [l, r]
int getRandomFromRange(int l, int r) {
    int x = (l + ((rand()) % (r - l + 1)));
    return x;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("testcases/small/in/input2.txt", "r", stdin);
    freopen("testcases/large/in/input6.txt", "w", stdout);

#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));

    int t;
    t = 50;
    cout << t << endl;

    for (int T = 1; T <= t; T++) {
        int n = getRandomFromRange(1000, 2000);
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            v[i] = getRandomFromRange(1000, 2000);
            cout << v[i] << " ";
        }
        cout << -1 << endl;
        ll sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += v[i];
        }
        for (int i = 0; i < 5; i++) {
            cout << sum / 6 << " ";
        }
        cout << (sum / 6) + sum % 6 << " ";
        int x = getRandomFromRange(50, 1000);
        for (int i = 0; i < x; i++) {
            cout << getRandomFromRange(1000, 2000) << " ";
        }

        cout << "-1\n";
        for (int i = 0; i < 5; i++) {
            cout << sum / 6 << " ";
        }
        cout << (sum / 6) + sum % 6 << " ";

        for (int i = 0; i < x; i++) {
            cout << getRandomFromRange(1000, 2000) << " ";
        }

        cout << "-1\n";
    }

    return 0;
}