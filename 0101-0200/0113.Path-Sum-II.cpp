#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int target;

    void dfs(TreeNode* node, int current_sum) {
        if (!node) return;

        current_sum += node->val;
        path.push_back(node->val);

        if (!node->left && !node->right) {
            if (current_sum == target)
                result.push_back(path);
        } else {
            dfs(node->left, current_sum);
            dfs(node->right, current_sum);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        result.clear();
        path.clear();

        dfs(root, 0);
        return result;
    }
};
