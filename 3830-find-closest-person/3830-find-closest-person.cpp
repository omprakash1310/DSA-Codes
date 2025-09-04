class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(x - z); // Distance from Person 1 to Person 3
        int d2 = abs(y - z); // Distance from Person 2 to Person 3
        if (d1 < d2) return 1; // Person 1 arrives first
        if (d2 < d1) return 2; // Person 2 arrives first
        return 0; // Both arrive at the same time
    }
};