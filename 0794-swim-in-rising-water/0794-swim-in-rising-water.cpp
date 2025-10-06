class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    pq.emplace(grid[0][0], 0, 0);
    while (!pq.empty()) {
        auto [t, x, y] = pq.top(); pq.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (x == n-1 && y == n-1) return t;
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny])
                pq.emplace(max(t, grid[nx][ny]), nx, ny);
        }
    }
    return -1; // should never reach here
    }
};