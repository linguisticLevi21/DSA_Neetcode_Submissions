class Solution {
public:
void bfs(int i, vector<bool> &vis, vector<vector<int>>& adj)
{
    vis[i] = true;

    for(auto &u : adj[i])
    {
        if(!vis[u])
        {
            bfs(u,vis,adj);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges)
        {
            int a = e[0];
            int b = e[1];

            adj[b].push_back(a);
            adj[a].push_back(b);
        }
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
           if(!vis[i])
           {
            cnt++;
            bfs(i,vis,adj);
           }
        }
        return cnt;
    }
};
