class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // Optimal App
        int mini=prices[0];
        int maxPro= 0;
        int n =prices.size();
        for(int i=0; i<n; i++){
            int diff= prices[i] - mini;
            maxPro= max(maxPro, diff);
            mini = min(mini, prices[i]);
        }
        return maxPro;
    }
};