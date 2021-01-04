/*
    Time Complexity: O(log(n))
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the binary tree
*/

int findStackSum(stack<int> stk) {
    // Function to find stack sum
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
    // Find sum of all 3 stacks
    int stk1Sum = findStackSum(stk1);
    int stk2Sum = findStackSum(stk2);
    int stk3Sum = findStackSum(stk3);

    vector<int> stk1AllSums, stk2AllSums, stk3AllSums;
    stk1AllSums.push_back(stk1Sum);
    stk2AllSums.push_back(stk2Sum);
    stk3AllSums.push_back(stk3Sum);
    // Find all possible sum all three stacks
    while (!stk1.empty()) {
        stk1Sum -= stk1.top();
        stk1.pop();
        stk1AllSums.push_back(stk1Sum);
    }
    while (!stk2.empty()) {
        stk2Sum -= stk2.top();
        stk2.pop();
        stk2AllSums.push_back(stk2Sum);
    }
    while (!stk3.empty()) {
        stk3Sum -= stk3.top();
        stk3.pop();
        stk3AllSums.push_back(stk3Sum);
    }
    // Reversing to get ascending order.
    reverse(stk2AllSums.begin(), stk2AllSums.end());
    reverse(stk3AllSums.begin(), stk3AllSums.end());

    for (int i = 0; i < stk1AllSums.size(); i++) {
        if (binary_search(stk2AllSums.begin(), stk2AllSums.end(), stk1AllSums[i]) and binary_search(stk3AllSums.begin(), stk3AllSums.end(), stk1AllSums[i])) {
            // If the sum is present in both the stacks
            return stk1AllSums[i];
        }
    }
    // Otherwise return 0
    return 0;
}