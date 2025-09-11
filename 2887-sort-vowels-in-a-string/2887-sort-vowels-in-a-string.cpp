class Solution {
public:
    string sortVowels(string s) {
        // Store positions and values of vowels
        vector<int> pos;
        vector<char> vowels;
        unordered_set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
        for (int i = 0; i < s.size(); ++i) {
            if (vow.count(s[i])) {
                pos.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        // Sort vowels by ASCII
        sort(vowels.begin(), vowels.end());
        // Place sorted vowels back in original positions
        for (int i = 0; i < pos.size(); ++i) {
            s[pos[i]] = vowels[i];
        }
        return s;
    }
};