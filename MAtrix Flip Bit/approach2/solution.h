/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the sequence
*/

int countFlip(vector<vector<int> > &mat) {
    int n = mat.size();
    // Initialise both visited row and col as 0
    vector<bool> visitedRow(n, false), visitedCol(n, false);
    int count = 0;
    vector<pair<int, int> > s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                s.push_back(make_pair(i, j));
            }
        }
    }

    for (auto element : s) {
        // Fixing column
        if (visitedCol[element.second] == false) {
            for (int k = 0; k < n; k++) {
                if (mat[k][element.second] == 1) {
                    count++;
                    mat[k][element.second] = -1;
                }
                if (k == n - 1) visitedCol[element.second] = true;
            }
        }
        // Fixing row
        if (visitedRow[element.first] == 0) {
            for (int k = 0; k < n; k++) {
                if (mat[element.first][k] == 1) {
                    count++;
                    mat[element.first][k] = -1;
                }
                if (k == n - 1) visitedRow[element.first] = true;
            }
        }
    }
    return count;
}
