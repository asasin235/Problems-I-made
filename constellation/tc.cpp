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
    freopen("testcases/large/in/input10.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    int t = 50 cout << t << endl;
    while (t--) {
        int n = 3000 cout << n << endl;
        int hashCnt = getRandomFromRange(0, 3);
        vector<string> first(6), second(6), third(6);
        //a
        first[0] = ". * . ";
        second[0] = "* * * ";
        third[0] = "* . * ";
        //e
        first[1] = "* * * ";
        second[1] = "* * * ";
        third[1] = "* * * ";
        //i
        first[2] = "* * * ";
        second[2] = ". * . ";
        third[2] = "* * * ";
        // o
        first[3] = "* * * ";
        second[3] = "* . * ";
        third[3] = "* * * ";
        // u
        first[4] = "* . * ";
        second[4] = "* . * ";
        third[4] = "* * * ";
        // $
        first[5] = "# ";
        second[5] = "# ";
        third[5] = "# ";
        vector<int> v;
        while (n) {
            int x = getRandomFromRange(0, 5);
            if (x == 5)
                n--;
            else if (n <= 2) {
                x = 5;
                n--;
            } else
                n -= 3;
            v.push_back(x);
        }
        for (auto i : v) {
            cout << first[i];
        }
        cout << endl;
        for (auto i : v) {
            cout << second[i];
        }
        cout << endl;
        for (auto i : v) {
            cout << third[i];
        }
        cout << endl;
    }
}