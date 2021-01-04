/*
    Time Complexity: O(2^n)
    Space Complexity: O(n)

    Where 'n' is the length of the string to be created.
*/

void generateStringHelper(int K, string &str, int n, vector<string> &ans) {
    // Print binary string without consecutive 1's
    if (n == K) {
        // Terminate binary string ans push in answer
        ans.push_back(str);

        return;
    }

    /* If previous character is '1' then we put
       Only 0 at end of string
       Example str = "01" then new string be "010" */

    if (str[n - 1] == '1') {
        str[n] = '0';
        generateStringHelper(K, str, n + 1, ans);
    }

    /* If previous character is '0' than we put
       Both '1' and '0' at end of string
       Example str = "00" then new  string "001" and "000" */

    if (str[n - 1] == '0') {
        str[n] = '0';
        generateStringHelper(K, str, n + 1, ans);
        str[n] = '1';
        generateStringHelper(K, str, n + 1, ans);
    }
}

vector<string> generateString(int K) {
    vector<string> ans;
    // If K=0 no binary strings are possible, hence we return empty array
    if (K == 0) {
        return ans;
    }
    // A string with K elements
    string str(K, '0');
    // First charecter 0
    str[0] = '0';
    generateStringHelper(K, str, 1, ans);
    // First charecter 1
    str[0] = '1';
    generateStringHelper(K, str, 1, ans);
    sort(ans.begin(), ans.end());

    return ans;
}
