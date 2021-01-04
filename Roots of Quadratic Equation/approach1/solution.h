/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

pair<int, int> findRoots(int a, int b, int c) {
    // Find the discriminant
    double D = b * b - 4 * a * c;
    if (D < 0) {
        // Roots Imaginary;
        return make_pair(-1, -1);
    } else {
        double root1 = (-b + sqrt(D)) / (2 * a);
        double root2 = (-b - sqrt(D)) / (2 * a);
        return make_pair((int)floor(root1), (int)floor(root2));
    }
}
