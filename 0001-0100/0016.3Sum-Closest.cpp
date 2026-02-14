#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        int best = nums[0] + nums[1] + nums[2];
        int best_diff = abs(best - target);

        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = sum - target;

                if (diff == 0) return target;

                int ad = abs(diff);
                if (ad < best_diff) {
                    best_diff = ad;
                    best = sum;
                }

                if (diff < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return best;
    }
};
