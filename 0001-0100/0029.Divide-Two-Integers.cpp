#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1)  return dividend;
        if (dividend == divisor) return 1;

        int negatives = 0;
        if (dividend > 0) {
            dividend = -dividend;
            negatives++;
        }
        if (divisor > 0) {
            divisor = -divisor;
            negatives++;
        }

        int result = 0;

        while (dividend <= divisor) {
            int current = divisor;
            int multiple = 1;

            while (current >= INT_MIN / 2 &&
                   dividend <= (current << 1)) {
                current <<= 1;
                multiple <<= 1;
            }

            dividend -= current;
            result += multiple;
        }

        return (negatives == 1) ? -result : result;
    }
};
