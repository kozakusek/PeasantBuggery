#include <bits/stdc++.h>
using namespace std;

// Got 0 ms. 
// Lol. DP is for losers.

class RegexGraph {
    static constexpr int ALPHABET = 26;
    static constexpr int MAXS = 32;

    int start;
    int accept;
    int nstates;

    // Fully ε-closed transitions:
    // trans[c][i] = bitmask of states reachable
    //               when consuming character c from state i
    uint64_t trans[ALPHABET][MAXS]{};

    // Fast input mapping
    static uint8_t cmap[256];

public:
    explicit RegexGraph(const std::string& pattern) {
        init_cmap();
        build(pattern);
    }

    bool matches(const std::string& text) const {
        uint64_t cur = 1ULL << start;

        for (unsigned char ch : text) {
            uint64_t next = 0;
            uint8_t c = cmap[ch];

            // Branchless bit-slicing
            for (int i = 0; i < nstates; ++i) {
                uint64_t bit = (cur >> i) & 1ULL;
                next |= trans[c][i] & -bit;
            }

            if (!next) return false;
            cur = next;
        }

        return (cur >> accept) & 1ULL;
    }

private:
    struct Edge { int to; char ch; };
    std::vector<std::vector<Edge>> graph;
    std::vector<uint64_t> eps;

    static void init_cmap() {
        static bool done = false;
        if (done) return;
        done = true;

        for (int i = 0; i < 256; ++i)
            cmap[i] = 255;

        for (int c = 0; c < ALPHABET; ++c)
            cmap['a' + c] = c;
    }

    int new_state() {
        graph.emplace_back();
        return (int)graph.size() - 1;
    }

    void add_edge(int u, int v, char ch) {
        graph[u].push_back({v, ch});
    }

    void build(const std::string& p) {
        graph.reserve(p.size() * 2 + 2);

        start = new_state();
        int cur = start;

        for (size_t i = 0; i < p.size(); ++i) {
            char c = p[i];
            bool star = (i + 1 < p.size() && p[i + 1] == '*');
            if (star) ++i;

            int next = new_state();

            if (star) {
                int loop = new_state();
                add_edge(cur, next, 0);
                add_edge(cur, loop, 0);
                add_edge(loop, loop, c);
                add_edge(loop, next, 0);
            } else {
                add_edge(cur, next, c);
            }
            cur = next;
        }

        accept = cur;
        nstates = graph.size();

        compute_eps_closure();
        compile_transitions();
    }

    void compute_eps_closure() {
        eps.assign(nstates, 0);

        for (int s = 0; s < nstates; ++s) {
            uint64_t mask = 0;
            std::vector<int> stack = {s};

            while (!stack.empty()) {
                int u = stack.back();
                stack.pop_back();
                if (mask & (1ULL << u)) continue;
                mask |= 1ULL << u;

                for (auto& e : graph[u])
                    if (e.ch == 0)
                        stack.push_back(e.to);
            }
            eps[s] = mask;
        }
    }

    void compile_transitions() {
        // Fully ε-close transitions
        for (int s = 0; s < nstates; ++s) {
            uint64_t src = eps[s];

            while (src) {
                int u = __builtin_ctzll(src);
                src &= src - 1;

                for (auto& e : graph[u]) {
                    if (e.ch == 0) continue;

                    uint64_t targets = eps[e.to];

                    if (e.ch == '.') {
                        for (int c = 0; c < ALPHABET; ++c)
                            trans[c][s] |= targets;
                    } else {
                        trans[e.ch - 'a'][s] |= targets;
                    }
                }
            }
        }
    }
};

uint8_t RegexGraph::cmap[256];

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return RegexGraph(p).matches(s);
    }
};