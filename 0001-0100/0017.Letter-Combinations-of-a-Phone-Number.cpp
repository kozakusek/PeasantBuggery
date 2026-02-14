#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        constexpr array<const char*, 10> letters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result{""}; 

        for (const char d : digits) {
            vector<string> temp;
            const char* chars = letters[d - '0'];

            for (const string& prefix : result) {
                for (int i = 0; chars[i]; ++i) {
                    temp.push_back(prefix + chars[i]);
                }
            }

            result.swap(temp);
        }

        return result;
    }
};
