#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {};
        int cols[9] = {};
        int boxes[9] = {};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int bit = 1 << (c - '1');
                int box = (i / 3) * 3 + (j / 3);

                if (rows[i] & bit) return false;
                if (cols[j] & bit) return false;
                if (boxes[box] & bit) return false;

                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }

        return true;
    }
};
