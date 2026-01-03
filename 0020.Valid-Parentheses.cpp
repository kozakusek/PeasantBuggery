#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        vector<char> stack;
        stack.reserve(s.size());

        for (char c : s) {
            if (isClosing(c)) {
                if (stack.empty() || !matches(stack.back(), c)) {
                    return false;
                }
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }

        return stack.empty();
    }

private:
    bool matches(char open, char close) const {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    bool isClosing(char c) const {
        return c == ')' || c == '}' || c == ']';
    }
};
