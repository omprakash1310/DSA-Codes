class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, nxt;
        for (int x : arr) {
            nxt = {x};
            for (int y : cur) nxt.insert(y | x);
            cur = nxt;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};