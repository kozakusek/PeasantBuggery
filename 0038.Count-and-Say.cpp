#include <bits/stdc++.h>
using namespace std;

constexpr size_t MAX_LEN = 5000;

struct Seq {
    std::array<char, MAX_LEN> data{};
    size_t len = 0;
};

constexpr Seq next(const Seq& s) {
    Seq out;

    size_t i = 0;
    while (i < s.len) {
        size_t j = i;
        while (j < s.len && s.data[j] == s.data[i])
            ++j;

        size_t count = j - i;

        if (count >= 100) {
            out.data[out.len++] = '0' + count / 100;
        }
        if (count >= 10) {
            out.data[out.len++] = '0' + (count / 10) % 10;
        }
        out.data[out.len++] = '0' + count % 10;

        out.data[out.len++] = s.data[i];
        i = j;
    }

    return out;
}

template<int N>
constexpr auto buildTable() {
    std::array<Seq, N + 1> table{};

    table[1].data[0] = '1';
    table[1].len = 1;

    for (int i = 2; i <= N; ++i) {
        table[i] = next(table[i - 1]);
    }

    return table;
}


constexpr auto TABLE = buildTable<30>();

class Solution {
public:
    string countAndSay(int n) {
        const Seq& s = TABLE[n];
        return string(s.data.data(), s.len);
    }
};