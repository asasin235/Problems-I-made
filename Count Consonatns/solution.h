/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the length of the string.
*/

// Iterative implementation
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
int countConsonants(string str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isConsonant(str[i])) {
            count++;
        }
    }
    return count;
}