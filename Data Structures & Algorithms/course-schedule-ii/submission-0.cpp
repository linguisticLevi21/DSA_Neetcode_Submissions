class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> vis(n, false);
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        vector<int> ans;
        for (auto& e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (int i : adj[x]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (ans.size() != n) {
            return {};
        }
        return ans;
    }
};