/*
    Time complexity: O(n^2)
    Space complexity: O(n)

    Where 'n' is the number of elements int the binary tree.
*/

int maxSub(BinaryTreeNode<int> *root) {
    // Find maximum in a subtree
    return root == NULL ? INT_MIN : max(root->data, max(maxSub(root->left), maxSub(root->right)));
}

int minSub(BinaryTreeNode<int> *root) {
    // Find minimum in subtree
    return root == NULL ? INT_MAX : min(root->data, min(minSub(root->left), minSub(root->right)));
}

void helper(BinaryTreeNode<int> *root, int &result) {
    if (root == NULL) {
        return;
    }
    // Calculate max and min for left subtree
    if (root->left != NULL) {
        result = max(result, abs(root->data - minSub(root->left)));
        result = max(result, abs(root->data - maxSub(root->left)));
    }
    // Calculate max and min for right subtree
    if (root->right != NULL) {
        result = max(result, abs(root->data - minSub(root->right)));
        result = max(result, abs(root->data - maxSub(root->right)));
    }
    // Recursively calculate for all other nodes
    helper(root->left, result);
    helper(root->right, result);
}

int maxAncestorDiff(BinaryTreeNode<int> *root) {
    int result = 0;
    helper(root, result);
    return result;
}