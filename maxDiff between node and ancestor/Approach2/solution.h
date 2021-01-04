/*
    Time complexity: O(n)
    Space complexity: O(n)

    Where 'n' is the number of elements int the binary tree.
*/

int helper(BinaryTreeNode<int>* root, int curMin, int curMax) {
    if (root == NULL) {
        return curMax - curMin;
    }

    curMax = max(root->data, curMax);
    curMin = min(root->data, curMin);

    int leftSubTree = helper(root->left, curMin, curMax);
    int rightSubTree = helper(root->right, curMin, curMax);

    return max(leftSubTree, rightSubTree);
}

int maxAncestorDiff(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }

    return helper(root, root->data, root->data);
}