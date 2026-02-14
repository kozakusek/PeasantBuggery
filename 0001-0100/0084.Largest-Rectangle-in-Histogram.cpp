#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        struct Node {
            int h;
            int start;
        };

        Node* st = new Node[n];
        int top = 0;

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int start = i;

            while (top > 0 && st[top - 1].h > heights[i]) {
                Node cur = st[--top];
                ans = max(ans, cur.h * (i - cur.start));
                start = cur.start;
            }

            st[top++] = {heights[i], start};
        }

        for (int i = 0; i < top; ++i) {
            ans = max(ans, st[i].h * (n - st[i].start));
        }

        delete[] st;
        return ans;
    }
};
