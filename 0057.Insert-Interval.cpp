#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;

        if (n == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        // Skip intervals completely before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ++i;
        }
        int insertPos = i;

        // Merge all overlapping intervals into newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }

        // Remove overlapping intervals
        intervals.erase(intervals.begin() + insertPos, intervals.begin() + i);

        // Insert the merged interval at the correct position
        intervals.insert(intervals.begin() + insertPos, newInterval);

        return intervals;
    }
};
