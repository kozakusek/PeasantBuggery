#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            string line;
            int numWords = j - i;
            bool lastLine = (j == n);

            if (numWords == 1 || lastLine) {
                for (int k = i; k < j; ++k) {
                    if (k > i) line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth;
                for (int k = i; k < j; ++k) totalSpaces -= words[k].size();
                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                line += words[i];
                for (int k = i + 1; k < j; ++k) {
                    int spacesToAdd = spaceBetween + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spacesToAdd, ' ') + words[k];
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};
