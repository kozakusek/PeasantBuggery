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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;

        while (!q.empty()) {
            int sz = q.size();
            res.emplace_back(sz);
            auto& lvl = res.back();

            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = q.front(); q.pop();
                lvl[rev ? sz - 1 - i : i] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            rev = !rev;
        }
        return res;
    }
};
