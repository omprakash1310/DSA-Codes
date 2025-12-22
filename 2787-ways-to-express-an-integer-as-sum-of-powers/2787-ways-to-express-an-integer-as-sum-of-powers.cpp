class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; i++) powers.push_back(pow(i, x));
        vector<vector<int>> dp(powers.size(), vector<int>(n + 1, -1));
        return helper(powers, 0, n, dp);
    }

    int helper(vector<int>& p, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (i == p.size() || target < 0) return 0;
        if (dp[i][target] != -1) return dp[i][target];
        long long take = helper(p, i + 1, target - p[i], dp);
        long long skip = helper(p, i + 1, target, dp);
        return dp[i][target] = (take + skip) % mod;
    }
};