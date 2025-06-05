class Solution {
public:
int minimumMoves(string s) {
    int minMoves = 0;
    string word = "";
    for (int i = 0; i < s.size(); i++) {
        word += s[i];
        if (word.find('O') != string::npos && word.size()==1) {
            word.clear();
            continue;
        }
        else if (word.size() == 3) {
            if (word.find('X') != string::npos) {
                minMoves++;
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        if (word.find('X') != string::npos) {
            minMoves++;
        }
    }
    return minMoves;
}
};