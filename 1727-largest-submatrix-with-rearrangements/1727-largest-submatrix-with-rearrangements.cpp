class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];

        int res = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> row = matrix[i];
            sort(row.rbegin(), row.rend());
            for (int j = 0; j < n; ++j)
                res = max(res, row[j] * (j + 1));
        }
        return res;
    }
};