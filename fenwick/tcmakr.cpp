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

    int t;
    t = getRandomFromRange(7, 10);
    cout << t << endl;

    while (t--) {
        // int n = 1000;
        // cout<<2*n+1<<endl;
        // int arr[]={12345678,-12345678};
        // vector<int> last;
        // for(int i = 0; i < n; i++)
        // {

        //     int x=getRandomFromRange(1,987652);
        //     cout<<x<<" ";
        //     last.push_back(-1*x);
        // }
        // sort(last.begin(),last.end());
        // cout<<34<<" ";
        // for(int i=0;i<n;i++){
        //     cout<<last[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"-1\n";
        // int n = 4998;
        // cout << 2 * n + 3 << endl;
        // vector<int> v(n), last;
        // for (int i = 0; i < n; i++) {
        //   v[i] = getRandomFromRange(100000000, 1000000000);
        //   last.push_back(-1 * v[i]);
        // }
        // reverse(v.begin(), v.end());
        // sort(last.begin(), last.end(), greater<int>());
        // long long ans = 0;
        // int s = getRandomFromRange(1, 34569);
        // cout << s << " ";
        // for (int i = 0; i < n; i++) {
        //   ans += (v[i] + last[i]);
        //   cout << v[i] << " " << last[i] << " ";
        // }
        // cout << 45 << " " << s << endl;
        // *************************************************
        // cout << ans << endl;
        // string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // string q = "";
        // int n = 100;
        // char x = alphabets[getRandomFromRange(0, 25)];
        // for (int i = 0; i < n; i++)
        // {
        //     q += x;
        // }
        // cout << q << endl;
        // ****************************************************

        int n = getRandomFromRange(10000, 100000);
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << getRandomFromRange(-90000, 200000) << " ";
        }
        cout << endl;
        int q = getRandomFromRange(40000, 90000);
        cout << q << endl;
        while (q--) {
            int b, c;
            int a = getRandomFromRange(1, 2);
            if (a == 1) {
                b = getRandomFromRange(0, n - 2);
                c = getRandomFromRange(b, n - 1);
                // sum
            } else {
                b = getRandomFromRange(0, n - 1);
                c = getRandomFromRange(-3000, 300);  // any val
                // update
            }
            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}