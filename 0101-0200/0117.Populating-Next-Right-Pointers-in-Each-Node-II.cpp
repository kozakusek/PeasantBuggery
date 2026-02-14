#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;           // current node on current level
        Node* next_level_start = nullptr; // first node of next level
        Node* prev = nullptr;        // last node connected on next level

        while (curr) {
            for (Node* child : {curr->left, curr->right}) {
                if (child) {
                    if (prev) {
                        prev->next = child;
                    } else {
                        next_level_start = child;
                    }
                    prev = child;
                }
            }

            curr = curr->next;

            if (!curr) {
                curr = next_level_start;
                next_level_start = nullptr;
                prev = nullptr;
            }
        }

        return root;
    }
};
