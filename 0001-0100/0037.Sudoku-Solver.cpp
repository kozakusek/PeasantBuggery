#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int FULL = (1 << 9) - 1;

    int rows[9]{}, cols[9]{}, boxes[9]{};
    int opts[9][9]{};

    int box(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    bool hiddenSinglesUnit(vector<pair<int,int>>& cells, vector<vector<char>>& board) {
        int count[9] = {};
        int where[9] = {};

        for (int k = 0; k < (int)cells.size(); ++k) {
            auto [r, c] = cells[k];
            int mask = opts[r][c];

            while (mask) {
                int d = __builtin_ctz(mask);
                mask &= mask - 1;
                count[d]++;
                where[d] = k;
            }
        }

        for (int d = 0; d < 9; ++d) {
            if (count[d] == 1) {
                auto [r, c] = cells[where[d]];
                place(board, r, c, d);
                return true;
            }
        }

        return false;
    }

    bool propagate(vector<vector<char>>& board) {
        bool changed = true;

        while (changed) {
            changed = false;

            // Naked singles
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') continue;

                    int used = rows[i] | cols[j] | boxes[box(i, j)];
                    int mask = FULL & ~used;

                    if (mask == 0) return false;

                    opts[i][j] = mask;

                    if ((mask & (mask - 1)) == 0) {
                        int d = __builtin_ctz(mask);
                        place(board, i, j, d);
                        changed = true;
                    }
                }
            }

            if (changed) continue;

            // Hidden singles — rows
            for (int i = 0; i < 9; ++i) {
                vector<pair<int,int>> cells;
                for (int j = 0; j < 9; ++j)
                    if (board[i][j] == '.')
                        cells.push_back({i, j});

                if (!cells.empty() && hiddenSinglesUnit(cells, board)) {
                    changed = true;
                    break;
                }
            }

            if (changed) continue;

            // Hidden singles — columns
            for (int j = 0; j < 9; ++j) {
                vector<pair<int,int>> cells;
                for (int i = 0; i < 9; ++i)
                    if (board[i][j] == '.')
                        cells.push_back({i, j});

                if (!cells.empty() && hiddenSinglesUnit(cells, board)) {
                    changed = true;
                    break;
                }
            }

            if (changed) continue;

            // Hidden singles — boxes
            for (int b = 0; b < 9; ++b) {
                vector<pair<int,int>> cells;
                int br = (b / 3) * 3;
                int bc = (b % 3) * 3;

                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        if (board[br + i][bc + j] == '.')
                            cells.push_back({br + i, bc + j});

                if (!cells.empty() && hiddenSinglesUnit(cells, board)) {
                    changed = true;
                    break;
                }
            }
        }

        return true;
    }

    void place(vector<vector<char>>& board, int r, int c, int d) {
        int bit = 1 << d;
        board[r][c] = '1' + d;
        rows[r] |= bit;
        cols[c] |= bit;
        boxes[box(r, c)] |= bit;
        opts[r][c] = 0;
    }

    bool solve(vector<vector<char>>& board) {
        if (!propagate(board)) return false;

        int r = -1, c = -1, best = 10;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int cnt = __builtin_popcount(opts[i][j]);
                    if (cnt < best) {
                        best = cnt;
                        r = i; c = j;
                    }
                }
            }
        }

        if (r == -1) return true;

        int savedRows[9], savedCols[9], savedBoxes[9], savedOpts[9][9];
        memcpy(savedRows, rows, sizeof rows);
        memcpy(savedCols, cols, sizeof cols);
        memcpy(savedBoxes, boxes, sizeof boxes);
        memcpy(savedOpts, opts, sizeof opts);
        auto savedBoard = board;

        int mask = opts[r][c];
        while (mask) {
            int d = __builtin_ctz(mask);
            mask &= mask - 1;

            place(board, r, c, d);
            if (solve(board)) return true;

            memcpy(rows, savedRows, sizeof rows);
            memcpy(cols, savedCols, sizeof cols);
            memcpy(boxes, savedBoxes, sizeof boxes);
            memcpy(opts, savedOpts, sizeof opts);
            board = savedBoard;
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '1';
                    int bit = 1 << d;
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[box(i, j)] |= bit;
                }
            }
        }

        solve(board);
    }
};
