#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == val) {
                nums[i] = nums.back();
                nums.pop_back();
            } else {
                i++;
            }
        }

        return nums.size();
    }
};