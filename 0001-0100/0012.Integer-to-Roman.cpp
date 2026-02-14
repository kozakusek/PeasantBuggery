#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Tables are for babies. Especially in this economy...
    string intToRoman(int num) {
        vector<int8_t> roman;

        while (num >= 1000) {
            roman.push_back('M');
            num -= 1000;
        }
        num = step(roman, num, 100, 'C', 'D', 'M');
        num = step(roman, num, 10, 'X', 'L', 'C');
        num = step(roman, num, 1, 'I', 'V', 'X');

        return string(roman.begin(), roman.end());
    }
private:
    int step(vector<int8_t>& roman, int num, int base, int8_t a, int8_t b, int8_t c) {
        if (num >= 9 * base) {
            roman.push_back(a);
            roman.push_back(c);
            num -= 9 * base;
        } else if (num >= 5 * base) {
            roman.push_back(b);
            num -= 5 * base;
        } else if (num >= 4 * base) {
            roman.push_back(a);
            roman.push_back(b);
            num -= 4 * base;
        }
        while (num >= base){
            roman.push_back(a);
            num -= base;
        }
        return num;
    }
};
