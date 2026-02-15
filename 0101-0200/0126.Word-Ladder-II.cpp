#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(const string& beginWord, const string& endWord, const vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) return result;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> current{beginWord};
        bool found = false;

        while (!current.empty() && !found) {
            for (auto &w : current) dict.erase(w);

            unordered_set<string> next;

            for (auto &word : current) {
                string tmp = word;

                for (int i = 0; i < tmp.size(); ++i) {
                    char orig = tmp[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        tmp[i] = c;

                        if (!dict.count(tmp)) continue;

                        next.insert(tmp);
                        parents[tmp].push_back(word);

                        if (tmp == endWord) found = true;
                    }

                    tmp[i] = orig;
                }
            }

            current.swap(next);
        }

        if (!found) return result;

        vector<string> path{endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(const string& word,
                   const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& result) {

        if (word == beginWord) {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            result.push_back(tmp);
            return;
        }

        for (auto &p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
