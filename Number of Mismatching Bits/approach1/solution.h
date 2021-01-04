/*
    Time Complexity: O(1)
    Space Complexity: O(1)

    Where 'n' is the given number.
*/

int numberOfMismatchingBits(int first, int second) {
    int count = 0;

    // Since, the numbers are less than 2^31 run the loop from '0' to '31' only
    for (int i = 0; i < 32; i++) {
        // Right shift both the numbers by 'i' and check if the bit at the 0th position is different
        if (((first >> i) & 1) != ((second >> i) & 1)) {
            count++;
        }
    }

    return count;
}