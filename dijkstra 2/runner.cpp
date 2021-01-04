#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // #ifndef ONLINE_JUDGE
    //     freopen("testcases/large/in/input1.txt", "r", stdin);
    //     freopen("testcases/large/out/output1.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int vertices, edges;
        cin >> vertices;
        cin >> edges;
        int u, v, distance;
        vector<vector<int> > vec;
        for (int i = 0; i < edges; i++) {
            vector<int> temp;
            cin >> u >> v >> distance;
            temp.push_back(u);
            temp.push_back(v);
            temp.push_back(distance);
            vec.push_back(temp);
        }
        vector<int> answer;
        answer = dijkstara(vec, vertices, edges, 0);
        for (auto it = answer.begin(); it != answer.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}