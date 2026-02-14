#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
