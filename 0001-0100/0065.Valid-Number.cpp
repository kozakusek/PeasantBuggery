#include <bits/stdc++.h>
using namespace std;

// *Disgusted emoji*

class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();

        while (i < n && isspace(s[i])) i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool isNumeric = false;
        while (i < n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }

        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false;

            if (i < n && (s[i] == '+' || s[i] == '-')) i++;

            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        while (i < n && isspace(s[i])) i++;

        return isNumeric && i == n;
    }
};
