/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)

    Where 'n' is the number of elements in the sequence
*/

int maxArea(vector<int>& height) {
    // Number of elements

    int n = height.size();

    // Variable to store max area initialised as a negative vlaue

    int globalMax = -1;

    // Loop through all starting indices

    for (int i = 0; i < n; i++) {
        // Fix a ending index for each starting index

        for (int j = n - 1; j > i; j--) {
            // Calculate area

            int area = (j - i) * min(height[i], height[j]);

            // Compare it with overall best area.

            globalMax = max(globalMax, area);
        }
    }
    return globalMax;
}