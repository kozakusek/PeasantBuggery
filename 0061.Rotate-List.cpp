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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* fast = head;
        int length = 1;

        for (int i = 0; i < k; ++i) {
            if (fast->next) {
                fast = fast->next;
                length++;
            } else { 
                // reached end, wrap k around
                k %= length;
                fast = head; 
                i = -1;
            }
        }

        if (k == 0) return head;

        ListNode* slow = head;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};
