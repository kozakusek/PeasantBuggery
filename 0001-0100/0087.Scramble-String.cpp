#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(const string& s1, const string& s2) {
        n = s1.size();
        if (n != (int)s2.size()) return false;
        if (s1 == s2) return true;

        a = &s1;
        b = &s2;
        memo.assign(n * n * (n + 1), -1);

        return dfs(0, 0, n);
    }

private:
    const string* a;
    const string* b;
    int n;
    vector<int8_t> memo; // -1 unknown, 0 false, 1 true

    inline int id(int i, int j, int len) const {
        return (i * n + j) * (n + 1) + len;
    }

    bool dfs(int i, int j, int len) {
        int idx = id(i, j, len);
        int8_t& res = memo[idx];
        if (res != -1) return res;

        if (std::string_view(*a).substr(i, len) ==
            std::string_view(*b).substr(j, len))
            return res = 1;

        int mask = 0;
        int cnt[26] = {};
        for (int k = 0; k < len; ++k) {
            int x = (*a)[i + k] - 'a';
            int y = (*b)[j + k] - 'a';
            mask ^= (1 << x);
            mask ^= (1 << y);
            ++cnt[x];
            --cnt[y];
        }
        if (mask) return res = 0;
        for (int c : cnt)
            if (c) return res = 0;

        for (int k = 1; k < len; ++k) {
            if (dfs(i, j, k) && dfs(i + k, j + k, len - k))
                return res = 1;
            if (dfs(i, j + len - k, k) && dfs(i + k, j, len - k))
                return res = 1;
        }

        return res = 0;
    }
};