/*
    Time Complexity: O(log(n))
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the binary tree
*/

// Function to get height
int height(BinaryTreeNode<int> *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

BinaryTreeNode<int> *rightRotate(BinaryTreeNode<int> *x) {
    BinaryTreeNode<int> *leftSubTreeRoot = x->left;
    BinaryTreeNode<int> *leftSubTreeRootRightChild = leftSubTreeRoot->right;

    // Perform rotation
    leftSubTreeRoot->right = x;
    x->left = leftSubTreeRootRightChild;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    leftSubTreeRoot->height = max(height(leftSubTreeRoot->left), height(leftSubTreeRoot->right)) + 1;

    // Return new root
    return leftSubTreeRoot;
}

BinaryTreeNode<int> *leftRotate(BinaryTreeNode<int> *x) {
    BinaryTreeNode<int> *rightSubTreeRoot = x->right;
    BinaryTreeNode<int> *rightSubTreeRootLeftChild = rightSubTreeRoot->left;

    // Perform rotation
    rightSubTreeRoot->left = x;
    x->right = rightSubTreeRootLeftChild;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    rightSubTreeRoot->height = max(height(rightSubTreeRoot->left), height(rightSubTreeRoot->right)) + 1;

    // Return new root
    return rightSubTreeRoot;
}

// Get Balance factor of node N
int getBalance(BinaryTreeNode<int> *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

/* Given a non-empty binary search tree, 
return the node with minimum data value 
found in that tree. Note that the entire 
tree does not need to be searched. */
BinaryTreeNode<int> *minValueNode(BinaryTreeNode<int> *node) {
    BinaryTreeNode<int> *current = node;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Recursive function to delete a node
 with given data from subtree with
 given root. It returns root of the
 modified subtree. */
BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int data) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the data to be deleted is smaller than the root's data, then it lies in left subtree

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    // If the data to be deleted is greater than the root's data, then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // if data is same as root's data, then this is the node to be deleted
    else {
        // node with only one child or no child
        if ((root->left == NULL) ||
            (root->right == NULL)) {
            BinaryTreeNode<int> *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else              // One child case
                *root = *temp;  // Copy the contents of
                                // the non-empty child
            free(temp);
        } else {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            BinaryTreeNode<int> *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    /* STEP 3: GET THE BALANCE FACTOR OF
     THIS NODE (to check whether this
     node became unbalanced) */
    int balance = getBalance(root);

    // If this node becomes unbalanced,then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
