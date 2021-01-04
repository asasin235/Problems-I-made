#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        DLLNode head = NULL;
        int data = 0;
        while (data != -1) {
            cin >> data;
            head = insert(head, data);
        }
        int x;
        cin >> x;
        cout << function(head, x);
    }
}