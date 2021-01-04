/*
    Time complexity: O(n)
    Space complexity: O(1)

    Where 'n' is the number of elements int the sequence.
*/

int minJumps(vector<int> &arr) {
    /* The variable 'curEnd stores the last index reachable from the current index
       'curFarthest storest the farthest index reachable */
    int minJump = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        // Update 'curFarthest'
        curFarthest = max(curFarthest, i + arr[i]);
        if (i == curEnd) {
            // Increment number of jumps if we reach the last reachable index
            minJump++;
            // Update the farthest index reachable
            curEnd = curFarthest;
        }
    }
    return minJump;
}