#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int open, int close, string& curr, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        if (open > 0) {
            curr.push_back('(');
            dfs(open - 1, close, curr, res);
            curr.pop_back();
        }
        if (close > open) {
            curr.push_back(')');
            dfs(open, close - 1, curr, res);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        dfs(n, n, curr, res);
        return res;
    }
};
