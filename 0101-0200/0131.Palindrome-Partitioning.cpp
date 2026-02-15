#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(const string& s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || pal[j + 1][i - 1])) {
                    pal[j][i] = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        path.reserve(n);

        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                res.push_back(path);
                return;
            }

            for (int end = start; end < n; ++end) {
                if (!pal[start][end]) continue;

                path.emplace_back(s.substr(start, end - start + 1));
                dfs(end + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};
