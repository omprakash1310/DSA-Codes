class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponent
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1;
        while (N) {
            if (N % 2) res *= x;    // If odd, multiply result by x
            x *= x;                 // Square x
            N /= 2;                 // Divide exponent by 2
        }
        return res;
    }
};