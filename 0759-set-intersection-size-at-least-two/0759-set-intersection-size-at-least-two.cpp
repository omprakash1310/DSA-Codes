class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1, res = 0;
        for (auto &it : intervals) {
            int start = it[0], end = it[1];
            bool aIn = (a >= start);
            bool bIn = (b >= start);
            if (aIn && bIn) continue;
            if (bIn) {
                a = b;
                b = end;
                res++;
            } else {
                a = end - 1;
                b = end;
                res += 2;
            }
        }
        return res;
    }
};