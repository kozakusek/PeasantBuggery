#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;

        vector<vector<int>> res;
        res.reserve(total);

        for (int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            int m = mask;
            while (m) {
                int i = __builtin_ctz(m);
                subset.push_back(nums[i]);
                m &= m - 1;
            }
            res.push_back(std::move(subset));
        }

        return res;
    }
};
