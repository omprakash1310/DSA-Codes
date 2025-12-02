class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> yCount;
        for (auto &p : points) yCount[p[1]]++;
        vector<long long> pairs;
        for (auto &[y, c] : yCount)
            if (c >= 2) pairs.push_back(1LL * c * (c - 1) / 2);
        long long res = 0, prefix = 0;
        for (auto p : pairs) {
            res = (res + prefix * p) % MOD;
            prefix = (prefix + p) % MOD;
        }
        return res;
    }
};