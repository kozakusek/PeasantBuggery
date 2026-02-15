#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> front{beginWord};
        unordered_set<string> back{endWord};

        int steps = 1;

        while (!front.empty() && !back.empty()) {
            if (front.size() > back.size()) swap(front, back);

            unordered_set<string> next;

            for (auto word : front) {
                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        word[i] = c;

                        if (back.count(word)) return steps + 1;

                        if (dict.count(word)) {
                            next.insert(word);
                            dict.erase(word);
                        }
                    }

                    word[i] = orig;
                }
            }

            front.swap(next);
            steps++;
        }

        return 0;
    }
};
