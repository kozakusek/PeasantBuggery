#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(const std::string& s) {
        size_t i = 0;

        while (i < s.size() && s[i] == ' ') i++;

        if (i == s.size()) return 0;

        int sign = 1;
        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') { i++; }

        int result = 0;
        while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
