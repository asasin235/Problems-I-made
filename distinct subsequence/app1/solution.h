/*
	Time complexity: O(2 ^ N)
	Space complexity: O(N)

	where N is the length of the given string S

 */

// Recursive function to find the number of times the string T occurs in the string S
int numDistinctHelper(string S, string T, int n, int m) {
    // If both strings are empty, or if string T is empty, return 1
    if ((n == 0 && m == 0) || m == 0) {
        return 1;
    }

    // Return 0, if only string S is empty
    if (n == 0) {
        return 0;
    }

    // If last characters are same
    if (S[n - 1] == T[m - 1]) {
        /* Recur for remaining strings by
         1. Considering last characters of both strings
         2. Ignoring last character of first string */
        return numDistinctHelper(S, T, n - 1, m - 1) + numDistinctHelper(S, T, n - 1, m);
    }
    // If last characters are different
    else {
        // Recur for remaining string by ignoring last char of string S
        return numDistinctHelper(S, T, n - 1, m);
    }
}

int numDistinct(string S, string T) {
    return numDistinctHelper(S, T, S.length(), T.length());
}
