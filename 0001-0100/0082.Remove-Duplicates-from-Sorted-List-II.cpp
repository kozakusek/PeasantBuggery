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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next) {
            ListNode* curr = prev->next;
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    ListNode* tmp = curr->next;
                    curr->next = curr->next->next;
                    delete tmp;
                }
                ListNode* tmp = prev->next;
                prev->next = curr->next;
                delete tmp;
            } else {
                prev = prev->next;
            }
        }

        return dummy.next;
    }
};
