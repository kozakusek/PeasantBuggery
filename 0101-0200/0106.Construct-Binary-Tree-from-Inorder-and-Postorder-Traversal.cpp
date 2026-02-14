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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int table[6001];
        for (int i = 0; i < inorder.size(); ++i)
            table[inorder[i] + 3000] = i;

        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, table, postIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder,
                    int table[6001], int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = table[rootVal + 3000];

        root->right = build(inorder, postorder, table, postIndex, inRootIndex + 1, inEnd);
        root->left = build(inorder, postorder, table, postIndex, inStart, inRootIndex - 1);

        return root;
    }
};
