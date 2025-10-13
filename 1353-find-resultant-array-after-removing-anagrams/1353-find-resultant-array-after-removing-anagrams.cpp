class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prev = "";
        for (auto& w : words) {
            string sorted = w;
            sort(sorted.begin(), sorted.end());
            if (sorted != prev) {
                res.push_back(w);
                prev = sorted;
            }
        }
        return res;
    }
};