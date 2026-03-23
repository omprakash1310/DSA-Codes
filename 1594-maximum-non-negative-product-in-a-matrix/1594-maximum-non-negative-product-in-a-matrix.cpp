class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxP(m, vector<long long>(n)), minP(m, vector<long long>(n));
        maxP[0][0] = minP[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) maxP[i][0] = minP[i][0] = maxP[i-1][0] * grid[i][0];
        for (int j = 1; j < n; j++) maxP[0][j] = minP[0][j] = maxP[0][j-1] * grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long a = max(maxP[i-1][j], maxP[i][j-1]);
                long long b = min(minP[i-1][j], minP[i][j-1]);
                if (grid[i][j] >= 0) {
                    maxP[i][j] = a * grid[i][j];
                    minP[i][j] = b * grid[i][j];
                } else {
                    maxP[i][j] = b * grid[i][j];
                    minP[i][j] = a * grid[i][j];
                }
            }
        }
        long long res = maxP[m-1][n-1];
        if (res < 0) return -1;
        return res % 1000000007;
    }
};