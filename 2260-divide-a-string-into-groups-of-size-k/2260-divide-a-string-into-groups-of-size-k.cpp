class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for (int i = 0; i < s.size(); i += k) {
            string group = s.substr(i, k); // Take up to k chars
            if (group.size() < k) group += string(k - group.size(), fill); // Pad if needed
            res.push_back(group);
        }
        return res;
    }
};
