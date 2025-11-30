class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for (int n : nums) total = (total + n) % p;
        if (total == 0) return 0;

        unordered_map<int, int> prefix;
        prefix[0] = -1;
        long cur = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - total + p) % p;
            if (prefix.count(target))
                res = min(res, i - prefix[target]);
            prefix[cur] = i;
        }
        return res == nums.size() ? -1 : res;
    }
};