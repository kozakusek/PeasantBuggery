#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        int next = 1; 

        while (true) {
            while ((int)curr.size() < k && next <= n) {
                curr.push_back(next);
                next++;
            }

            if ((int)curr.size() == k) {
                res.push_back(curr);
            }

            while (!curr.empty() && curr.back() == n - (k - curr.size())) {
                next = curr.back() + 1;
                curr.pop_back();
            }

            if (curr.empty()) break;

            next = curr.back() + 1;
            curr.pop_back();
            curr.push_back(next);
            next++;
        }

        return res;
    }
};
