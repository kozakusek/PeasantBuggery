#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }
            if (matrix[mid][0] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};
