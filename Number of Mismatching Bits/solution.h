/*
    Time Complexity: O(log(n))
    Space Complexity: O(n)

    Where 'n' is the given number
*/

int countSetBits(int Xor) {
    // Returns number of set bits
    return (int)__builtin_popcount(Xor);
}
int numberOfMismatchingBits(int first, int second) {
    int Xor = first ^ second;
    return countSetBits(Xor);
}