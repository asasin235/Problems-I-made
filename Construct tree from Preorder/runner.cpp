#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
void printInorder(BinaryTreeNode<int> *node) {
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

#include "solution.h"
int main() {
#ifndef ONLINE_JUDGE
    freopen("TestCases/large/in/input6.txt", "r", stdin);
    freopen("TestCases/large/out/output6.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> isLeaf(n, 0);
        for (auto &i : v) {
            cin >> i;
        }
        for (int i = 0; i < n; i++) {
            cin >> isLeaf[i];
        }

        BinaryTreeNode<int> *root = constructTree(v, isLeaf);

        printInorder(root);
        cout << endl;
    }
}