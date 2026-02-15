#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int best_profit = 0;

        for (int p : prices) {
            min_price = min(min_price, p);
            best_profit = max(best_profit, p - min_price);
        }

        return best_profit;
    }
};
