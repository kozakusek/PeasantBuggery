#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.reserve(intervals.size() / 2);

        merged.push_back(intervals[0]);
        int lastIdx = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged[lastIdx][1]) {
                merged[lastIdx][1] = max(merged[lastIdx][1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
                ++lastIdx;
            }
        }

        return merged;
    }
};
