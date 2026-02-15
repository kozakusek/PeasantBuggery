#include <bits/stdc++.h>
using namespace std;


// Bullshit. O(n) is expected, O(nlogn) passes, this is O(n^2) ...
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int best = 0;

        for (int x : s) {
            if (!s.count(x - 1)) {
                int cur = x;
                int len = 1;

                while (s.count(cur + 1)) {
                    cur++;
                    len++;
                }

                best = max(best, len);
            }
        }

        return best;
    }
};
