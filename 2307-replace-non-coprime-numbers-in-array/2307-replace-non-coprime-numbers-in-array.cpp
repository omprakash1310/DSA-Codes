class Solution {
public:
    // Helper function to compute GCD
    int gcd(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    // Helper function to compute LCM
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;
        for (int n : nums) {
            stk.push_back(n);
            // Keep merging as long as top two are non-coprime
            while (stk.size() > 1 && gcd(stk[stk.size()-1], stk[stk.size()-2]) > 1) {
                int a = stk.back(); stk.pop_back();
                int b = stk.back(); stk.pop_back();
                stk.push_back(lcm(a, b));
            }
        }
        return stk;
    }
};