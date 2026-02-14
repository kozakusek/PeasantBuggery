#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }

        return build(head, 0, n - 1);
    }

private:
    TreeNode* build(ListNode*& head, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* leftChild = build(head, left, mid - 1);

        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;

        head = head->next;

        root->right = build(head, mid + 1, right);

        return root;
    }
};
