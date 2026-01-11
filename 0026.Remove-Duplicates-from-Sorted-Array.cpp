#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, k = 1;

        while (i < nums.size()) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
            ++i;
        }
        
        nums.resize(k);

        return k;
    }
};