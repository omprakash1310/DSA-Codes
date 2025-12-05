class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0, left = 0;
        int count = 0;
        for (int x : nums) total += x;
        for (int i = 0; i < nums.size() - 1; i++) {
            left += nums[i];
            long long right = total - left;
            if ((left - right) % 2 == 0) count++;
        }
        return count;
    }
};