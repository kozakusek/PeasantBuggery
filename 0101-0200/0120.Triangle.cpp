#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;

        vector<int> dp = triangle[0];

        for (int i = 1; i < n; ++i) {
            vector<int> new_dp(i + 1);
            for (int j = 0; j <= i; ++j) {
                if (j == 0)
                    new_dp[j] = dp[0] + triangle[i][j];
                else if (j == i)
                    new_dp[j] = dp[j - 1] + triangle[i][j];
                else
                    new_dp[j] = triangle[i][j] + min(dp[j - 1], dp[j]);
            }
            dp = move(new_dp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};
