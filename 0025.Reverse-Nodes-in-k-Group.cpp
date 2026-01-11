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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (true) {
            ListNode* curr = prev;
            for (int i = 0; i < k && curr; ++i) {
                curr = curr->next;
            }
            if (!curr) break; 

            // Reverse k nodes
            ListNode* tail = prev->next;
            ListNode* next = curr->next;
            ListNode* p = prev->next;
            ListNode* q = p->next;

            for (int i = 1; i < k; ++i) {
                ListNode* tmp = q->next;
                q->next = p;
                p = q;
                q = tmp;
            }

            // Append reversed group
            prev->next = p;
            tail->next = next;

            prev = tail;
        }

        return dummy.next;
    }
};