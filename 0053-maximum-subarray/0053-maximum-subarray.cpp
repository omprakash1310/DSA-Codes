class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        // Most Optimal Approach
        int maxi = INT_MIN;
        int sum=0;

         for (int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

       
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
    }
};