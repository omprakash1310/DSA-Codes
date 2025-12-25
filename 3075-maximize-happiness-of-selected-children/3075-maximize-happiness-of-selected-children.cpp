class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend()); // sort descending
        long long total = 0;
        for (int i = 0; i < k; i++) {
            int val = happiness[i] - i; // each turn decreases by i
            if (val > 0) total += val;
        }
        return total;
    }
};