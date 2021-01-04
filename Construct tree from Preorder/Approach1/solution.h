/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the binary tree
*/

BinaryTreeNode<int> *helper(vector<int> &pre, vector<int> &isLeaf, int *curIdxPtr) {
    int n = pre.size();
    int curIdx = *curIdxPtr;
    if (curIdx == n) {
        return NULL;
    }

    // Allocate memory for this node and increment index for subsequent recursive calls
    BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(pre[curIdx]);
    (*curIdxPtr)++;

    // If this is an internal node, construct left and right subtrees and link the subtrees
    if (isLeaf[curIdx] == 0) {
        temp->left = helper(pre, isLeaf, curIdxPtr);
        temp->right = helper(pre, isLeaf, curIdxPtr);
    }

    return temp;
}
BinaryTreeNode<int> *constructTree(vector<int> &pre, vector<int> &isLeaf) {
    int curIdxPtr = 0;
    return helper(pre, isLeaf, &curIdxPtr);
}