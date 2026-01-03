#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(const string& s) {
        int i = 0;
        int res = 0;

        res += step(s, i, 1000, 'M', 0, 0);
        res += step(s, i, 100,  'C', 'D', 'M');
        res += step(s, i, 10,   'X', 'L', 'C');
        res += step(s, i, 1,    'I', 'V', 'X');

        return res;
    }

private:
    int step(const string& s, int& i, int base, char a, char b, char c) {
        int val = 0;

        // 9 × base: a c
        if (c && i + 1 < s.size() && s[i] == a && s[i + 1] == c) {
            i += 2;
            return 9 * base;
        }

        // 5 × base: b
        if (b && i < s.size() && s[i] == b) {
            i++;
            val += 5 * base;
        }

        // 4 × base: a b
        if (b && i + 1 < s.size() && s[i] == a && s[i + 1] == b) {
            i += 2;
            return 4 * base;
        }

        // 1 × base: a (up to 3 times)
        while (i < s.size() && s[i] == a) {
            i++;
            val += base;
        }

        return val;
    }
};
