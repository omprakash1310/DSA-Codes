class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while (i < n - 1) {
            if (bits[i] == 1) i += 2;  // skip two bits for 10 or 11
            else i += 1;               // skip one bit for 0
        }
        return i == n - 1;  // true if last char is one-bit
    }
};