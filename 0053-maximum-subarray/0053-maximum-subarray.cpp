class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        // Most Optimal Approach
        int maxi = arr[0];
        int sum=0;

         for (int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        maxi= max(maxi, sum);

       
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
    }
};