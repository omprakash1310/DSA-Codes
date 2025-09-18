class Solution {
public:
    bool isValid(string word) {
    if (word.size() < 3) return false;
    bool hasVowel = false, hasConsonant = false;
    for (char c : word) {
        if (!isdigit(c) && !isalpha(c)) return false;
        char lower = tolower(c);
        if (isalpha(c)) {
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                hasVowel = true;
            else
                hasConsonant = true;
        }
    }
    return hasVowel && hasConsonant;
}

};