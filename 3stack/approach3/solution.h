/*
    Time Complexity: O(log(n))
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the binary tree
*/

int findStackSum(stack<int> stk) {
    if (stk.empty()) {
        return 0;
    }
    int sum = 0;
    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    return sum;
}
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3) {
    int stk1Sum = findStackSum(stk1);
    int stk2Sum = findStackSum(stk2);
    int stk3Sum = findStackSum(stk3);

    while (1) {
        // If any stack is empty
        if (stk1.empty() || stk2.empty() || stk3.empty())
            return 0;

        // If sum of all three stack are equal.
        if (stk1Sum == stk2Sum && stk2Sum == stk3Sum)
            return stk1Sum;

        // Finding the stack with maximum sum and
        // removing its top element.
        if (stk1Sum >= stk2Sum && stk1Sum >= stk3Sum) {
            stk1Sum -= stk1.top();
            stk1.pop();
        } else if (stk2Sum >= stk1Sum && stk2Sum >= stk3Sum) {
            stk2Sum -= stk2.top();
            stk2.pop();
        } else if (stk3Sum >= stk2Sum && stk3Sum >= stk1Sum) {
            stk3Sum -= stk3.top();
            stk3.pop();
        }
    }
}
