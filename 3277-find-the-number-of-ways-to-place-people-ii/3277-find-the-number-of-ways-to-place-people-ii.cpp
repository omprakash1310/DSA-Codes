#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        // Sort by x ascending, then by y descending.
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            // Initialize max_y for the current point p_i.
            // Any valid partner p_j must have a y-coordinate greater than this.
            int max_y = -2e9; // Use a very small number

            for (int j = i + 1; j < n; ++j) {
                // p_i is the upper-left point, p_j is the bottom-right.
                // We need p_j.y <= p_i.y.
                // Sorting already guarantees p_j.x >= p_i.x.
                if (points[j][1] <= points[i][1]) {
                    // Check if p_j is "visible" from p_i.
                    // It is visible if its y-coordinate is higher than any other valid
                    // point we've found so far for this p_i.
                    if (points[j][1] > max_y) {
                        count++;
                        // This point now sets the new maximum y for future points to beat.
                        max_y = points[j][1];
                    }
                }
            }
        }
        return count;
    }
};