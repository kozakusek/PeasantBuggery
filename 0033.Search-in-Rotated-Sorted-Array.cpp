#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        if (nums[l] <= nums[r]) {
            auto it = lower_bound(nums.begin(), nums.end(), target);
            return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
        }
        
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int pivot = l;

        if (target <= nums.back()) {
            auto it = lower_bound(nums.begin() + pivot, nums.end(), target);
            return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
        } else {
            auto it = lower_bound(nums.begin(), nums.begin() + pivot, target);
            return (it != nums.begin() + pivot && *it == target) ? it - nums.begin() : -1;
        }
    }
};
