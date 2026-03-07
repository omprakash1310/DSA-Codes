class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s; // simulate rotation
        string alt1, alt2;
        for (int i = 0; i < s.size(); i++) {
            alt1 += (i % 2 ? '0' : '1');
            alt2 += (i % 2 ? '1' : '0');
        }

        int res = INT_MAX, diff1 = 0, diff2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != alt1[i]) diff1++;
            if (s[i] != alt2[i]) diff2++;
            if (i >= n) {
                if (s[i - n] != alt1[i - n]) diff1--;
                if (s[i - n] != alt2[i - n]) diff2--;
            }
            if (i >= n - 1) res = min(res, min(diff1, diff2));
        }
        return res;
    }
};