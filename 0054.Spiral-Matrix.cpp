#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> res;
        res.reserve(m * n);

        while (top <= bottom && left <= right) {
            // top row
            for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
            ++top;

            // right column
            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            --right;

            if (top <= bottom) {
                // bottom row
                for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
                --bottom;
            }

            if (left <= right) {
                // left column
                for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
                ++left;
            }
        }

        return res;
    }
};
