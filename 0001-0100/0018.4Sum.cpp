#include <bits/stdc++.h>
using namespace std;

// yeah well, hope they do the 5sum now :)

class Solution {
public:
    vector<vector<int>> kSum(vector<int>& nums, int target, int k, int start = 0) {
        vector<vector<int>> result;
        const int n = nums.size();
        if (k == 2) {
            int l = start, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    result.push_back({nums[l], nums[r]});
                    ++l; --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        } else {
            for (int i = start; i < n - k + 1; ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue;
                if ((long)nums[i] + (long)nums[n - 1] * (k - 1) < target) continue;
                if ((long)nums[i] * k > target) break;

                auto sub = kSum(nums, target - nums[i], k - 1, i + 1);
                for (auto &vec : sub) {
                    vec.insert(vec.begin(), nums[i]);
                    result.push_back(vec);
                }
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4);
    }
};