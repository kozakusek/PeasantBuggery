#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    
    void dfs(const vector<int>& candidates, int start, int remain) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > remain) break;
            if (i > start && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, remain - candidates[i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        path.clear();
        path.reserve(candidates.size());
        dfs(candidates, 0, target);
        return res;
    }
};
