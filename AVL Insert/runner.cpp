// C++ program to insert a node in AVL tree
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// An AVL tree node
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    int height;
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

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

#include "solution.h"
void inOrder(BinaryTreeNode<int> *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        BinaryTreeNode<int> *root = takeInput();
        int toInsert;
        cin >> toInsert;
        root = insertIntoAvl(root, toInsert);

        inOrder(root);
        cout << endl;
    }

    return 0;
}
