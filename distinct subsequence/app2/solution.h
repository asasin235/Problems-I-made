/*
	Time complexity: O(M * N)
	Space complexity: O(M * N)

	where M, N are the length of the given strings

 */

// Recursive function to find the number of times
// the string T occurs in the string S
int numDistinct(string S, string T) {
    int m = T.size();
    int n = S.size();

    // T can't appear as a subsequence in S
    if (m > n) {
        return 0;
    }

    // dp[i][j] stores the count of
    // occurrences of T(1..i) in S(1..j)

    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    // Initializing first column with
    // all 0s. An empty string can't have
    // another string as subsequence
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 0;
    }

    // Initializing first row with all 1s
    // An empty string is subsequence of all
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    // Fill dp[][] in bottom up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If last characters don't match,
            // then value is same as the value
            // without last character in S.
            if (T[i - 1] != S[j - 1]) {
                dp[i][j] = dp[i][j - 1];
            }

            // Else value is obtained considering two cases
            // a) All substrings without last character in S
            // b) All substrings without last characters in both
            else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}
