class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> uniqueChars(s.begin(), s.end());
        int count = 0;

        for (char c : uniqueChars) {
            int first = s.find(c);
            int last = s.rfind(c);
            if (last - first >= 2) {
                unordered_set<char> middle;
                for (int i = first + 1; i < last; ++i)
                    middle.insert(s[i]);
                count += middle.size();
            }
        }
        return count;
    }
};