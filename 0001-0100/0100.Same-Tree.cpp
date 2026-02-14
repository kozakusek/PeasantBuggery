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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);

        while (!qu.empty()) {
            TreeNode* a = qu.front(); qu.pop();
            TreeNode* b = qu.front(); qu.pop();

            if (!a || !b) {
                if (a != b) return false;
                continue;
            }

            if (a->val != b->val) return false;

            qu.push(a->left);
            qu.push(b->left);
            qu.push(a->right);
            qu.push(b->right);
        }
        return true;
    }
};
