class Solution {
public:
int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    unordered_set<int> needTeach;
    unordered_map<int, unordered_set<int>> userLang;
    for (int i = 0; i < languages.size(); ++i)
        userLang[i + 1] = unordered_set<int>(languages[i].begin(), languages[i].end());

    // Find friends who can't communicate
    for (auto& f : friendships) {
        int u = f[0], v = f[1];
        bool can = false;
        for (int lang : userLang[u])
            if (userLang[v].count(lang)) { can = true; break; }
        if (!can) {
            needTeach.insert(u);
            needTeach.insert(v);
        }
    }

    // Count for each language, how many of needTeach already know it
    vector<int> langKnown(n + 1, 0);
    for (int user : needTeach)
        for (int lang : userLang[user])
            langKnown[lang]++;
    int maxKnown = 0;
    for (int i = 1; i <= n; ++i)
        maxKnown = max(maxKnown, langKnown[i]);
    return needTeach.size() - maxKnown;
}
};