class Solution {
public:
    int maxOr = 0, count = 0;

    void dfs(vector<int>& nums, int i, int curr) {
        if (i == nums.size()) {
            if (curr == maxOr) count++;
            return;
        }
        dfs(nums, i + 1, curr | nums[i]);
        dfs(nums, i + 1, curr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int x : nums) maxOr |= x;
        dfs(nums, 0, 0);
        return count;
    }
};