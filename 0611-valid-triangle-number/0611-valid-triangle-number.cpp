class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort so we can use two pointers
    int n = nums.size(), count = 0;
    for (int k = n - 1; k >= 2; --k) { // k is the largest side
        int i = 0, j = k - 1;
        while (i < j) {
            // If smallest two sum > largest, all pairs between i and j work
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);
                --j;
            } else {
                ++i;
            }
        }
    }
    return count;
}
};