/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the sequence
*/

vector<int> findEquilibriumIndices(vector<int> &sequence) {
    int n = sequence.size();
    // Make prefix sum and suffix sum arrays and answer array
    vector<int> prefixSum(n), suffixSum(n), ans;

    prefixSum[0] = sequence[0];
    suffixSum[n - 1] = sequence[n - 1];

    // Calculate 'prefixSum' for all indices

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + sequence[i];
    }
    // Calculate 'suffixSum' for all indices

    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + sequence[i];
    }
    for (int i = 0; i < n; i++) {
        // Special case the first and last element

        if (i == 0) {
            if (suffixSum[1] == 0) {
                ans.push_back(i);
            }
        } else if (i == n - 1) {
            if (prefixSum[n - 2] == 0) {
                ans.push_back(i);
            }
        } else {
            // Otherwise if 'prefixSum[i-1]' is equal to 'suffixSum[i+1]' include the index in answer

            if (prefixSum[i - 1] == suffixSum[i + 1]) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}