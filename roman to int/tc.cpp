// C++ Program to convert decimal number to
// roman numerals
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

// use this to get a random number from range [l, r]
int getRandomFromRange(int l, int r) {
    int x = (l + ((rand()) % (r - l + 1)));
    return x;
}

// Function to convert decimal to Roman Numerals
void printRoman(int number) {
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (number > 0) {
        int div = number / num[i];
        number = number % num[i];
        while (div--) {
            cout << sym[i];
        }
        i--;
    }
}

//Driver program
int main() {
#ifndef ONLINE_JUDGE
    //freopen("testcases/small/in/input2.txt", "r", stdin);
    freopen("testcases/large/in/input5.txt", "w", stdout);

#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    int t = getRandomFromRange(5, 10);
    cout << t << endl;
    while (t--) {
        int n = getRandomFromRange(1, 399);
        printRoman(n);
        cout << endl;
    }
}
