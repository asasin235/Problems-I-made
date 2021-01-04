/*
    Time complexity: O(n^n)
    Space complexity: O(n)

    Where 'n' is equal to number of elements in the sequence.
*/

int minJumpsHelper(vector<int>& arr, int currIdx) {
    // Base case
    if (currIdx >= arr.size() - 1) {
        return 0;
    }
    int minJump = 999999;  // Initialised with a very large value
    int currAns = 0;       // To store the answer for every index

    // Recursively find all possible combinations of jumps.
    for (int i = 1; i <= arr[currIdx]; i++) {
        if  currIdx + i <= arr.size() - 1) {
                currAns = 1 + minJumpsHelper(arr, currIdx + i);
            }
        minJump = min(currAns, minJump);
    }
    return minJump;
}

int minJumps(vector<int>& arr) {
    return minJumpsHelper(arr, 0);
}
