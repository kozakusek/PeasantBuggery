#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        st.reserve(16);

        int n = path.size();
        for (int i = 0; i < n; ) {
            while (i < n && path[i] == '/') i++;
            int start = i;
            while (i < n && path[i] != '/') i++;
            if (start == i) break;

            int len = i - start;
            if (len == 1 && path[start] == '.') continue;
            if (len == 2 && path[start] == '.' && path[start+1] == '.') {
                if (!st.empty()) st.pop_back();
            } else {
                st.emplace_back(path, start, len);
            }
        }

        if (st.empty()) return "/";

        string res;
        for (auto& s : st) {
            res.push_back('/');
            res += s;
        }
        return res;
    }
};
