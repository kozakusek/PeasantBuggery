#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        const int n = num1.size();
        const int m = num2.size();
        vector<int> arr(n + m, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                const int pro = (num1[i] - '0') * (num2[j] - '0');
                const int p1 = i + j;
                const int p2 = i + j + 1; 
                const int sum = pro + arr[p2];
                arr[p2] = sum % 10;
                arr[p1] += sum / 10;
            }
        }

        int i = 0;
        while (i < n + m && arr[i] == 0) i++;
        if (i == n + m) return "0";

        string ans;
        while (i < n + m) ans += char(arr[i++] + '0');
        return ans;
    }
};
