class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long left = 0, right = sum / n;
        while (left < right) {
            long long mid = (right + left + 1) / 2;
            long long power = 0;
            for (auto b : batteries)
                power += min((long long)b, mid);
            if (power >= mid * n)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};