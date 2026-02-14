#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;

        const int m = words[0].size();
        const int k = words.size();
        const int n = s.size();

        using sv = std::string_view;

        unordered_map<sv, int> id;
        id.reserve(words.size());

        int idx = 0;
        for (const auto& w : words) {
            sv vw(w);
            if (!id.count(vw)) {
                id[vw] = idx++;
            }
        }

        const int U = idx;

        vector<int> target(U, 0);
        for (const auto& w : words) {
            target[id[sv(w)]]++;
        }

        // token[i] = id of word starting at i, or -1
        vector<int> token(n, -1);
        for (int i = 0; i + m <= n; i++) {
            sv w(s.data() + i, m);
            auto it = id.find(w);
            if (it != id.end()) {
                token[i] = it->second;
            }
        }

        for (int offset = 0; offset < m; offset++) {
            vector<int> window(U, 0);
            int left = offset, count = 0;

            for (int right = offset; right + m <= n; right += m) {
                int wId = token[right];

                if (wId == -1) {
                    fill(window.begin(), window.end(), 0);
                    count = 0;
                    left = right + m;
                    continue;
                }

                window[wId]++;
                count++;

                while (window[wId] > target[wId]) {
                    int lwId = token[left];
                    window[lwId]--;
                    count--;
                    left += m;
                }

                if (count == k) {
                    res.push_back(left);
                }
            }
        }

        return res;
    }
};
