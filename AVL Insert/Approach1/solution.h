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
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

BinaryTreeNode<int> *insertIntoAvl(BinaryTreeNode<int> *root, int data) {
    // 1. Perform the normal BST insertion
    if (root == NULL) {
        return (new BinaryTreeNode<int>(data));
    }

    if (data < root->data) {
        root->left = insertIntoAvl(root->left, data);
    } else if (data > root->data) {
        root->right = insertIntoAvl(root->right, data);
    } else  // Equal keys are not allowed in BST
    {
        return root;
    }

    // 2. Update height of this ancestor node
    root->height = 1 + max(height(root->left), height(root->right));

    /* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the node pointer
    return root;
}
