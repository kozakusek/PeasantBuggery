#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(const string& s) {
        int n = s.size();
        if (n == 0) return "";

        vector<int> d(n);
        int best_len = 1, best_pos = 0;

        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                ++k;
            }
            d[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            int len = 2 * d[i] - 1;
            if (len > best_len) {
                best_len = len;
                best_pos = i - d[i] + 1;
            }
        }

        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 0 : min(d[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
                ++k;
            }
            d[i] = k;
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            int len = 2 * d[i];
            if (len > best_len) {
                best_len = len;
                best_pos = i - d[i];
            }
        }

        return s.substr(best_pos, best_len);
    }
};