/*
    Time complexity: O(n)
    Space complexity: O(1)

    Where 'n' is the length of the string
*/

int romanToInt(string s) {
    int count = 0;
    int preInt = 0;  // to store previous char value
    //unordered map for finding interger value for roman numerals
    map<char, int> conv =
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};

    // Loop from end...starting
    for (int i = s.length() - 1; i >= 0; i--) {
        char ch = s[i];
        int curInt = conv[ch];  // Store current char integer value

        /* Value is greater or equal to previous value then increment count i.e., II means 1+1
           else in case of IV V=5 and I=1 here 1<5 then else part runs and 5-1=4 is the answer */

        if (curInt >= preInt) {
            count += curInt;
        } else {
            count -= curInt;
        }

        preInt = curInt;  // Update preInt value with current value for next iteration
    }
    return count;
}