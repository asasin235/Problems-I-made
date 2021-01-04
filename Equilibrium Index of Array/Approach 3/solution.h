/*
    Time complexity: O(n)
    Space complexity: O(1)

    Where 'n' is the number of elements int the sequence.
*/

vector<int> findEquilibriumIndices(vector<int> &sequence) {
    // Integer to store size
    int n = sequence.size();

    // Answer vector

    vector<int> ans;
    int totalSum = 0;
    // find totalsum
    for (int i = 0; i < n; i++) {
        totalSum += sequence[i];
    }
    // Initially rightsum is equal to the total sum

    int leftSum = 0, rightSum = totalSum;

    for (int i = 0; i < n; i++) {
        // Subtract current element from right Sum

        rightSum -= sequence[i];

        // If left is equal to right put it in result

        if (leftSum == rightSum) {
            ans.push_back(i);
        }

        // Add current element to left sum before checking the next element

        leftSum += sequence[i];
    }

    return ans;
}