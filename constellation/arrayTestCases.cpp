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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));

    int t;
    t = 50;
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
        char arr[6][3][3];
        // a=0 .... #=5

        arr[0][0][0] = '.';
        arr[0][0][1] = '*';
        arr[0][0][2] = '.';
        arr[0][1][0] = '*';
        arr[0][1][1] = '*';
        arr[0][1][2] = '*';
        arr[0][2][0] = '*';
        arr[0][2][1] = '.';
        arr[0][2][2] = '*';
        arr[1][0][] int n = 9999;
        cout << n << endl;
        vector<int> v;
        for (int i = 0; i < 50; i++) {
            v.push_back(getRandomFromRange(1000000, 10000000));
        }
        vector<int> v1 = v;
        reverse(v1.begin(), v1.end());
        for (int i = 0; i < 99; i++) {
            for (auto i : v) {
                cout << i << " ";
            }

            for (auto i : v1) {
                cout << -1 * i << " ";
            }
            cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}