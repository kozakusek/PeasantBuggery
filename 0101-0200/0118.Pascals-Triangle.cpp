#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows <= 0) return triangle;

        triangle.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> row(i + 1, 1);

            const vector<int>& prev = triangle[i - 1];
            for (int j = 1; j < i; ++j) {
                row[j] = prev[j - 1] + prev[j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};
