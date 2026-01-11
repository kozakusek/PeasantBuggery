#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        const auto a = lower_bound(nums.begin(), nums.end(), target);
        if (a == nums.end() || *a != target) return {-1, -1};

        const auto b = upper_bound(nums.begin(), nums.end(), target);

        return { static_cast<int>(a - nums.begin()),  static_cast<int>(b - nums.begin()) - 1 };
    }
};
