class Solution {
public:
    bool dfs(int i, vector<int>& state,
             vector<vector<int>>& adj) {

        state[i] = 1;

        for (auto& u : adj[i]) {
            if (state[u] == 1)
                return true;

            if (state[u] == 0) {
                if (dfs(u, state, adj))
                    return true;
            }
        }

        state[i] = 2;
        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, state, adj))
                    return false;
            }
        }

        return true;
    }
};