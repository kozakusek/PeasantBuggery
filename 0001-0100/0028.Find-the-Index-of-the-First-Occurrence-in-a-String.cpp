#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> buildLPS(const string& pattern) {
        const int m = pattern.size();
    
        vector<int> lps(m, 0);

        int len = 0;
        for (int i = 1; i < m;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        return lps;
    }

    int kmpSearch(const string& text, const string& pattern, const vector<int>& lps) {
        const int n = text.size();
        const int m = pattern.size();

        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    return i - m;
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;

        const vector<int> lps = buildLPS(needle);
        return kmpSearch(haystack, needle, lps);
    }
};