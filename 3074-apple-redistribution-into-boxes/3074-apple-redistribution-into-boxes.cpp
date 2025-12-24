class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend()); // sort descending
        int used = 0, count = 0;
        for (int c : capacity) {
            used += c;
            count++;
            if (used >= totalApples) break;
        }
        return count;
    }
};