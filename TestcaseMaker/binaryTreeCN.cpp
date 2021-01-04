#include <bits/stdc++.h>
using namespace std;

//========================================================

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

//========================================================

// use this to get a random number from range [l, r] except -1
int getRandomFromRange(int l, int r)
{
    int x = (l + ((rand() * rand()) % (r - l + 1)));
    
    while(x == -1) x = (l + ((rand() * rand()) % (r - l + 1)));

    return x;
}


//========================================================

/*
    Return the string representing the BST
    with n nodes where every node is from
    the range [l, r]
    Note that the number of integers in
    the range [l, r] must be >= n
*/
string generateBST(int n, int l, int r)
{
    string str = "";

    queue<pair<int, pair<int, int>>> queue;

    // Create the root node
    int root = getRandomFromRange(l, r);

    // Add the root node and its
    // range in the queues
    queue.push(make_pair(root, make_pair(l, r)));

    str += (to_string(root) + " ");

    // Number of nodes in the current tree
    int valid = 1;

    while (!queue.empty())
    {

        // Get the current node
        pair<int, pair<int, int>> currNode = queue.front();
        queue.pop();

        // If the tree has been generated
        if (valid >= n)
            break;

        // If the left node is not possible
        if (currNode.first == currNode.second.first)
        {
            str += "N ";
        }
        else
        {

            // Generate the left child
            int leftChild = getRandomFromRange(currNode.second.first, currNode.first - 1);

            // Add the left child and its range to the queue
            queue.push(make_pair(leftChild, make_pair(currNode.second.first, currNode.first - 1)));

            str += (to_string(leftChild) + " ");
            valid++;
        }

        // If the tree has been generated
        if (valid >= n)
            break;

        // If the right node is not possible
        if (currNode.first == currNode.second.second)
        {
            str += "N ";
        }
        else
        {

            // Generate the right child
            int rightChild = getRandomFromRange(currNode.first + 1, currNode.second.second);

            // Add the left child and its range to the queue
            queue.push(make_pair(rightChild, make_pair(currNode.first + 1, currNode.second.second)));
            str += (to_string(rightChild) + " ");
            valid++;
        }
    }
    str += "\n";
    return str;
}

//========================================================

// Return the string representing the binary tree with
// n nodes where every node is from the range [l, r]
string generalTreeDuplicates(int n, int l, int r, int factor)
{
    string str = "";

    // To store the count of total nodes including
    // null children of every valid node
    int count = 2;

    // To store the count of all valid nodes
    int valid = 1;

    // Generate the root node to the queue
    int root = getRandomFromRange(l, r);
    str += (to_string(root) + " ");

    while (valid < n)
    {

        // Time to hit null
        if ((count % factor) == 0)
        {
            str += "N ";
        }

        // Generate the left child
        else
        {

            // Get a random value for the left child
            int leftChild = getRandomFromRange(l, r);
            str += (to_string(leftChild) + " ");

            // Increment the count of valid nodes
            valid++;
        }

        // A node has been added
        count++;

        // If the tree has been generated
        if (valid >= n)
            break;

        // Time to hit null
        if ((count % factor) == 0)
        {
            str += "N ";
        }

        // Generate the right child
        else
        {

            // Get a random value for the right child
            int rightChild = getRandomFromRange(l, r);
            str += (to_string(rightChild) + " ");

            // Increment the count of valid nodes
            valid++;
        }

        // Another node has been added
        count++;
    }
    str += "\n";
    return str;
}

//========================================================

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

//========================================================

void storeNodesInOrder(Node *root, vector<Node *> &inOrder)
{
    if (!root)
        return;

    storeNodesInOrder(root->left, inOrder);
    inOrder.push_back(root);
    storeNodesInOrder(root->right, inOrder);
}

//========================================================

string toString(Node *root)
{
    if (root == nullptr)
        return "N\n";

    string str;
    queue<Node *> qq;
    qq.push(root);

    while (!qq.empty())
    {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr)
        {
            str += "N ";
            continue;
        }
        str += (to_string(curr->data) + " ");
        qq.push(curr->left);
        qq.push(curr->right);
    }
    str += "\n";
    return str;
}

//========================================================

void addLeaf(Node *root)
{
    if (!root->left)
    {
        root->left = new Node(rand() % 100);
    }
    if (!root->right)
    {
        root->right = new Node(rand() % 100);
    }
}

//========================================================

int N = 5000, MAXI = 100;
// N means numebr of nodes will be from 1 to N
//MAXI means value of each nodes will be from 1 to MAXI

//========================================================
void bfs(Node *root)
{

    queue<pair<Node *, int>> q;

    q.emplace(root, 0);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            pair<Node *, int> n = q.front();
            q.pop();
            // cout<<"( "<<n.first->data<<" "<<n.second<<" )"<<" ";
            cout << n.first->data << " ";
            if (n.first->left != NULL)
                q.emplace(n.first->left, n.second - 1);
            else
            {
                cout << -1 << " ";
            }

            if (n.first->right != NULL)
                q.emplace(n.first->right, n.second + 1);
            else
            {
                cout << -1 << " ";
            }
        }
        // cout << endl;
    }
}

//=========================================================

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(nullptr));

    int tc = 100;
    cout << tc << "\n";

    while (tc--)
    {
        int n = rand() % N + 1;
        int l = 1;
        int r = MAXI;

        // factor = 2 for skewed trees
        int factor = 2 + rand() % n;

        // auto treeString = generateBST(n, l, r);
        auto treeString = generalTreeDuplicates(n, l, r, factor);
        // cout << treeString << endl;
        Node *root = buildTree(treeString);
        bfs(root);
        cout << "\n";
        // cout << "~\n";
    }
    return 0;
}

