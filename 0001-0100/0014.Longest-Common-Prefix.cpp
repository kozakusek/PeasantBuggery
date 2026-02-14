#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        size_t end = INT_MAX;
        for (const auto& s: strs) {
            end = min(end, s.size());
        }
        size_t i = 0;
        for (; i < end; i++) {
            const auto c = strs[0][i];
            for (const auto& s: strs) {
                if (s[i] != c) {
                    return strs[0].substr(0, i);;
                }
            }
        }
        return strs[0].substr(0, i);
    }
};
