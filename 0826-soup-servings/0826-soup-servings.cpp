class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0; // For large n, answer approaches 1
        vector<vector<double>> memo(200, vector<double>(200, -1));
        function<double(int, int)> dp = [&](int a, int b) {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1.0;
            if (b <= 0) return 0.0;
            if (memo[a][b] >= 0) return memo[a][b];
            return memo[a][b] = 0.25 * (
                dp(a-4, b) +
                dp(a-3, b-1) +
                dp(a-2, b-2) +
                dp(a-1, b-3)
            );
        };
        n = (n + 24) / 25;
        return dp(n, n);
    }
};
