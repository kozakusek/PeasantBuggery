#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        int i = 0, j = 0;
        int backtrack = -1;
        int starPos = -1;

        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                starPos = j++;
                backtrack = i;
            } else if (starPos != -1) {
                j = starPos + 1;
                i = ++backtrack;
            } else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*') j++;

        return j == p.size();
    }
};
