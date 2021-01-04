/*
	Time complexity: O(4^N/sqrt(N))
	Space complexity: O(4^N/sqrt(N))

	where N is the given number

 */

void printParanthesesHelper(string cur, int open, int close, int max) {
    if (cur.length() == (max * 2)) {
        cout << cur << endl;
        return;
    }

    if (open < max) {
        printParanthesesHelper(cur + "{", open + 1, close, max);
    }
    if (close < open) {
        printParanthesesHelper(cur + "}", open, close + 1, max);
    }
}

void printParantheses(int n) {
    string str = "";
    printParanthesesHelper(str, 0, 0, n);
}