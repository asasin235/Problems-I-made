/*
    Time Complexity: O(log(n))
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the binary tree
*/

int findStackSum(stack<int> stk) {
    // Find the sum of stacks
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
    // Sum of all 3 stacks
    int stk1Sum = findStackSum(stk1);
    int stk2Sum = findStackSum(stk2);
    int stk3Sum = findStackSum(stk3);

    vector<int> stk1AllSums, stk2AllSums, stk3AllSums;
    stk1AllSums.push_back(stk1Sum);
    stk2AllSums.push_back(stk2Sum);
    stk3AllSums.push_back(stk3Sum);

    // All possible sums for the 3 stacks
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

    for (int i = 0; i < stk1AllSums.size(); i++) {
        for (int j = 0; j < stk2AllSums.size(); j++) {
            for (int k = 0; k < stk3AllSums.size(); k++) {
                if (stk1AllSums[i] == stk2AllSums[j] and stk2AllSums[j] == stk3AllSums[k]) {
                    // The first time we get an answer it guaranteed to be the best coz we will have all 3 arrays in descending order.
                    return stk1AllSums[i];
                }
            }
        }
    }
    // If no answer return 0
    return 0;
}