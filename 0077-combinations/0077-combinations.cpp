class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int n, int k, int start, vector<int>& curr) {
        if (curr.size() == k) {
            res.push_back(curr); // Found a valid combination
            return;
        }
        for (int i = start; i <= n; ++i) {
            curr.push_back(i); // Choose i
            backtrack(n, k, i + 1, curr); // Recurse
            curr.pop_back(); // Undo choice
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return res;
    }
};