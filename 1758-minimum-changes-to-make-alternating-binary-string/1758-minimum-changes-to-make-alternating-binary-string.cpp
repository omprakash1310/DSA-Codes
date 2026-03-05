class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0, count2 = 0;
        
        // Pattern 1: starting with '0' -> "010101..."
        for (int i = 0; i < n; i++) {
            if (s[i] != (i % 2 == 0 ? '0' : '1')) count1++;
        }
        
        // Pattern 2: starting with '1' -> "101010..."
        for (int i = 0; i < n; i++) {
            if (s[i] != (i % 2 == 0 ? '1' : '0')) count2++;
        }
        
        return min(count1, count2);
    }
};