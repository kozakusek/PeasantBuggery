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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int table[6001]; 
        for (int i = 0; i < inorder.size(); ++i) {
            table[inorder[i] + 3000] = i;
        }

        int preIndex = 0;
        return build(preorder, table, preIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& preorder, int table[6001],
                    int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = table[rootVal + 3000];
        int leftSize = inRootIndex - inStart;

        root->left = build(preorder, table, preIndex, inStart, inRootIndex - 1);
        root->right = build(preorder, table, preIndex, inRootIndex + 1, inEnd);

        return root;
    }
};
