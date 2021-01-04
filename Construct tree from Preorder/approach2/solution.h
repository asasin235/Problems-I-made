/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the binary tree
*/

BinaryTreeNode<int> *constructTree(vector<int> &pre, vector<int> &isLeaf) {
    int n = pre.size();
    // Stack for Construction
    stack<BinaryTreeNode<int> *> stk;
    // Initialise root to null
    BinaryTreeNode<int> *root = NULL;

    for (int i = 0; i < n; i++) {
        if (root == NULL) {
            root = new BinaryTreeNode<int>(pre[i]);
            if (isLeaf[i] == 0) {
                stk.push(root);
            }

        } else {
            BinaryTreeNode<int> *t = new BinaryTreeNode<int>(pre[i]);

            if (!stk.empty()) {
                if (stk.top()->left == NULL)
                    stk.top()->left = t;
                else {
                    stk.top()->right = t;
                    stk.pop();
                }
                if (isLeaf[i] == 0) {
                    stk.push(t);
                }
            }
        }
    }
    return root;
}