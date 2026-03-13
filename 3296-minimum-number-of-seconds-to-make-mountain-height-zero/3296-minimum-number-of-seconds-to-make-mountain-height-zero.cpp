class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18, ans = right;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long total = 0;
            for (auto t : workerTimes) {
                long long l = 0, r = 1e6;
                while (l < r) {
                    long long m = (l + r + 1) / 2;
                    if ((long long)t * m * (m + 1) / 2 <= mid) l = m;
                    else r = m - 1;
                }
                total += l;
                if (total >= mountainHeight) break;
            }
            if (total >= mountainHeight) ans = mid, right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }
};