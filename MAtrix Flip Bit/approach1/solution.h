/*
    Time Complexity: O(n^3)
    Space Complexity: O(1)

    Where 'n' is the number of elements in the sequence
*/

int countFlip(vector<vector<int> > &mat) {
    int n = mat.size();

    // Mark the flipped bits as -1 and increment count
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                // Use 'k' as a variable to iterate through row and column
                for (int k = 0; k < n; k++) {
                    // Check every column
                    if (mat[i][k] == 1) {
                        count++;
                        mat[i][k] = -1;
                    }
                    // Check every row
                    if (mat[k][j] == 1) {
                        count++;
                        mat[k][j] = -1;
                    }
                }
            }
        }
    }
    return count;
}