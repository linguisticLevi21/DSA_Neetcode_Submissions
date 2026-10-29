class Solution {
public:
    typedef pair<int, int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n + 1);

        for (auto& i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> res(n + 1, INT_MAX);
        res[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (res[node] < dist)
                continue;

            for (auto& i : adj[node]) {
                auto u = i.first;
                auto wt = i.second;

                if (wt + dist < res[u]) {
                    res[u] = wt + dist;
                    pq.push({dist + wt, u});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (res[i] == INT_MAX)
                return -1;
            ans = max(ans, res[i]);
        }

        return ans;
    }
};