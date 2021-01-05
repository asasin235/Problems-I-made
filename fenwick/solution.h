/*
    Time complexity: O(q*log(n))
    Space complexity: O(n)

    Where 'n' is the number of elements int the sequence and 'q' is the number of queries.
*/

void updateFenwick(vector<int> &fenwick, int n, int idx, int val) {
    // idx in fenwickTree[] is 1 more than the idx in arr[]
    idx = idx + 1;

    // Traverse all ancestors and add 'val'
    while (idx <= n) {
        // Add 'val' to current node of BI Tree
        fenwick[idx] += val;

        // Update idx to that of parent in update View
        idx += idx & (-idx);
    }
}

// Used to get sum from index 0 to the index passed
int getSum(vector<int> &fenwickTree, int index) {
    int sum = 0;  // Iniialize result

    // index in fenwickTree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of fenwickTree[index]
    while (index > 0) {
        // Add current element of fenwickTree to sum
        sum += fenwickTree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
void fenwickTree(int n, vector<int> &arr, int q, vector<tuple<int, int, int>> &queries) {
    // Write your code here.
    vector<int> fenwick(arr.size() + 1, 0);  // Fenwick tree

    // Generating the fenwick tree.
    for (int i = 1; i <= n; i++) {
        updateFenwick(fenwick, n, i, arr[i]);
    }
    // Processing the queries
    for (int i = 0; i < q; i++) {
        if (get<0>(queries[i]) == 1) {
            // Sum Query
            if (get<1>(queries[i]) == 0) {
                // If we need sum from first index to the given index
                cout << getSum(fenwick, get<2>(queries[i])) << endl;
            } else {
                cout << getSum(fenwick, get<2>(queries[i])) - getSum(fenwick, get<1>(queries[i]) - 1) << endl;
            }
        } else {
            updateFenwick(fenwick, n, get<1>(queries[i]), get<2>(queries[i]));
            // Range update query
        }
    }
}