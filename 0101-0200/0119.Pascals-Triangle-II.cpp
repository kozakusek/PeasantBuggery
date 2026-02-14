#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int k = 1; k <= rowIndex; ++k) {
            long long val = (long long)row[k - 1] * (rowIndex - k + 1) / k;
            row[k] = (int)val;
        }

        return row;
    }
};
