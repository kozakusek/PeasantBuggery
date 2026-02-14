#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(const string& s, const string& t) {
        if (t.size() > s.size()) return "";

        int cnt[128] = {};
        for (char c : t) cnt[c]--;

        int missing = t.size();
        int best_len = INT_MAX;
        int best_l = 0;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (++cnt[s[r]] <= 0) {
                missing--;
            }

            while (missing == 0) {
                int len = r - l + 1;
                if (len < best_len) {
                    best_len = len;
                    best_l = l;
                }

                if (--cnt[s[l]] < 0) {
                    missing++;
                }
                l++;
            }
        }

        return best_len == INT_MAX ? "" : s.substr(best_l, best_len);
    }
};