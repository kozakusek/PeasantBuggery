#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        
        int digits = 0;
        int y = x;
        while (y != 0) { 
            digits++;
            y /= 10;
        }

        y = 0;
        for (int i = 0; i < digits / 2; i++) {
            y = y * 10 + x % 10;
            x /= 10;    
        }

        if (digits & 1) {
            x /= 10;
        }

        return x == y;
    }
};
