class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++) pos[nums[i]].push_back(i);

        int ans = INT_MAX;
        for (auto& [num, v] : pos) {
            if (v.size() < 3) continue;
            for (int i = 0; i + 2 < v.size(); i++) {
                int d = abs(v[i] - v[i+1]) + abs(v[i+1] - v[i+2]) + abs(v[i] - v[i+2]);
                ans = min(ans, d);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};