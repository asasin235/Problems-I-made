#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

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

using namespace std;
#include "app1.h"

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;

    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;

    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;

        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("testcases/large/in/input10.txt", "r", stdin);
    freopen("testcases/large/out/output10.txt", "w", stdout);
#endif
    // #ifndef ONLINE_JUDGE
    //     freopen("input12.txt", "r", stdin);
    //     freopen("output12.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;

    while (t--) {
        BinaryTreeNode<int> *root = takeInput();
        cout << maxPath(root) << endl;
    }
}