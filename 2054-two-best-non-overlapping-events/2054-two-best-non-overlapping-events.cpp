class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> endTimes, maxVal(n);
        endTimes.reserve(n);
        
        maxVal[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i)
            maxVal[i] = max(events[i][2], maxVal[i + 1]);
        
        for (auto& e : events)
            endTimes.push_back(e[0]);
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int end = events[i][1];
            int val = events[i][2];
            int j = upper_bound(events.begin(), events.end(), vector<int>{end, INT_MAX, INT_MAX}) - events.begin();
            if (j < n) val += maxVal[j];
            res = max(res, val);
        }
        return res;
    }
};