#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int height[200] = {};
        int ans = 0;

        struct Node {
            int h;
            int start;
        };

        Node st[200];

        for (int i = 0; i < rows; ++i) {
            int top = 0;

            for (int j = 0; j < cols; ++j) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;

                int start = j;
                while (top > 0 && st[top - 1].h > height[j]) {
                    Node cur = st[--top];
                    ans = max(ans, cur.h * (j - cur.start));
                    start = cur.start;
                }
                st[top++] = {height[j], start};
            }

            for (int k = 0; k < top; ++k) {
                ans = max(ans, st[k].h * (cols - st[k].start));
            }
        }

        return ans;
    }
};
