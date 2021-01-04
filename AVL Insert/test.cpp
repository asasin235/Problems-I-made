#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
   public:
    struct node *left;
    int data;
    struct node *right;
};
int getRandomFromRange(int l, int r) {
    int x = (l + ((rand()) % (r - l + 1)));
    return x;
}
node *newNode(int data) {
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node *createBalancedBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    node *root = newNode(arr[mid]);

    root->left = createBalancedBST(arr, start, mid - 1);

    root->right = createBalancedBST(arr, mid + 1, end);

    return root;
}

vector<int> createLevelOrder(node *root) {
    vector<int> answer;

    queue<node *> q1;

    q1.push(root);
    answer.push_back(root->data);

    while (!q1.empty()) {
        node *first = q1.front();

        if (first->left != NULL) {
            q1.push(first->left);
            answer.push_back(first->left->data);
        } else {
            answer.push_back(-1);
        }

        if (first->right != NULL) {
            q1.push(first->right);
            answer.push_back(first->right->data);
        } else {
            answer.push_back(-1);
        }

        q1.pop();
    }

    return answer;
}

node *createleftVtree(int arr[], int end) {
    if (0 > end)
        return NULL;

    node *root1 = newNode(arr[end]);

    root1->left = createleftVtree(arr, end - 1);

    return root1;
}

node *createSkewTree(int arr[], int end) {
    if (0 > end)
        return NULL;

    node *root = newNode(arr[end]);

    root->left = createSkewTree(arr, end - 1);

    return root;
}

node *createSkewRightTree(int arr[], int start, int end) {
    if (start >= end)
        return NULL;

    node *root = newNode(arr[start]);

    root->right = createSkewRightTree(arr, start + 1, end);

    return root;
}

node *createBT(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    node *root = newNode(arr[mid]);

    root->left = createBT(arr, start, mid - 1);

    root->right = createBT(arr, mid + 1, end);

    return root;
}

node *createrightVtree(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    node *root1 = newNode(arr[start]);

    root1->right = createrightVtree(arr, start + 1, end);

    return root1;
}
void mirrorTree(node *root) {
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    // Do BFS. While doing BFS, keep swapping
    // left and right children
    while (!q.empty()) {
        // pop top node from queue
        node *curr = q.front();
        q.pop();

        // swap left child with right child
        swap(curr->left, curr->right);

        // push left and right children
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
node *createAVLTree(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    node *root = newNode(arr[mid]);

    root->left = createBT(arr, start, mid - 1);

    root->right = createBT(arr, mid + 1, end);

    return root;
}
int main() {
    int t;

    //cout << "Enter TestCases ";
    t = 100;

    ofstream myfile("testcases/large/in/input10.txt");

    ofstream file("output.txt");

    myfile << t << endl;

    while (t--) {
        int n;

        //cout << endl

        //cin >> n;
        n = getRandomFromRange(2900, 2995);
        //if (!(n & 1)) n++;

        int maxValue = 100;

        int arr[n];

        for (int i = 0; i < n; i++) {
            int t = getRandomFromRange(-1000000000, 1000000000);
            if (t == -1) t++;
            arr[i] = t;
            //t++;
        }
        //
        //	cout<<" Press 1 for Balanced binary search tree "<<endl<<" Press 2 for binary tree "<<endl<<" Press 3 for V binary search tree "<<endl
        //	<<" Press 4 for V binary tree "<<endl<<" Press 5 for skew binary search tree "<<endl<<" Press 6 for skew left binary tree "<<endl<<
        //	" Press 7 for skew right binary tree "<<endl<< " Press 8 for skew right binary search tree "<<endl;
        int want = 9;
        //cin>> want;

        node *root = NULL;

        if (want == 1) {
            sort(arr, arr + n);
            root = createBalancedBST(arr, 0, n - 1);

        } else if (want == 2) {
            //	sort(arr, arr+n);
            root = createBT(arr, 0, n - 1);

        } else if (want == 3) {
            sort(arr, arr + n);
            int mid = (n - 1) / 2;
            root = newNode(arr[mid]);

            root->left = createleftVtree(arr, mid - 1);
            root->right = createrightVtree(arr, mid + 1, n - 1);

        } else if (want == 4) {
            int mid = (n - 1) / 2;
            root = newNode(arr[mid]);

            root->left = createleftVtree(arr, mid - 1);
            root->right = createrightVtree(arr, mid + 1, n - 1);

        } else if (want == 5) {
            sort(arr, arr + n);
            root = createSkewTree(arr, n - 1);

        } else if (want == 6) {
            root = createSkewTree(arr, n - 1);

        } else if (want == 7) {
            root = createSkewRightTree(arr, 0, n);
        } else if (want == 8) {
            sort(arr, arr + n);
            root = createSkewRightTree(arr, 0, n);
        } else if (want == 9) {
            sort(arr, arr + n);
            root = createAVLTree(arr, 0, n - 1);
        }
        //	node* BTroot = createBT(arr, 0, n-1);

        vector<int> levelOrder = createLevelOrder(root);

        /*	for(int i=0;i<levelOrder.size();i++){
	
		cout<<levelOrder[i]<<" ";
	
	}
	*/

        for (int i = 0; i < levelOrder.size(); i++) {
            if (levelOrder[i] == -1)
                myfile << levelOrder[i] << " ";
            else
                myfile << levelOrder[i] << " ";
        }

        myfile << endl;
        myfile << getRandomFromRange(-200000, 100000000) << endl;
        mirrorTree(root);
        vector<int> level = createLevelOrder(root);
        for (int i = 0; i < level.size(); i++) {
            if (level[i] == -1)
                file << level[i] << " ";
            else
                file << level[i] << " ";
        }

        file << endl;
    }

    myfile.close();
    file.close();
    return 0;
}