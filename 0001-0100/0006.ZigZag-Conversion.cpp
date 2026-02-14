#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1) return s;

        vector<int8_t> out(s.size());
        size_t pos = 0;
    
        size_t step = (numRows - 1) * 2;
        for (size_t i = 0; i < s.size(); i += step) {
            out[pos++] = s[i];
        }

        for (int row = 1; row < numRows - 1; row++) {
            size_t step_2 = 2 * row;
            size_t step_1 = 2 * numRows - 2 - (step_2);
            size_t current_step = numRows & 1 == 0 ? step_1 : step_2;
            for (size_t i = row; i < s.size(); i += current_step) {
                out[pos++] = s[i];
                if (current_step == step_1) {
                    current_step = step_2;
                } else {
                    current_step = step_1;
                }
            }
        }
        
        for (size_t i = numRows - 1; i < s.size(); i += step) {
            out[pos++] = s[i];
        }

        return string(out.begin(), out.end());
    }
};