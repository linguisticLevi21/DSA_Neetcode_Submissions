class Solution {
public:
bool dfs(int i , int parent , vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[i] = true;
    for(auto &u : adj[i])
    {
        if(!vis[u])
        {
            if(dfs(u,i,vis,adj)) return true;
        }
        else if(parent != u) return true;
    }
    return false;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        int cnt = 0;
        bool flag = false;
        vector<bool> vis(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                cnt++;
                if(dfs(i,-1,vis,adj)){
                //flag = true;
                return false;
                }
            }
        }
        return cnt==1;
    }
};
