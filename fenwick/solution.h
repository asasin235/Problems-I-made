/*
    Time complexity: O(q*log(n))
    Space complexity: O(n)

    Where 'n' is the number of elements int the sequence and 'q' is the number of queries.
*/

class FenwickTree {
    public:
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void update(int idx,int val,vector<int> &arr){
        add(idx,val-arr[idx]);
        arr[idx]=val;
    }

    void add(int idx, int delta) {

        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
void fenwickTree(int n, vector<int> &arr, int q, vector<tuple<int, int, int>> &queries) {
    // Write your code here.
    // Initialised Fenwick tree using array
    FenwickTree tree(arr);
    
   

    // Processing the queries
    for (int i = 0; i < q; i++) {
        if (get<0>(queries[i]) == 1) {
            // Sum Query
           
                cout<<tree.sum(get<1>(queries[i]),get<2>(queries[i]))<<endl;
            
        } else {
            tree.update( get<1>(queries[i]), get<2>(queries[i]),arr);
            // Range update query
        }
    }
}