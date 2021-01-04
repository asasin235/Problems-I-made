/*
    Time complexity: O(n)
    Space complexity: O(n)

    Where 'n' is the number of elements int the binary tree.
*/

void maxPathHelper(BinaryTreeNode<int> *root, int currentLength, int expected, int &globalMax) {
    if (root == NULL) {
        return;
    }

    // If root data has one more than its parent then increase current length

    if (root->data == expected) {
        currentLength++;
    } else {
        currentLength = 1;
    }

    //  Update the maximum by current length
    globalMax = max(globalMax, currentLength);

    // Recursively call left and right subtree with expected value 1 more than root data

    maxPathHelper(root->left, currentLength, root->data + 1, globalMax);
    maxPathHelper(root->right, currentLength, root->data + 1, globalMax);
}
int maxPath(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }

    int globalMax = 0;

    maxPathHelper(root, 0, root->data, globalMax);

    return globalMax;
}