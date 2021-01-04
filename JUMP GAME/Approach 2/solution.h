/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the sequence
*/

int minJumpsHelper(vector<int>& arr, int currIdx, vector<int>& dp) {
    // Base Case
    if (currIdx >= arr.size() - 1) {
        return 0;
    }
    // If answer already calculated, return it immidiately
    if (dp[currIdx] != -1) {
        return dp[currIdx];
    }
    int minJumps = 999999;  // Initialised with a very large value
    int currentAns = 0;
    // Calculate answer recursively
    for (int i = 1; i <= arr[currIdx]; i++) {
        if (currIdx + i <= arr.size() - 1) {
            currentAns = 1 + minJumpsHelper(arr, currIdx + i, dp);
        }
        minJumps = min(currentAns, minJumps);
        // Store the calculated answer in the dp array.
        dp[currIdx] = minJumps;
    }
    return minJumps;
}
int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);

    return minJumpsHelper(arr, 0, dp);
}
