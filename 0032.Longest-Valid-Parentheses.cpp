#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestValidParentheses(const string& s) {
        int best = 0, open = 0, close = 0;

        for (char c : s) {
            if (c == '(') ++open; 
            else ++close;

            if (close > open) {
                open = close = 0;
            } else if (open == close) {
                best = max(best, 2 * close);
            }
        }

        open = close = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') ++open; 
            else ++close;

            if (open > close) {
                open = close = 0;
            } else if (open == close) {
                best = max(best, 2 * open);
            }
        }

        return best;
    }
};
