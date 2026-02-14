#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev2 = 1;
        int prev1 = 1;

        for (int i = 1; i < s.size(); ++i) {
            int cur = 0;

            if (s[i] != '0')
                cur += prev1;

            int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (two >= 10 && two <= 26)
                cur += prev2;

            prev2 = prev1;
            prev1 = cur;

            if (cur == 0) return 0;
        }

        return prev1;
    }
};
