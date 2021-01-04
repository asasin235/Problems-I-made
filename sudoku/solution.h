/*
	Time Complexity: O(9^(N*N))
	Space complexity: O(N*N)
	
	where N is the number of nodes in the tree
*/

bool isSafe(vector<vector<int>> &board, int c1, int row, int col) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        char t1 = board[row][i];
        if (t1 == c1)
            return false;
    }
    for (int i = 0; i < n; i++) {
        char t1 = board[i][col];
        if (t1 == c1)
            return false;
    }
    int rs = row - row % (int)sqrt(n);
    int cs = col - col % (int)sqrt(n);
    int nn = (int)sqrt(n);

    for (int i = rs; i < rs + nn; i++) {
        for (int j = cs; j < cs + nn; j++) {
            char t1 = board[i][j];
            if (t1 == c1)
                return false;
        }
    }
    return true;
}

vector<vector<int>> al2;

void solveSudokuUtil(vector<vector<int>> &board) {
    int row = -1;
    int col = -1;
    int n = board.size();
    int m = board[0].size();
    bool isEmpty = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                isEmpty = true;
                row = i;
                col = j;
                break;
            }
            if (isEmpty == true)
                break;
        }
    }
    if (!isEmpty) {
        for (int i = 0; i < n; i++) {
            vector<int> temp1 = board[i];
            al2.push_back(temp1);
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        char c1 = (char)(1 + i - 1);
        if (isSafe(board, c1, row, col)) {
            board[row][col] = c1;

            solveSudokuUtil(board);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveSudoku(vector<vector<int>> &board) {
    solveSudokuUtil(board);
    return al2;
}
