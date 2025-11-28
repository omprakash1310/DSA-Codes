class Solution {
public:
    int res = 0;
    vector<vector<int>> g;
    int k;

    int dfs(int u, int p, vector<int>& values) {
        long long sum = values[u];
        for (int v : g[u]) {
            if (v == p) continue;
            sum += dfs(v, u, values);
        }
        if (sum % k == 0) {
            res++;
            return 0;
        }
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        g.assign(n, {});
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, values);
        return res;
    }
};