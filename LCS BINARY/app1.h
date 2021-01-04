/*
    Time complexity: O(n)
    Space complexity: O(n)

    Where 'n' is the number of elements int the binary tree.
*/

int maxPath(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }

    queue<BinaryTreeNode<int>*> nodeQueue;
    queue<int> sizeQueue;

    nodeQueue.push(root);
    sizeQueue.push(1);
    int mx = 1;

    while (!nodeQueue.empty()) {
        BinaryTreeNode<int>* head = nodeQueue.front();
        nodeQueue.pop();
        int size = sizeQueue.front();
        sizeQueue.pop();

        if (head->left != NULL) {
            int leftSize = size;
            if (head->data == head->left->data - 1) {
                leftSize++;
                mx = max(mx, leftSize);
            } else {
                leftSize = 1;
            }

            nodeQueue.push(head->left);
            sizeQueue.push(leftSize);
        }

        if (head->right != NULL) {
            int rightSize = size;
            if (head->data == head->right->data - 1) {
                rightSize++;
                mx = max(mx, rightSize);
            } else {
                rightSize = 1;
            }

            nodeQueue.push(head->right);
            sizeQueue.push(rightSize);
        }
    }

    return mx;
}