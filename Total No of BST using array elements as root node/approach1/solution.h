/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the sequence
*/

const int mod = (int)1e9 + 7;
// Multiplication of big numbers under mod
int multiply(int a, int b, int mod) {
    int res = 0;  // Initialize result

    /* Update a if it is more than
     or equal to mod */

    a %= mod;

    while (b) {
        // If b is odd, add a with result
        if (b & 1) {
            res = (res + a) % mod;
        }

        /* Here we assume that doing 2*a
           doesn't cause overflow */
        a = (2 * a) % mod;

        b >>= 1;  // b = b / 2
    }

    return res;
}
int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;  // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int modInverse(int b, int m) {
    int x, y;  // Used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1) {
        return -1;
    }
    // m is added to handle negative x
    return (x % m + m) % m;
}

// Returns catalan(n) % 1e9+7

int fact(int num) {
    int fact = 1;

    while (num > 1) {
        fact = multiply(fact, num, mod);
        num -= 1;
    }
    return fact;
}

// Find nth catalan number
int catalan(int n) {
    return multiply(multiply(fact(2 * n), modInverse(fact(n + 1), mod), mod), modInverse(fact(n), mod), mod);
}
vector<int> totalBST(vector<int> arr) {
    vector<int> ans;
    int n = arr.size();
    int i, k;
    for (k = 0; k < n; k++) {
        int s = 0;

        // Count the number of element less than current element in arr[k]
        for (i = 0; i < n; i++) {
            if (arr[i] < arr[k])
                s += 1;
        }

        /* Here s = number of node in left
         BST and (n-s-1) = number of node
         in right BST
         Find number of BST using elements
         in left BST */

        int catalan_leftBST = catalan(s);

        // Find number of BST using elements in right BST
        int catalan_rightBST = catalan(n - s - 1);

        // Find total number of BST
        int totalBST = multiply(catalan_rightBST, catalan_leftBST, mod);

        // add total BST count to answer array
        ans.push_back(totalBST);
    }
    return ans;
}
