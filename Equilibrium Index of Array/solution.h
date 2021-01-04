/*
    Time complexity: O(n^2)
    Space complexity: O(1)

    Where 'n' is equal to number of elements in the sequence.
*/

vector<int> findEquilibriumIndices(std::vector<int> &v) {
    // An integer to store number of elements
    int n = v.size();

    // Answer vector
    vector<int> ans;

    //  Try to find equilibrium element
    for (int i = 0; i < n; i++) {
        int leftSum = 0, rightSum = 0;

        // Find left sum
        for (int j = 0; j < i; j++) {
            leftSum += v[j];
        }

        // Find right sum
        for (int j = i + 1; j < n; j++) {
            rightSum += v[j];
        }

        // If left is equal to right put it in result
        if (leftSum == rightSum) {
            ans.push_back(i);
        }
    }

    return ans;
}