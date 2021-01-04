/*
    Time Complexity: O(n)
    Space Complexity: O(1)

    Where 'n' is the number of columns in the matrix
*/

string constellations(vector<vector<char> >& universe, int n) {
    string str = "";
    int curIdx = 0;
    // Iterate over the whole loop
    while (curIdx < n) {
        if (universe[0][curIdx] == '#' && universe[1][curIdx] == '#' && universe[2][curIdx] == '#') {
            str += "#", curIdx++;
            continue;

        } else if (universe[0][curIdx] == '.' && universe[1][curIdx] == '.' && universe[2][curIdx] == '.') {
            curIdx++;
            continue;

        } else if (curIdx + 2 < n and universe[0][curIdx] == '.' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '.' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '*' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '.' && universe[2][curIdx + 2] == '*') {
            str += "A", curIdx += 3;
            continue;

        } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '*' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
            str += "E", curIdx += 3;
            continue;

        } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '.' && universe[1][curIdx + 1] == '*' && universe[1][curIdx + 2] == '.' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
            str += "I", curIdx += 3;
            continue;

        } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '*' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '.' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
            str += "O", curIdx += 3;
            continue;

        } else if (curIdx + 2 < n and universe[0][curIdx] == '*' && universe[0][curIdx + 1] == '.' && universe[0][curIdx + 2] == '*' && universe[1][curIdx] == '*' && universe[1][curIdx + 1] == '.' && universe[1][curIdx + 2] == '*' && universe[2][curIdx] == '*' && universe[2][curIdx + 1] == '*' && universe[2][curIdx + 2] == '*') {
            str += "U", curIdx += 3;
            continue;

        } else {
            curIdx++;
        }
    }

    return str;
}