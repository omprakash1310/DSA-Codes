class Solution {
public:
long long maximumTotalDamage(vector<int>& power) {
    map<int, long long> cnt;
    for (int x : power) cnt[x]++;
    vector<pair<int, long long>> vals;
    for (auto& [k, v] : cnt) vals.push_back({k, v * k});
    int n = vals.size();
    vector<long long> dp(n+1, 0);
    for (int i = n-1; i >= 0; --i) {
        int j = i+1;
        while (j < n && vals[j].first <= vals[i].first + 2) ++j;
        dp[i] = max(dp[i+1], vals[i].second + dp[j]);
    }
    return dp[0];
}    

};