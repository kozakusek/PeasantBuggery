#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<string>& res) {
        if (path.size() == 4) {
            if (start == s.size()) {
                res.push_back(join(path));
            }
            return;
        }

        for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
            string seg = s.substr(start, len);
            if ((seg[0] == '0' && seg.size() > 1) || stoi(seg) > 255)
                continue;
            path.push_back(seg);
            backtrack(s, start + len, path, res);
            path.pop_back();
        }
    }

    string join(const vector<string>& path) {
        string s;
        for (int i = 0; i < path.size(); ++i) {
            if (i > 0) s += '.';
            s += path[i];
        }
        return s;
    }
};
