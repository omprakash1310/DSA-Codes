class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        vector<int> inc(n, 1);

        // Compute lengths of increasing sequences
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) inc[i] = inc[i - 1] + 1;
        }

        // Check for two adjacent increasing subarrays of length k
        for (int i = k; i < n; i++) {
            if (inc[i] >= k && inc[i - k] >= k) return true;
        }

        return false;
    }
};