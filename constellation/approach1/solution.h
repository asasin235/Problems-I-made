/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of columns in the matrix
*/

string generateConstellations(int curIdx, vector<vector<char> >& universe, int n) {
    if (curIdx >= n) {
        // If we are at last index
        return "";
    }
    if (universe[0][curIdx] == '#' && universe[1][curIdx] == '#' && universe[2][curIdx] == '#') {
        // If it is a row of hashes
        return "#" + generateConstellations(curIdx + 1, universe, n);

    } else if (universe[0][curIdx] == '.' && universe[1][curIdx] == '.' && universe[2][curIdx] == '.') {
        // If it is a row of dots
        return generateConstellations(curIdx + 1, universe, n);

    } else if (curIdx + 2 < n and universe[0][curIdx] == '.' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '.' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '*' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '.' && universe[2][curIdx + 2] == '*') {
        // If the 3x3 matrix has an A
        return "A" + generateConstellations(curIdx + 3, universe, n);

    } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '*' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
        // If the 3x3 matrix has an E
        return "E" + generateConstellations(curIdx + 3, universe, n);

    } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '.' && universe[1][curIdx + 1] == '*' && universe[1][curIdx + 2] == '.' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
        // If the 3x3 matrix has an I
        return "I" + generateConstellations(curIdx + 3, universe, n);

    } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '.' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
        // If the 3x3 matrix has an O
        return "O" + generateConstellations(curIdx + 3, universe, n);

    } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '.' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '.' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
        // If the 3x3 matrix has an U
        return "U" + generateConstellations(curIdx + 3, universe, n);

    } else {
        // Anything else
        return generateConstellations(curIdx + 1, universe, n);
    }
}

string constellations(vector<vector<char> >& universe, int n) {
    return generateConstellations(0, universe, n);
}