#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1);

        for (int j = 0; j <= m; ++j) dp[j] = j;

        for (int i = 1; i <= n; ++i) {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= m; ++j) {
                int cur = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = prev;
                else
                    dp[j] = 1 + min({dp[j], dp[j - 1], prev});
                prev = cur;
            }
        }
        return dp[m];
    }
};
