class FoodRatings {
    // Map food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;
    // Map cuisine -> set of { -rating, food } for fast lookup
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodInfo[food];
        cuisineFoods[cuisine].erase({-oldRating, food}); // Remove old entry
        cuisineFoods[cuisine].insert({-newRating, food}); // Insert new
        oldRating = newRating; // Update map
    }

    string highestRated(string cuisine) {
        // Return the food with highest rating (lowest -rating, lexicographically smallest)
        return cuisineFoods[cuisine].begin()->second;
    }
};