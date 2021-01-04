/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the length of the string.
*/

// Recursive implementation
bool isConsonant(char c) {
    // If space
    if (c == ' ') {
        return false;
    }

    // Make the charecter uppercase.
    c = toupper(c);
    if (c != 'A' and c != 'E' and c != 'I' and c != 'O' and c != 'U') {
        return true;
    }

    return false;
}
int countConsonantsHelper(string str, int n) {
    if (n == 1) {
        return isConsonant(str[0]);
    }
    return isConsonant(str[n - 1]) + countConsonantsHelper(str, n - 1);
}
int countConsonants(string str) {
    return countConsonantsHelper(str, str.length());
}