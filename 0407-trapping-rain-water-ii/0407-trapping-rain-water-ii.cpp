class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto cmp = [](const vector<int>& a, const vector<int>& b) { return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        // Push all border cells into the heap and mark as visited
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int res = 0;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int h = curr[0], x = curr[1], y = curr[2];
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                res += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), nx, ny});
                visited[nx][ny] = true;
            }
        }
        return res;
    }
};