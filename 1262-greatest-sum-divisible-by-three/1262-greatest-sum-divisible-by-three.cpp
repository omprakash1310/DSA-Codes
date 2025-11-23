class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int num : nums) {
            vector<int> temp(dp);
            for (int i : dp) {
                temp[(i + num) % 3] = max(temp[(i + num) % 3], i + num);
            }
            dp = temp;
        }
        return dp[0];
    }
};