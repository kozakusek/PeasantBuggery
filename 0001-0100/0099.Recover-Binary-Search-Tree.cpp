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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        stack<TreeNode*> st;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top(); st.pop();

            if (prev && prev->val > root->val) {
                if (!first) first = prev;
                second = root;
            }
            prev = root;
            root = root->right;
        }

        swap(first->val, second->val);
    }
};
