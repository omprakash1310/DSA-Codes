class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
    // Sort the array to easily check the triangle condition
    sort(nums.begin(), nums.end());
    // Check from the largest triplet downwards
    for(int i = nums.size() - 1; i >= 2; --i) {
        // If the sum of the two smaller sides is greater than the largest, it's a valid triangle
        if(nums[i-1] + nums[i-2] > nums[i]) {
            return nums[i] + nums[i-1] + nums[i-2];
        }
    }
    // If no valid triangle is found, return 0
    return 0;
}
};