/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the sequence
*/

// Function to return the minimum number of operations to convert string initial to final
int minOperations(string initial, string final) {
    // If both the strings are equal then
    // no operation needs to be performed
    if (initial == final)
        return 0;

    unordered_map<string, int> nodes;

    int n;

    n = initial.length();
    int pos = 0;
    for (int i = 0; i < initial.length(); i++) {
        if (initial[i] == '_') {
            // Store the position of '_'
            pos = i;
            break;
        }
    }

    // To store the generated string at every move and the position of '_' within it
    queue<pair<string, int> > q;

    q.push(make_pair(initial, pos));

    // Nodes will store the minimum operations to reach that particular string
    nodes[initial] = 0;

    while (!q.empty()) {
        string currStr = q.front().first;
        int currPos = q.front().second;

        // Minimum moves to reach the string currStr
        int dist = nodes[currStr];
        q.pop();

        // Try all 4 possible operations

        // If '_' can be swapped with the character on it'initial left
        if (currPos > 0) {
            // Swap with the left character
            swap(currStr[currPos], currStr[currPos - 1]);

            // If the string is generated for the first time

            if (!nodes.count(currStr)) {
                // If generated string is the required string

                if (currStr == final) {
                    return dist + 1;
                    break;
                }

                // Update the distance for the currently generated string
                nodes[currStr] = dist + 1;
                q.push(make_pair(currStr, currPos - 1));
            }

            // Restore the string before it was swapped to check other cases
            swap(currStr[currPos], currStr[currPos - 1]);
        }

        // Swap '_' with the character on it'initial right this time
        if (currPos < n - 1) {
            swap(currStr[currPos], currStr[currPos + 1]);
            if (!nodes.count(currStr)) {
                if (currStr == final) {
                    return dist + 1;
                    break;
                }
                nodes[currStr] = dist + 1;
                q.push(make_pair(currStr, currPos + 1));
            }
            swap(currStr[currPos], currStr[currPos + 1]);
        }

        // If '_' can be swapped with the character 'i-2'
        if (currPos > 1 && currStr[currPos - 1] != currStr[currPos - 2]) {
            swap(currStr[currPos], currStr[currPos - 2]);
            if (!nodes.count(currStr)) {
                if (currStr == final) {
                    return dist + 1;
                    break;
                }
                nodes[currStr] = dist + 1;
                q.push(make_pair(currStr, currPos - 2));
            }
            swap(currStr[currPos], currStr[currPos - 2]);
        }

        // If '_' can be swapped with the character at 'i+2'
        if (currPos < n - 2 && currStr[currPos + 1] != currStr[currPos + 2]) {
            swap(currStr[currPos], currStr[currPos + 2]);
            if (!nodes.count(currStr)) {
                if (currStr == final) {
                    return dist + 1;
                    break;
                }
                nodes[currStr] = dist + 1;
                q.push(make_pair(currStr, currPos + 2));
            }
            swap(currStr[currPos], currStr[currPos + 2]);
        }
    }
}
