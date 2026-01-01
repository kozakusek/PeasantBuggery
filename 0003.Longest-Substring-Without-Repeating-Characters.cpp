#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        static thread_local bitset<128> counts;
        counts.reset();

        int best = 0, current = 0, ptr = 0;
        for (int i = 0; i < s.length(); i++) {
            if (counts[s[i]]) {
                best = max(current, best);
                while(s[i] != s[ptr]) {
                    counts.reset(s[ptr]);
                    ptr++;
                }
                ptr++;
                current = i - ptr + 1;
            } else {
                counts.set(s[i]);
                current++;
            }
        }

        return max(current, best);
    }

};

const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *operator new(size_t size) {
    constexpr size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = buffer + buffer_pos + padding;
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void *ptr, unsigned long) {}
void operator delete(void *ptr) {}
void operator delete[](void *ptr) {}