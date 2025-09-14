class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vow;
        auto devowel = [](string w) {
            for (auto& c : w) if (strchr("aeiou", tolower(c))) c = '*';
            return w;
        };
        for (auto& w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            cap.insert({lower, cap.count(lower) ? cap[lower] : w});
            string v = devowel(lower);
            vow.insert({v, vow.count(v) ? vow[v] : w});
        }
        vector<string> res;
        for (auto& q : queries) {
            if (words.count(q)) res.push_back(q);
            else {
                string lower = q;
                transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                if (cap.count(lower)) res.push_back(cap[lower]);
                else {
                    string v = devowel(lower);
                    res.push_back(vow.count(v) ? vow[v] : "");
                }
            }
        }
        return res;
    }
};