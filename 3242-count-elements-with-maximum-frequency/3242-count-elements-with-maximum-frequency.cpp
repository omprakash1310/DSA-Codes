class Solution {
public:
   int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq; // Tracks frequency of each element
    int maxFreq = 0, total = 0;
    for (int n : nums) {
        freq[n]++;
        if (freq[n] > maxFreq) maxFreq = freq[n]; // Find max frequency
    }
    for (auto& [k, v] : freq)
        if (v == maxFreq) total += v; // Sum elements with max frequency
    return total;
}

};