#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(const vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int res = 0;
        while (l < r) {
            res = max(res, (r - l) * min(h[l], h[r]));
            if (h[l] >= h[r]) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};
