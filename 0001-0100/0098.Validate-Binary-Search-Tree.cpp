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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> st;
        long long prev = LLONG_MIN;

        while (root || !st.empty()) {
            while (root) {
                st.push_back(root);
                root = root->left;
            }

            root = st.back(); st.pop_back();

            if (root->val <= prev) return false;
            prev = root->val;

            root = root->right;
        }
        return true;
    }
};
