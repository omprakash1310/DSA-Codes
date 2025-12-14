class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long res = 1;
        int seatCount = 0, plantCount = 0;
        bool inSection = false;

        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                if (seatCount == 2) inSection = true;
                else if (seatCount == 3) {
                    res = (res * (plantCount + 1)) % MOD;
                    seatCount = 1;
                    plantCount = 0;
                    inSection = false;
                }
            } else if (c == 'P' && inSection) {
                plantCount++;
            }
        }

        return seatCount == 2 ? res : 0;
    }
};