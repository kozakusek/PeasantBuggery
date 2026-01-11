#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0, right = h.size() - 1, leftMax = 0, rightMax = 0, water = 0;
        while (left <= right) {
            if (h[left] < h[right]) {
                leftMax = max(leftMax, h[left]);
                water += leftMax - h[left];
                left++;
            } else {
                rightMax = max(rightMax, h[right]);
                water += rightMax - h[right];
                right--;
            }
        }
        return water;
    }
};
