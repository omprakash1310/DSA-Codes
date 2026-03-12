struct DSU {
    int n, comp;
    vector<int> p;
    DSU(int n): n(n), comp(n), p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        p[b] = a;
        --comp;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<array<int,4>> must, opt;
        for (auto &e: edges) {
            if (e[3] == 1) must.push_back({e[0], e[1], e[2], e[3]});
            else opt.push_back({e[0], e[1], e[2], e[3]});
        }
        sort(opt.begin(), opt.end(), [](auto &a, auto &b){ return a[2] > b[2]; });

        DSU base(n);
        int hi = INT_MAX;
        for (auto &e: must) {
            if (!base.unite(e[0], e[1])) return -1;
            hi = min(hi, e[2]);
        }
        if (hi == INT_MAX && !opt.empty()) hi = opt[0][2] * 2;
        if (hi == INT_MAX) return -1;

        auto can = [&](int x) {
            DSU dsu = base;
            int used = 0;
            for (auto &e: opt) {
                if (dsu.comp == 1) break;
                int u = e[0], v = e[1], s = e[2];
                if (s >= x || (s * 2 >= x && used < k)) {
                    if (dsu.unite(u, v)) {
                        if (s < x) ++used;
                    }
                }
            }
            return dsu.comp == 1;
        };

        int lo = 0, ans = -1;
        if (!can(lo)) return -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};