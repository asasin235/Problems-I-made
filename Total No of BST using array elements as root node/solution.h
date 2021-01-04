/*
    Time Complexity: O(nlogn)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the sequence
*/

const int mod = (int)1e9 + 7;
int multiply(int a, int b, int mod) {
    int res = 0;  // Initialize result

    // Update a if it is more than or equal to mod
    a %= mod;

    while (b) {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a doesn't cause overflow

        a = (2 * a) % mod;

        b >>= 1;  // b = b / 2
    }

    return res;
}
// Precompute the factorial
void calculateFactorials(vector<int> &factorial, int n) {
    factorial[1] = 1;
    factorial[0] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        factorial[i] = multiply(factorial[i - 1], i, mod);
    }
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

// Returns catalan(n) % mod using Fermat's little theorem.
int catalan(int n, vector<int> &factorial) {
    return multiply(multiply(factorial[2 * n], modInverse(factorial[n + 1], mod), mod), modInverse(factorial[n], mod), mod);
}

vector<int> totalBST(vector<int> &arr) {
    vector<int> ansArray;
    int n = arr.size();
    vector<int> factorial(2 * n + 1);
    calculateFactorials(factorial, n);
    vector<int> sortedCopy = arr;
    // Sort for efficient searching
    sort(sortedCopy.begin(), sortedCopy.end());

    // For each array element
    for (int k = 0; k < n; k++) {
        // Find the position of the current element in sorted oreder

        int pos = lower_bound(sortedCopy.begin(), sortedCopy.end(), arr[k]) - sortedCopy.begin();

        int lessThan, greaterThan;

        // No of elements less= pos
        lessThan = pos;

        // No of elements greater = n-pos-1
        greaterThan = n - pos - 1;
        // Find catalan number to the left and right
        int ansLeft = catalan(lessThan, factorial);

        int ansRight = catalan(greaterThan, factorial);

        int ans = multiply(ansLeft, ansRight, mod);

        ansArray.push_back(ans);
    }
    return ansArray;
}
