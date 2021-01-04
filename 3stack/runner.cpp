#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> takeInput() {
    int x;

    cin >> x;
    stack<int> st;

    while (1) {
        st.push(x);
        cin >> x;
        if (x == -1) {
            break;
        }
    }
    return st;
}
#include "solution.h"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x = 0;

        stack<int> stk1 = takeInput(), stk2 = takeInput(), stk3 = takeInput();

        cout << maxSum(stk1, stk2, stk3) << endl;
    }
}