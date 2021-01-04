#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;

    Node *next;
    Node(int data) {
        this->data = data;

        this->next = NULL;
    }
};
Node *takeinput() {
    int x, y;
    Node *head = NULL, *tail = NULL;
    cin >> x;
    if (x == -1) {
        return head;
    }

    while (1) {
        Node *newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> x;
        if (x == -1) {
            break;
        }
    }

    return head;
}
#include "solution.h"
int main() {
#ifndef ONLINE_JUDGE
    freopen("testcases/large/in/input9.txt", "r", stdin);
    freopen("testcases/large/out/output9.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)

    {
        int data = 0;
        // cin >> data;
        Node *head;
        head = takeinput();

        Node *ans = findMiddle(head);
        if (ans == NULL)
            cout << -1 << endl;
        else
            cout << ans->data << endl;
    }
    return 0;
}
