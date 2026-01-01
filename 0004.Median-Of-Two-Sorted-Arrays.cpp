#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& a, const vector<int>& b) {
        int al = 0;
        int ar = a.size();
        int bl = 0;
        int br = b.size();
        int ml = (ar + br) / 2;

        if ((ar + br) & 1) {
            return static_cast<double>(kth(a, al, ar, b, bl, br, ml));
        }

        int l = kth(a, al, ar, b, bl, br, ml - 1);
        int r = kth(a, al, ar, b, bl, br, ml);

        return 0.5 * (l + r);
    }

private:
    int kth(const vector<int>& a, int al, int ar,
            const vector<int>& b, int bl, int br,
            int k) {
        while (true) {
            if (al == ar) return b[bl + k];
            if (bl == br) return a[al + k];
            if (k == 0) return min(a[al], b[bl]);

            int step = (k - 1) / 2;
            int ia = min(al + step, ar - 1);
            int ib = min(bl + step, br - 1);

            if (a[ia] <= b[ib]) {
                k -= (ia - al + 1);
                al = ia + 1;
            } else {
                k -= (ib - bl + 1);
                bl = ib + 1;
            }
        }
    }
};
