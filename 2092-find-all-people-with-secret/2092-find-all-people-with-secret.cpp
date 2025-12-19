class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> secret(n, 0);
        secret[0] = secret[firstPerson] = 1;

        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){ return a[2] < b[2]; });

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            unordered_map<int, vector<int>> g;
            unordered_set<int> people;

            while (i < meetings.size() && meetings[i][2] == t) {
                int x = meetings[i][0], y = meetings[i][1];
                g[x].push_back(y);
                g[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            for (int p : people) if (secret[p]) q.push(p);

            unordered_set<int> visited;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                if (visited.count(cur)) continue;
                visited.insert(cur);
                secret[cur] = 1;
                for (int nei : g[cur]) if (!visited.count(nei)) q.push(nei);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) if (secret[i]) res.push_back(i);
        return res;
    }
};