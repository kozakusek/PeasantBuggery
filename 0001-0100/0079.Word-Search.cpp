#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        if (!canForm(board, word)) return false;

        if (count(word.begin(), word.end(), word[0]) >
            count(word.begin(), word.end(), word.back())) {
            reverse(word.begin(), word.end());
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] &&
                    dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word,
             int x, int y, int idx) {
        if (idx == word.size()) return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;
        if (board[x][y] != word[idx]) return false;

        char tmp = board[x][y];
        board[x][y] = '#';

        bool ok =
            dfs(board, word, x + 1, y, idx + 1) ||
            dfs(board, word, x - 1, y, idx + 1) ||
            dfs(board, word, x, y + 1, idx + 1) ||
            dfs(board, word, x, y - 1, idx + 1);

        board[x][y] = tmp;
        return ok;
    }

    bool canForm(vector<vector<char>>& board, const string& word) {
        int cnt[128] = {};
        for (auto& r : board)
            for (char c : r)
                cnt[c]++;
        for (char c : word)
            if (--cnt[c] < 0)
                return false;
        return true;
    }
};
