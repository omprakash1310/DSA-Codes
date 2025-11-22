class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int n : nums) {
            int r = n % 3;
            if (r == 1 || r == 2) ops += 1;
        }
        return ops;
    }
};