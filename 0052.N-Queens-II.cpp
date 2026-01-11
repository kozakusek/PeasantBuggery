#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        count = 0;
        solve(0, 0, 0, 0);
        return count;
    }

private:
    int n;
    int count;

    void solve(int row, int cols, int diag1, int diag2) {
        if (row == n) {
            ++count;
            return;
        }

        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int p = available & -available; // pick lowest 1-bit
            available ^= p;                // remove it

            solve(row + 1,
                  cols | p,
                  (diag1 | p) << 1,
                  (diag2 | p) >> 1);
        }
    }
};
