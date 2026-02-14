#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};

        int lastSize = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int start = (i > 0 && nums[i] == nums[i - 1]) ? lastSize : 0;
            lastSize = res.size();

            for (int j = start; j < lastSize; ++j) {
                auto cur = res[j];
                cur.push_back(nums[i]);
                res.push_back(move(cur));
            }
        }
        return res;
    }
};
