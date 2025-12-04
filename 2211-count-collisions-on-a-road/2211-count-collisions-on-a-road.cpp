class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int collisions = 0;
        int left = 0, right = n - 1;

        // Ignore cars moving left at the start
        while (left < n && directions[left] == 'L') left++;
        // Ignore cars moving right at the end
        while (right >= 0 && directions[right] == 'R') right--;

        // Count all remaining moving cars (R or L) as collisions
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') collisions++;
        }

        return collisions;
    }
};