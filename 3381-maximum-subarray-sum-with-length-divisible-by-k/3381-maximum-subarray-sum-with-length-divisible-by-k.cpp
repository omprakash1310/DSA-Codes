class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> minPrefix(k, LLONG_MAX);
        long long res = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;
            if (minPrefix[mod] != LLONG_MAX)
                res = max(res, prefix[i] - minPrefix[mod]);
            minPrefix[mod] = min(minPrefix[mod], prefix[i]);
        }
        return res;
    }
};