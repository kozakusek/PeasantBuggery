#include <bits/stdc++.h>
using namespace std;

// your stack bad stack :(

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        path.reserve(64);

        function<void(int, int)> dfs = [&](int idx, int remain) {
            if (remain == 0) {
                res.push_back(path);
                return;
            }
            if (remain < 0) return;

            for (int i = idx; i < candidates.size(); ++i) {
                int c = candidates[i];
                if (c > remain) break;
                path.push_back(c);
                dfs(i, remain - c);
                path.pop_back();
            }
        };

        dfs(0, target);
        return res;
    }
};