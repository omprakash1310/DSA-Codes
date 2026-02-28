class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 0;
        int mod = 1e9 + 7;
        int length = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) length++; // new bit length when i is power of 2
            res = ((res << length) % mod + i) % mod;
        }
        return res;
    }
};