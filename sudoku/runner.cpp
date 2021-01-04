#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
#include "solution.h"
bool sudokuChecker(vector<vector<int>> &original, vector<vector<int>> &solution) {
    bool flag = 1;
    int expectedVal = (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9);
    int actualVal = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (original[row][col] != 0 and original[row][col] != solution[row][col]) {
                return false;
            }
        }
    }
    for (int row = 0; row < 9; row++) {
        actualVal = 0;
        for (int col = 0; col < 9; col++) {
            actualVal ^= solution[row][col];
        }
        if (actualVal != expectedVal) {
            flag = false;
            break;
        }
    }
    if (flag) {
        for (int row = 0; row < 9; row++) {
            actualVal = 0;
            for (int col = 0; col < 9; col++) {
                actualVal ^= solution[row][col];
            }
            if (actualVal != expectedVal) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < 9; i += 3) {
            if (flag) {
                for (int j = 0; j < 9; j += 3) {
                    actualVal = 0;
                    for (int ii = i; ii < i + 3; ii++) {
                        for (int jj = j; jj < (j + 3); jj++) {
                            actualVal ^= solution[ii][jj];
                        }
                    }
                    if (actualVal != expectedVal) {
                        flag = false;
                        break;
                    }
                }

            } else {
                break;
            }
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> wor;
    vector<vector<int>> sol;
    for (int i = 0; i < 9; i++) {
        vector<int> temp;
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        wor.push_back(temp);
    }
    sol = solveSudoku(wor);

    if (sudokuChecker(wor, sol)) {
        cout << "CORRECT SOLUTION\n";
    } else {
        cout << "INCORRECT SOLUTION\n";
    }
}
