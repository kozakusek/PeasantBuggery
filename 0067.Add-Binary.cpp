#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        int maxLen = max(n, m);
        vector<char> res(maxLen + 1, '0');

        bool carry = false;
        int i = n - 1, j = m - 1, k = maxLen;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry ? 1 : 0;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            carry = sum > 1;
            res[k--] = (sum % 2) + '0';
        }

        if (res[0] == '0') return string(res.begin() + 1, res.end());
        else return string(res.begin(), res.end());
    }
};
