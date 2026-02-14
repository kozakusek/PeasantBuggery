#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        res.clear();
        vector<int> board(n, 0);
        solve(0, 0, 0, 0, board);
        return res;
    }

private:
    int n;
    vector<vector<string>> res;

    void solve(int row, int cols, int diag1, int diag2, vector<int>& board) {
        if (row == n) {
            res.push_back(draw(board));
            return;
        }

        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int p = available & -available; // pick lowest 1-bit
            available ^= p;                // remove it from available

            int col = __builtin_ctz(p);    // column index
            board[row] = col;

            solve(row + 1,
                  cols | p,
                  (diag1 | p) << 1,
                  (diag2 | p) >> 1,
                  board);
        }
    }

    vector<string> draw(const vector<int>& board) {
        vector<string> b(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
            b[i][board[i]] = 'Q';
        return b;
    }
};
