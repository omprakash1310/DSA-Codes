class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         // Max heap: each entry stores gain, pass, total
    auto gain = [](int pass, int total) {
        double before = (double)pass / total;
        double after = (double)(pass + 1) / (total + 1);
        return after - before;
    };
    priority_queue<pair<double, pair<int, int>>> pq;
    for (auto& c : classes)
        pq.push({gain(c[0], c[1]), {c[0], c[1]}});
    while (extraStudents--) {
        auto cur = pq.top(); pq.pop();
        int pass = cur.second.first + 1;
        int total = cur.second.second + 1;
        pq.push({gain(pass, total), {pass, total}});
    }
    double total = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        total += (double)cur.second.first / cur.second.second;
    }
    return total / classes.size();

    }
};