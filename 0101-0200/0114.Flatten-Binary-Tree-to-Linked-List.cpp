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
    TreeNode* flattenRec(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* left_last = flattenRec(root->left);
        TreeNode* right_last = flattenRec(root->right);

        if (root->left) {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;

            if (left_last) left_last->right = temp;
        }

        if (right_last) return right_last;
        if (left_last) return left_last;
        return root;
    }

    void flatten(TreeNode* root) {
        flattenRec(root);
    }
};

