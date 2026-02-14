#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        for (int i = 2; i <= n; ++i) factorial *= i;

        int mask = 0; 
        k--;
        vector<char> result(n, '0');

        for (int i = n; i >= 1; --i) {
            factorial /= i;
            int cnt = k / factorial;
            k %= factorial;

            int num = 1;
            for (int b = 0; b < n; ++b, ++num) {
                if (!(mask & (1 << b))) {
                    if (cnt == 0) break;
                    cnt--;
                }
            }

            result[n - i] = '0' + num;
            mask |= (1 << (num - 1));
        }

        return string(result.begin(), result.end());
    }
};
