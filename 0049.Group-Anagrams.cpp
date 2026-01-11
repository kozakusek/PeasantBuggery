#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size());

        for (const string& s : strs) {
            int cnt[26] = {};
            for (char c : s) ++cnt[c - 'a'];

            string key;
            key.reserve(52);
            for (int i = 0; i < 26; ++i) {
                key.push_back('#');
                key.append(to_string(cnt[i]));
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(mp.size());
        for (auto& [_, group] : mp) {
            res.push_back(move(group));
        }

        return res;
    }
};

